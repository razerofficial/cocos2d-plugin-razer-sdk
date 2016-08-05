#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

#if ANDROID
#include "RazerSDK\RazerSDK_Plugin.h"

#include <android/log.h>
#include <iostream>  

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "HelloWorldScene"
#endif

USING_NS_CC;

#define LEFT_ANCHOR 50
#define RIGHT_ANCHOR 250
#define VERT_PADDING 5
#define TEXT_PADDING 100

HelloWorld* HelloWorld::_sInstance = 0;
Main_CallbacksInitPlugin HelloWorld::_sMain_CallbacksInitPlugin = Main_CallbacksInitPlugin();
Main_CallbacksRequestGamerInfo HelloWorld::_sMain_CallbacksRequestGamerInfo = Main_CallbacksRequestGamerInfo();
Main_CallbacksRequestProducts HelloWorld::_sMain_CallbacksRequestProducts = Main_CallbacksRequestProducts();
Main_CallbacksRequestPurchase HelloWorld::_sMain_CallbacksRequestPurchase = Main_CallbacksRequestPurchase();
Main_CallbacksRequestReceipts HelloWorld::_sMain_CallbacksRequestReceipts = Main_CallbacksRequestReceipts();
Main_CallbacksShutdown HelloWorld::_sMain_CallbacksShutdown = Main_CallbacksShutdown();

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // '_sInstance' is an autorelease object
	HelloWorld::_sInstance = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(_sInstance);

    // return the scene
    return scene;
}

void HelloWorld::InitPlugin()
{
	std::string secretApiKey = "eyJkZXZlbG9wZXJfaWQiOiIzMTBhOGY1MS00ZDZlLTRhZTUtYmRhMC1iOTM4";
	secretApiKey += "NzhlNWY1ZDAiLCJkZXZlbG9wZXJfcHVibGljX2tleSI6Ik1JR2ZNQTBHQ1Nx";
	secretApiKey += "R1NJYjNEUUVCQVFVQUE0R05BRENCaVFLQmdRQ3BkZUs4SDh6NG9qb0czZUI4";
	secretApiKey += "azU4SWpWaEpJUkQ5MSt0aGQ1NjJNaXlEa09teEhLSXFMUlFId25OZW4xRHkv";
	secretApiKey += "TGxnTStzak1GaEZHL0dERUVWemRIeTRNNkkyc1l6bGR4VmNLWWFpUlhFa0ls";
	secretApiKey += "NUNyWjhtRGdLaWgzOFNueDFPY3R3UzFQM0wxcXA3LzZiM2xlejY4ZmIyalVV";
	secretApiKey += "WFpIaStaRDZROGlPbzE5V3Rhd0lEQVFBQiJ9";
	RazerSDK::Plugin::initPlugin(secretApiKey, &_sMain_CallbacksInitPlugin);
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add your codes below...

	/// app label
    
	_mLabelApp = Label::createWithTTF("Cocos2d IAP Sample App", "fonts/Marker Felt.ttf", 18);

	float y = origin.y + visibleSize.height;

    /// app label
	y -= _mLabelApp->getContentSize().height;
	_mLabelApp->setPosition(Vec2(origin.x + visibleSize.width/2, y));
    this->addChild(_mLabelApp, 1);
	y -= VERT_PADDING;

	float x = origin.x + LEFT_ANCHOR;

	/// status label
	_mLabelStatus = Label::createWithTTF("Status:", "fonts/Marker Felt.ttf", 12);
	y -= _mLabelStatus->getContentSize().height;
	_mLabelStatus->setPosition(Vec2(x, y));
	this->addChild(_mLabelStatus, 1);

	/// status text label
	x = origin.x + TEXT_PADDING;
	_mLabelStatusText = Label::createWithTTF("App Started", "fonts/Marker Felt.ttf", 12);
	_mLabelStatusText->setPosition(Vec2(x, y));
	_mLabelStatusText->setAnchorPoint(Vec2(0, 0.5f));
	this->addChild(_mLabelStatusText, 1);
	y -= VERT_PADDING;

	/// gamer info label
	x = origin.x + LEFT_ANCHOR;
	_mLabelGamerInfo = Label::createWithTTF("GamerInfo:", "fonts/Marker Felt.ttf", 12);
	y -= _mLabelGamerInfo->getContentSize().height;
	_mLabelGamerInfo->setPosition(Vec2(x, y));
	this->addChild(_mLabelGamerInfo, 1);

	/// gamer info text label
	x = origin.x + TEXT_PADDING;
	_mLabelGamerInfoText = Label::createWithTTF("Need To Request", "fonts/Marker Felt.ttf", 12);
	_mLabelGamerInfoText->setPosition(Vec2(x, y));
	_mLabelGamerInfoText->setAnchorPoint(Vec2(0, 0.5f));
	this->addChild(_mLabelGamerInfoText, 1);
	y -= VERT_PADDING;

	/// request products button
	x = origin.x + LEFT_ANCHOR + 20;
	CreateButton(_mButtonRequestProducts, "RequestProducts", x, y, 3.f, CC_CALLBACK_1(HelloWorld::requestProductsCallback, this));

	/// request receipts button
	x = origin.x + LEFT_ANCHOR + 125;
	CreateButton(_mButtonRequestReceipts, "RequestReceipts", x, y, 3.f, CC_CALLBACK_1(HelloWorld::requestReceiptsCallback, this));

	/// request gamer info button
	x = origin.x + LEFT_ANCHOR + 240;
	CreateButton(_mButtonRequestGamerInfo, "RequestGamerInfo", x, y, 3.5f, CC_CALLBACK_1(HelloWorld::requestGamerInfoCallback, this));

	/// shutdown button
	x = origin.x + LEFT_ANCHOR + 350;
	CreateButton(_mButtonShutdown, "Shutdown", x, y, 2.5f, CC_CALLBACK_1(HelloWorld::shutdownCallback, this));

	y -= _mButtonRequestProducts._mButton->getContentSize().height;

	y -= VERT_PADDING;
	y -= VERT_PADDING;
	y -= VERT_PADDING;

	/// products section

	x = origin.x + LEFT_ANCHOR;
	CreateButtonRequestProduct(x, y);

	/// receipts section

	x = origin.x + RIGHT_ANCHOR;
	CreateButtonRequestReceipts(x, y);
    
    return true;
}

HelloWorld* HelloWorld::GetInstance()
{
	return _sInstance;
}

void HelloWorld::UpdateStatusText(const std::string& text)
{
	_mLabelStatusText->setString(text);
}

void HelloWorld::UpdateStatusErrorText(const std::string& context, const int errorCode, const std::string& errorMessage)
{
	std::string text = context;
	text += ": ErrorCode=";
	text += errorCode;
	text += " Message=";
	text += errorMessage;
	_mLabelStatusText->setString(text);
}

void HelloWorld::UpdateGamerInfoText(const std::string& text)
{
	_mLabelGamerInfoText->setString(text);
}

void HelloWorld::UpdateProducts(const std::vector<RazerSDK::Product>& products)
{
	for (ButtonWithLabel buttonLabel : _mProducts)
	{
		this->removeChild(buttonLabel._mLabel);
		this->removeChild(buttonLabel._mMenu);
		this->removeChild(buttonLabel._mButton);
	}
	_mProducts.clear();

	int y = _mLabelProducts->getPosition().y;
	for (const RazerSDK::Product& product : products)
	{
		std::string text = product.Identifier;
		ButtonWithLabel buttonWithLabel = ButtonWithLabel();
		CreateButton(buttonWithLabel, text, 100, y, 4.5f, CC_CALLBACK_1(HelloWorld::requestPurchaseCallback, this));
		_mProducts.push_back(buttonWithLabel);
		y -= 35;
	}
}

void HelloWorld::UpdateReceipts(const std::vector<RazerSDK::Receipt>& receipts)
{
	for (cocos2d::Label* label : _mReceipts)
	{
		this->removeChild(label);
	}
	_mReceipts.clear();

	int x = _mLabelReceipts->getPosition().x;
	int y = _mLabelReceipts->getPosition().y - _mLabelReceipts->getContentSize().height;
	for (const RazerSDK::Receipt& receipt : receipts)
	{
		y -= 16;

		std::ostringstream stream;
		stream << receipt.Identifier;
		stream << " " << receipt.LocalPrice;
		std::string text = stream.str();

		Label* label = Label::createWithTTF(text, "fonts/Marker Felt.ttf", 12);
		label->setPosition(Vec2(x, y));
		label->setAnchorPoint(Vec2(0, 0.5f));
		this->addChild(label, 1);

		_mReceipts.push_back(label);
	}
}

void HelloWorld::CreateButton(ButtonWithLabel& buttonWithLabel, const std::string& text, int x, int y, float hScale, const cocos2d::ccMenuCallback& callback)
{
	buttonWithLabel._mButton = MenuItemImage::create(
		"ButtonInactive.png",
		"ButtonActive.png",
		callback);

	buttonWithLabel._mButton->setPosition(Vec2(x, y - buttonWithLabel._mButton->getContentSize().height));
	buttonWithLabel._mButton->setScaleX(hScale);

	this->addChild(buttonWithLabel._mButton, 1);

	buttonWithLabel._mMenu = Menu::create(buttonWithLabel._mButton, NULL);
	buttonWithLabel._mMenu->setPosition(Vec2::ZERO);
	this->addChild(buttonWithLabel._mMenu, 1);

	buttonWithLabel._mLabel = Label::createWithTTF(text, "fonts/Marker Felt.ttf", 12);
	buttonWithLabel._mLabel->setPosition(Vec2(x, y - buttonWithLabel._mButton->getContentSize().height));
	this->addChild(buttonWithLabel._mLabel, 1);
}

void HelloWorld::CreateButtonRequestProduct(int x, int y)
{
	/// products label
	_mLabelProducts = Label::createWithTTF("Products:", "fonts/Marker Felt.ttf", 12);
	y -= _mLabelProducts->getContentSize().height;
	_mLabelProducts->setPosition(Vec2(x, y));
	this->addChild(_mLabelProducts, 1);
	y -= VERT_PADDING;
}

void HelloWorld::CreateButtonRequestReceipts(int x, int y)
{
	/// products label
	_mLabelReceipts = Label::createWithTTF("Receipts:", "fonts/Marker Felt.ttf", 12);
	y -= _mLabelReceipts->getContentSize().height;
	_mLabelReceipts->setPosition(Vec2(x, y));
	this->addChild(_mLabelReceipts, 1);
	y -= VERT_PADDING;
}

void HelloWorld::requestProductsCallback(Ref* pSender)
{
	std::vector<std::string> products;
	products.push_back("long_sword");
	products.push_back("sharp_axe");
	products.push_back("__DECLINED__THIS_PURCHASE");
	RazerSDK::Plugin::requestProducts(products, &_sMain_CallbacksRequestProducts);
}

void HelloWorld::requestPurchaseCallback(Ref* pSender)
{
	MenuItemImage* button = dynamic_cast<cocos2d::MenuItemImage*>(pSender);
	for (ButtonWithLabel buttonLabel : _mProducts)
	{
		if (button == buttonLabel._mButton)
		{
			std::string identifier = buttonLabel._mLabel->getString();
			std::string text = "requestPurchase: ";
			text += identifier;
			__android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, text.c_str());
			HelloWorld::GetInstance()->UpdateStatusText(text);
			std::string productType = "ENTITLEMENT";
			RazerSDK::Plugin::requestPurchase(identifier, productType, &_sMain_CallbacksRequestPurchase);
			break;
		}
	}
}

void HelloWorld::requestReceiptsCallback(Ref* pSender)
{
	RazerSDK::Plugin::requestReceipts(&_sMain_CallbacksRequestReceipts);
}

void HelloWorld::requestGamerInfoCallback(Ref* pSender)
{
	RazerSDK::Plugin::requestGamerInfo(&_sMain_CallbacksRequestGamerInfo);
}

void HelloWorld::shutdownCallback(Ref* pSender)
{
	RazerSDK::Plugin::shutdown(&_sMain_CallbacksShutdown);
}

void HelloWorld::Shutdown()
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application, do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);
}
