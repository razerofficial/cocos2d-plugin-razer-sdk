/*
* Copyright (C) 2012-2016 Razer, Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "Main_CallbacksRequestReceipts.h"

#include "HelloWorldScene.h"

#if ANDROID

#include <android/log.h>

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "Main_CallbacksRequestReceipts"

void Main_CallbacksRequestReceipts::OnSuccess(const std::vector<RazerSDK::Receipt>& receipts)
{
	cocos2d::Director::getInstance()->getScheduler()->performFunctionInCocosThread([receipts] {
		// execute code on main thread
		HelloWorld::GetInstance()->UpdateStatusText("RequestReceipts: Success!");
		HelloWorld::GetInstance()->UpdateReceipts(receipts);
	});
}

void Main_CallbacksRequestReceipts::OnFailure(int errorCode, const std::string& errorMessage)
{
	cocos2d::Director::getInstance()->getScheduler()->performFunctionInCocosThread([errorCode, errorMessage] {
		// execute code on main thread
		HelloWorld::GetInstance()->UpdateStatusErrorText("RequestReceipts", errorCode, errorMessage);
	});
}

void Main_CallbacksRequestReceipts::OnCancel()
{
	cocos2d::Director::getInstance()->getScheduler()->performFunctionInCocosThread([] {
		// execute code on main thread
		HelloWorld::GetInstance()->UpdateStatusText("RequestReceipts: Cancelled!");
	});
}

#endif
