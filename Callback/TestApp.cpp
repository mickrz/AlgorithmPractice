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

#include "CallbackMgr.h"
#include "NotificationMgr.h"
#include "Client.h"
#include <thread>

int main()
{
	/* Register callback of client interested whne state changes */
	std::shared_ptr<CallbackMgr> callbackMgr = std::make_shared<CallbackMgr>();
	callbackMgr->register_callback(&Client::func, State::STATE_RUNNING);
	callbackMgr->register_callback(&Client::func, State::STATE_STOPPED);
	callbackMgr->register_callback(&Client::func, std::nullopt);
	callbackMgr->register_callback(&Client::func, State::STATE_PAUSED);

	/* Pass in shared ptr for callback so NotificationMgr can trigger when state changes.
	   There will be a total of 7 notifications - 2 each for running, stopped and paused
	   and 1 for starting since the third registration was for all state changes. */
	NotificationMgr notificationMgr(callbackMgr);
	notificationMgr.GenerateEvent(1, State::STATE_RUNNING);
	std::this_thread::sleep_for(std::chrono::seconds(2));
	notificationMgr.GenerateEvent(2, State::STATE_STOPPED);
	std::this_thread::sleep_for(std::chrono::seconds(3));
	notificationMgr.GenerateEvent(3, State::STATE_STARTING);
	std::this_thread::sleep_for(std::chrono::seconds(4));
	notificationMgr.GenerateEvent(4, State::STATE_PAUSED);

	return 0;
}