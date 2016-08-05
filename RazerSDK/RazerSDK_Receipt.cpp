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

// this test is Android specific
#if ANDROID

#include "RazerSDK_Receipt.h"
#include "RazerSDK_JSONObject.h"

#include <android/log.h>
#include <string>

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "RazerSDK_Receipt"

#ifdef ENABLE_VERBOSE_LOGGING
#undef ENABLE_VERBOSE_LOGGING
#endif
#define ENABLE_VERBOSE_LOGGING false

namespace RazerSDK
{
	void Receipt::Init()
	{
		Currency = "";
		GamerUuid = "";
		GeneratedDate = "";
		Identifier = "";
		LocalPrice = 0;
		PriceInCents = 0;
		PurchaseDate = "";
		Uuid = "";
	}

	void Receipt::ParseJSON(const org_json_JSONObject::JSONObject& jsonObject)
	{
		Init();

#if ENABLE_VERBOSE_LOGGING
		__android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, "jsonData=%s", jsonObject.toString().c_str());
#endif

		std::string field;

#if ENABLE_VERBOSE_LOGGING
		__android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, "Parse currency");
#endif
		field = "currency";
		if (jsonObject.has(field))
		{
			Currency = jsonObject.getString(field);
		}
		
#if ENABLE_VERBOSE_LOGGING
		__android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, "Parse gamerUuid");
#endif
		field = "gamerUuid";
		if (jsonObject.has(field))
		{
			GamerUuid = jsonObject.getString(field);
		}
		
#if ENABLE_VERBOSE_LOGGING
		__android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, "Parse generatedDate");
#endif
		field = "generatedDate";
		if (jsonObject.has(field))
		{
			GeneratedDate = jsonObject.getString(field);
		}
		
#if ENABLE_VERBOSE_LOGGING
		__android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, "Parse identifier");
#endif
		field = "identifier";
		if (jsonObject.has(field))
		{
			Identifier = jsonObject.getString(field);
		}

#if ENABLE_VERBOSE_LOGGING
		__android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, "Parse localPrice");
#endif
		field = "localPrice";
		if (jsonObject.has(field))
		{
			LocalPrice = (float)jsonObject.getDouble(field);
		}

#if ENABLE_VERBOSE_LOGGING
		__android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, "Parse priceInCents");
#endif
		field = "priceInCents";
		if (jsonObject.has(field))
		{
			PriceInCents = jsonObject.getInt(field);
		}
		
#if ENABLE_VERBOSE_LOGGING
		__android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, "Parse purchaseDate");
#endif
		field = "purchaseDate";
		if (jsonObject.has(field))
		{
			PurchaseDate = jsonObject.getString(field);
		}

#if ENABLE_VERBOSE_LOGGING
		__android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, "Parse uuid");
#endif
		field = "uuid";
		if (jsonObject.has(field))
		{
			Uuid = jsonObject.getString(field);
		}

#if ENABLE_VERBOSE_LOGGING
		__android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, "Currency: %s", Currency.c_str());
		__android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, "GamerUuid: %s", GamerUuid.c_str());
		__android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, "GeneratedDate: %s", GeneratedDate.c_str());
		__android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, "Identifier: %s", Identifier.c_str());
		__android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, "LocalPrice: %f", LocalPrice);
		__android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, "PriceInCents: %d", PriceInCents);
		__android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, "PurchaseDate: %s", PurchaseDate.c_str());
		__android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, "Uuid: %s", Uuid.c_str());
#endif
	}
}

#endif
