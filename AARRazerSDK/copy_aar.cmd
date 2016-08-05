SET JAVA_HOME=C:\NVPACK\jdk1.7.0_71

SET JAR="%JAVA_HOME%\bin\jar.exe"

COPY /Y pluginrazersdk\libs\store-sdk-standard-release.aar ..\
COPY /Y pluginrazersdk\build\outputs\aar\pluginrazersdk-release.aar ..\

CD ..\

IF EXIST classes.jar DEL classes.JAR
CALL %JAR% -xvf store-sdk-standard-release.aar classes.jar
IF EXIST store-sdk-standard-release.jar DEL store-sdk-standard-release.jar
RENAME classes.jar store-sdk-standard-release.jar

IF EXIST classes.jar DEL classes.JAR
CALL %JAR% -xvf pluginrazersdk-release.aar classes.jar
IF EXIST pluginrazersdk-release.jar DEL pluginrazersdk-release.jar
RENAME classes.jar pluginrazersdk-release.jar

REM InAppPurchases

COPY /Y store-sdk-standard-release.aar InAppPurchases\proj.android-studio\app\libs
COPY /Y store-sdk-standard-release.aar InAppPurchases\proj.visualstudio\Cocos2d\libs
COPY /Y store-sdk-standard-release.jar InAppPurchases\proj.visualstudio\Cocos2d\libs

COPY /Y pluginrazersdk-release.aar InAppPurchases\proj.android-studio\app\libs
COPY /Y pluginrazersdk-release.aar InAppPurchases\proj.visualstudio\Cocos2d\libs
COPY /Y pluginrazersdk-release.jar InAppPurchases\proj.visualstudio\Cocos2d\libs

if NOT "%NO_PAUSE%"=="true" PAUSE
