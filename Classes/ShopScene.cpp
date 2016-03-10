//
//  ShopScene.cpp
//  ClickC
//
//  Created by lanqs on 15/6/10.
//
//

#include "ShopScene.h"
#include "ui/CocosGUI.h"
#include "cocos2d.h"
USING_NS_CC;
using namespace ui;


bool ShopScene::init()
{
    if ( !LayerColor::initWithColor(Color4B(160,160,160,100)))
    {
        return false;
    }
    auto _listner = EventListenerTouchOneByOne::create();
    _listner->setSwallowTouches(true);
    _listner->onTouchBegan = CC_CALLBACK_2(ShopScene:: onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_listner, this);
    
    //加载到当前场景
    auto scene = Director::getInstance()->getRunningScene();
    scene ->addChild(this,999);
    this->setUi();
    return true;
}

void ShopScene::setUi()
{
    //开启回弹效果
    auto _scrollView  =ScrollView::create();
    _scrollView->setBounceEnabled(true);
    this->addChild(_scrollView);
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto spriteBackground = Sprite::create("shop1.jpg");
    spriteBackground->setScale(0.6);
    spriteBackground->setPosition(visibleSize/2);
    this->addChild(spriteBackground);
    
    auto btnSignOut = Button::create("signbtn.png");
    btnSignOut ->setPosition(Vec2(visibleSize.width*0.76,visibleSize.height*0.65));
    btnSignOut->setScale(0.59);
    this->addChild(btnSignOut);
    btnSignOut->addClickEventListener(CC_CALLBACK_1(ShopScene::btnSignOutCallFunc, this));
    
}
bool ShopScene:: onTouchBegan(cocos2d::Touch *touch, cocos2d::Event  *unused_envent)
{
    return true;
}
void ShopScene::btnSignOutCallFunc(cocos2d::Ref*)
{
    this->removeFromParentAndCleanup(true);
}