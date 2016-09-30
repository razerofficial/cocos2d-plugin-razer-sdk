LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos)

LOCAL_MODULE := MyGame_shared

LOCAL_MODULE_FILENAME := libMyGame

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../../Classes/AppDelegate.cpp \
                   ../../../Classes/HelloWorldScene.cpp \
				   ../../../Classes/Main_CallbacksInitPlugin.cpp \
				   ../../../Classes/Main_CallbacksRequestLogin.cpp \
				   ../../../Classes/Main_CallbacksRequestGamerInfo.cpp \
				   ../../../Classes/Main_CallbacksRequestProducts.cpp \
				   ../../../Classes/Main_CallbacksRequestPurchase.cpp \
				   ../../../Classes/Main_CallbacksRequestReceipts.cpp \
				   ../../../Classes/Main_CallbacksShutdown.cpp \
				   RazerSDK/RazerSDK_Bitmap.cpp \
                   RazerSDK/RazerSDK_BitmapConfig.cpp \
                   RazerSDK/RazerSDK_Bundle.cpp \
                   RazerSDK/RazerSDK_CallbacksContentDelete.cpp \
                   RazerSDK/RazerSDK_CallbacksContentDownload.cpp \
                   RazerSDK/RazerSDK_CallbacksContentInit.cpp \
                   RazerSDK/RazerSDK_CallbacksContentPublish.cpp \
                   RazerSDK/RazerSDK_CallbacksContentSave.cpp \
                   RazerSDK/RazerSDK_CallbacksContentSearchInstalled.cpp \
                   RazerSDK/RazerSDK_CallbacksContentSearchPublished.cpp \
                   RazerSDK/RazerSDK_CallbacksContentUnpublish.cpp \
                   RazerSDK/RazerSDK_CallbackSingleton.cpp \
                   RazerSDK/RazerSDK_CallbacksInitPlugin.cpp \
                   RazerSDK/RazerSDK_CallbacksRequestLogin.cpp \
                   RazerSDK/RazerSDK_CallbacksRequestGamerInfo.cpp \
                   RazerSDK/RazerSDK_CallbacksRequestProducts.cpp \
                   RazerSDK/RazerSDK_CallbacksRequestPurchase.cpp \
                   RazerSDK/RazerSDK_CallbacksRequestReceipts.cpp \
                   RazerSDK/RazerSDK_CallbacksShutdown.cpp \
                   RazerSDK/RazerSDK_Color.cpp \
                   RazerSDK/RazerSDK_Controller.cpp \
                   RazerSDK/RazerSDK_GameMod.cpp \
                   RazerSDK/RazerSDK_GameModEditor.cpp \
                   RazerSDK/RazerSDK_GameModManager.cpp \
                   RazerSDK/RazerSDK_GameModScreenshot.cpp \
                   RazerSDK/RazerSDK_GamerInfo.cpp \
                   RazerSDK/RazerSDK_InputStream.cpp \
                   RazerSDK/RazerSDK_InputView.cpp \
                   RazerSDK/RazerSDK_JSONArray.cpp \
                   RazerSDK/RazerSDK_JSONObject.cpp \
                   RazerSDK/RazerSDK_OutputStream.cpp \
                   RazerSDK/RazerSDK_Plugin.cpp \
                   RazerSDK/RazerSDK_Product.cpp \
                   RazerSDK/RazerSDK_PurchaseResult.cpp \
                   RazerSDK/RazerSDK_Receipt.cpp \
                   RazerSDK/RazerSDK_String.cpp
				   
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../Classes
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../cocos2d/cocos/platform/android/jni

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static
LOCAL_STATIC_LIBRARIES += android_native_app_glue
LOCAL_STATIC_LIBRARIES += ndk_helper

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)
$(call import-module,android/native_app_glue)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
