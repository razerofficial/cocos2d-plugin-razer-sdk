#pragma once

#include "cocos2d.h"

#if ANDROID
#include "Main_CallbacksInitPlugin.h"
#include "Main_CallbacksRequestGamerInfo.h"
#include "Main_CallbacksRequestProducts.h"
#include "Main_CallbacksRequestPurchase.h"
#include "Main_CallbacksRequestReceipts.h"
#include "Main_CallbacksShutdown.h"
#endif

struct ButtonWithLabel
{
public:
	cocos2d::MenuItemImage* _mButton;
	cocos2d::Label* _mLabel;
	cocos2d::Menu* _mMenu;
};

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	void requestProductsCallback(cocos2d::Ref* pSender);

	void requestPurchaseCallback(cocos2d::Ref* pSender);

	void requestReceiptsCallback(cocos2d::Ref* pSender);
    
	void requestGamerInfoCallback(cocos2d::Ref* pSender);

    void shutdownCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	static HelloWorld* GetInstance();

	void UpdateStatusText(const std::string& text);

	void UpdateStatusErrorText(const std::string& context, const int errorCode, const std::string& errorMessage);

	void UpdateGamerInfoText(const std::string& text);

#if ANDROID

	void InitPlugin();

	void Shutdown();

	void UpdateProducts(const std::vector<RazerSDK::Product>& products);

	void UpdateReceipts(const std::vector<RazerSDK::Receipt>& receipts);

#endif

private:

	void CreateButtonRequestProduct(int x, int y);
	void CreateButtonRequestReceipts(int x, int y);

	void CreateButton(ButtonWithLabel& buttonWithLabel, const std::string& text, int x, int y, float hScale, const cocos2d::ccMenuCallback& callback);

	static HelloWorld* _sInstance;

	cocos2d::Label* _mLabelApp;
	cocos2d::Label* _mLabelStatus;
	cocos2d::Label* _mLabelStatusText;
	cocos2d::Label* _mLabelGamerInfo;
	cocos2d::Label* _mLabelGamerInfoText;
	cocos2d::Label* _mLabelProducts;
	cocos2d::Label* _mLabelReceipts;

	ButtonWithLabel _mButtonRequestProducts;
	ButtonWithLabel _mButtonRequestReceipts;
	ButtonWithLabel _mButtonRequestGamerInfo;
	ButtonWithLabel _mButtonShutdown;

	std::vector<ButtonWithLabel> _mProducts;
	std::vector<cocos2d::Label*> _mReceipts;

#if ANDROID
	static Main_CallbacksInitPlugin _sMain_CallbacksInitPlugin;
	static Main_CallbacksRequestGamerInfo _sMain_CallbacksRequestGamerInfo;
	static Main_CallbacksRequestProducts _sMain_CallbacksRequestProducts;
	static Main_CallbacksRequestPurchase _sMain_CallbacksRequestPurchase;
	static Main_CallbacksRequestReceipts _sMain_CallbacksRequestReceipts;
	static Main_CallbacksShutdown _sMain_CallbacksShutdown;
#endif

};
