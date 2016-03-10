//
//  SureSignOutScene.cpp
//  ClickC
//
//  Created by lanqs on 15/6/16.
//
//

#include "SureSignOutScene.h"
#include "ui/CocosGUI.h"
#include "Function.h"
#include "HomeScene.h"
using namespace ui;
USING_NS_CC;
bool SureSignOutScene::init()
{
    if ( !LayerColor::initWithColor(Color4B(160,160,160,100)))
    {
        return false;
    }
    auto _listner = EventListenerTouchOneByOne::create();
    _listner->setSwallowTouches(true);
    _listner->onTouchBegan = CC_CALLBACK_2(SureSignOutScene:: onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_listner, this);
    
    //加载到当前场景
    auto scene = Director::getInstance()->getRunningScene();
    scene ->addChild(this,999);
    this->setUi();
    return true;
}

void SureSignOutScene::setUi()
{
    //开启回弹效果
    auto _scrollView  =ScrollView::create();
    _scrollView->setBounceEnabled(true);
    this->addChild(_scrollView);
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto spriteBackground = Sprite::create("suresignout.png");
    spriteBackground->setScale(0.6);
    spriteBackground->setPosition(visibleSize.width/2,visibleSize.height*0.495);
    this->addChild(spriteBackground);
    
    auto btnSignOut = Button::create("SUREBTN.png");
    btnSignOut->setPosition(Vec2(visibleSize.width*0.355,visibleSize.height*0.399));
    btnSignOut->setScale(0.6);
    this->addChild(btnSignOut);
    btnSignOut->addClickEventListener(CC_CALLBACK_1(SureSignOutScene::btnSignOutCallback, this));
    
    auto btnSignOutNo = Button::create("SUREBTN1.png");
    btnSignOutNo->setPosition(Vec2(visibleSize.width*0.646,visibleSize.height*0.399));
    btnSignOutNo->setScale(0.6);
    this->addChild(btnSignOutNo);
    btnSignOutNo->addClickEventListener(CC_CALLBACK_1(SureSignOutScene::btnContinueCallback, this));
}

void SureSignOutScene::btnSignOutCallback(Ref *target)
{
    this->removeFromParentAndCleanup(true);
    auto scene = HomeScene::createScene();
    Director::getInstance()->pushScene(scene);
}

void SureSignOutScene::btnContinueCallback(Ref *target)
{
    this->removeFromParentAndCleanup(true);
}
bool SureSignOutScene:: onTouchBegan(cocos2d::Touch *touch, cocos2d::Event  *unused_envent)
{
    return true;
}