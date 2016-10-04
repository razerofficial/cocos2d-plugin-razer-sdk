ECHO ON
COPY /Y store-sdk-standard-release.aar AARRazerSDK\pluginrazersdk\libs\
COPY /Y store-sdk-standard-release.aar InAppPurchases\proj.android-studio\app\libs
COPY /Y store-sdk-standard-release.aar InAppPurchases\proj.visualstudio\Cocos2d\libs
COPY /Y store-sdk-standard-release.jar InAppPurchases\proj.visualstudio\Cocos2d\libs
PAUSE
