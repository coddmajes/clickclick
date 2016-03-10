//
//  PauseScene.cpp
//  ClickC
//
//  Created by lanqs on 15/6/16.
//
//

#include "PauseScene.h"
#include "ui/CocosGUI.h"
#include "Function.h"
using namespace ui;
USING_NS_CC;
bool PauseScene::init()
{
    if ( !LayerColor::initWithColor(Color4B(255,255,255,100)))
    {
        return false;
    }
    auto _listner = EventListenerTouchOneByOne::create();
    _listner->setSwallowTouches(true);
    _listner->onTouchBegan = CC_CALLBACK_2(PauseScene:: onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_listner, this);
    
    //加载到当前场景
    auto scene = Director::getInstance()->getRunningScene();
    scene ->addChild(this,999);
    this->setUi();
    return true;
}

void PauseScene::setUi()
{
    //开启回弹效果
    auto _scrollView  =ScrollView::create();
    _scrollView->setBounceEnabled(true);
    this->addChild(_scrollView);
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto btnPause = Button::create("pause.png");
    btnPause->setPosition(Vec2(visibleSize.width*0.8,visibleSize.height*0.2245));
    btnPause->setScale(0.6);
    this->addChild(btnPause);
    btnPause->addClickEventListener(CC_CALLBACK_1(PauseScene::btnContinueCallback, this));
}

void PauseScene::btnContinueCallback(Ref *target)
{
    this->removeFromParentAndCleanup(true);
}
bool PauseScene:: onTouchBegan(cocos2d::Touch *touch, cocos2d::Event  *unused_envent)
{
    return true;
}