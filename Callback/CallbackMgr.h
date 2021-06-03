/*
MIT License
Copyright (c) 2021 Mike Rzucidlo
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once
#include <functional>
#include <vector>
#include <optional>
#include "Common.h"

/* function to implement by clients to pass in when registering and to call when state changes */
using CallbackFunction = std::function<void(std::string timestamp, uint32_t val, std::optional<State> state)>;

/* stores function and optional state */
struct CallbackData {
	CallbackFunction cb;
	std::optional<State> state;
};

class CallbackMgr {
public:
	CallbackMgr() = default;
	~CallbackMgr() { m_Callbacks.clear(); };

	/* register callback with option of filtering on specific state or receive all state changes */
	void register_callback(const CallbackFunction& cb, const std::optional<State> state) {
			CallbackData cb_data = { std::move(cb), std::move(state) };
			m_Callbacks.emplace_back(std::move(cb_data));
	}

	/* callback with specific state or send all state changes */
	void callback(const std::string timestamp, const uint32_t val, const State state) const {
		for (const auto& cb : m_Callbacks) {
			if (cb.state == state || !cb.state.has_value()) {
				cb.cb(timestamp, val, state);
			}
		}
	}

private:
	/* list of all registered callbacks */
	std::vector<CallbackData> m_Callbacks;
};