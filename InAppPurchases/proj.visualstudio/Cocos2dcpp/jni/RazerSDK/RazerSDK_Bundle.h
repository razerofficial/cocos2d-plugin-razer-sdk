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

#pragma once

// this code is Android specific
#if ANDROID

#include <jni.h>

namespace android_os_Bundle
{
	class Bundle
	{
	public:
		static int InitJNI();
		static int FindJNI();
		Bundle(jobject instance);
		jobject GetInstance() const;
		void Dispose() const;
	private:
		static jclass _jcBundle;
		jobject _instance;
	};
}

#endif
