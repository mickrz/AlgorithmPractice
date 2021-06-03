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

#include "Client.h"

/* required to be declared in source file so memory is allocated.
   it's a static */
std::mutex Client::m_FuncLock;

std::string Client::TranslateState(const State state) {
	if (state == STATE_STARTING) { return "STARTING"; }
	else if (state == STATE_STARTED) { return "STARTED"; }
	else if (state == STATE_RUNNING) { return "RUNNING"; }
	else if (state == STATE_PAUSED) { return "PAUSED"; }
	else if (state == STATE_STOPPED) { return "STOPPED"; }
	else if (state == STATE_ERROR) { return "ERROR"; }
	else { return "UNKNOWN"; }
}

void Client::func(std::string timestamp, uint32_t val, std::optional<State> state) {
	std::unique_lock<std::mutex> guard(m_FuncLock);
	std::stringstream ss;
	ss << "Client callback triggered: " << timestamp
		<< ", value = " << std::to_string(val);

	if (state.has_value()) {
		ss << ", state = " << TranslateState(state.value());
	}

	std::cout << ss.str() << std::endl;
}