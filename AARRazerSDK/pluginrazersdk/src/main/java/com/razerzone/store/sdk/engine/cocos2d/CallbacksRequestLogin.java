/*
 * Copyright (C) 2012-2015 OUYA, Inc.
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

package com.razerzone.store.sdk.engine.cocos2d;


import android.util.Log;


public class CallbacksRequestLogin {

	private final String TAG  = CallbacksRequestLogin.class.getSimpleName();

	private static final boolean sEnableLogging = false;

	public native void CallbacksRequestLoginOnSuccess();
	public native void CallbacksRequestLoginOnFailure(int errorCode, String errorMessage);
	public native void CallbacksRequestLoginOnCancel();

	public void onSuccess() {
		if (sEnableLogging) {
			Log.d(TAG, "onSuccess:");
		}
		CallbacksRequestLoginOnSuccess();
	}

	public void onFailure(final int errorCode, final String errorMessage) {
		if (sEnableLogging) {
			Log.d(TAG, "onFailure: errorCode=" + errorCode + " errorMessage=" + errorMessage);
		}
		if (null == errorMessage) {
			CallbacksRequestLoginOnFailure(errorCode, "");
		} else {
			CallbacksRequestLoginOnFailure(errorCode, errorMessage);
		}
	}

	public void onCancel() {
		if (sEnableLogging) {
			Log.d(TAG, "onCancel");
		}
		CallbacksRequestLoginOnCancel();
	}
}
