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
#include "CallbackMgr.h"
#include <chrono>
#include <iomanip>

class NotificationMgr
{
public:
	NotificationMgr(std::shared_ptr<CallbackMgr> callbackMgr) {
		m_CallbackMgr = callbackMgr;
	}
	~NotificationMgr() = default;

	/* sample mgr to generate events of state changes. this could be called
	   in multiple places in practice. callbackMgr will need to be passed in */
	void GenerateEvent(const int val, const State state) {
		m_CallbackMgr->callback(GetCurrentTime(), val, state);
	}

	/* used to get current time of when state changes */
	std::string GetCurrentTime() {
		using namespace std::literals::chrono_literals;
		auto t = std::time(nullptr);
		tm ltm;

		localtime_s(&ltm, &t);
		std::stringstream timeNow;
		timeNow << std::put_time(&ltm, "%A, %Y-%m-%d %H:%M:%S %z %Z");
		return timeNow.str();
	}

private:
	/* it's necessary to use the same shared ptr for Callback Mgr where
	   callback data is stored. */
	std::shared_ptr<CallbackMgr> m_CallbackMgr = nullptr;
};