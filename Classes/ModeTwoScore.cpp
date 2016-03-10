//
//  ModeTwoScore.cpp
//  ClickC
//
//  Created by lanqs on 15/6/17.
//
//

#include "ModeTwoScore.h"
#include "ui/CocosGUI.h"
#include "Function.h"
using namespace ui;
USING_NS_CC;
#include "HomeScene.h"
#include "ModeTwoSceneOne.h"
#include "ModeTwoSceneOne1.h"
#include "ModeTwoSceneTwo.h"
#include "ModeTwoSceneTwo1.h"
#include "ModeTwoSceneThree.h"
bool ModeTwoScore::init()
{
    if ( !LayerColor::initWithColor(Color4B(160,160,160,160)))
    {
        return false;
    }
    auto _listner = EventListenerTouchOneByOne::create();
    _listner->setSwallowTouches(true);
    _listner->onTouchBegan = CC_CALLBACK_2(ModeTwoScore:: onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_listner, this);
    
    //加载到当前场景
    auto scene = Director::getInstance()->getRunningScene();
    scene ->addChild(this,999);
    this->setUi();
    return true;
}

void ModeTwoScore::setUi()
{
    //开启回弹效果
    auto _scrollView  =ScrollView::create();
    _scrollView->setBounceEnabled(true);
    this->addChild(_scrollView);
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto spriteScore = Sprite::create("Mode2sCORE.png");
    spriteScore->setPosition(Vec2(visibleSize/2));
    spriteScore->setScale(0.6);
    this->addChild(spriteScore);
    
    
    //退出btn
    auto btnSignOut = Button::create("m2hscore.png");
    btnSignOut ->setPosition(Vec2(visibleSize.width*0.5,visibleSize.height*0.4));
    btnSignOut->setScale(0.59);
    this->addChild(btnSignOut);
    btnSignOut->addClickEventListener(CC_CALLBACK_1(ModeTwoScore::btnSignOutCallback, this));
    
    //得分
    auto userDefault = UserDefault::getInstance();
    int  score = getScore();
    auto labelScore = Label::createWithTTF(StringUtils::format("%d", score), "fonts/Marker Felt.ttf",36);
    labelScore->setPosition(Vec2(visibleSize.width*0.5,visibleSize.height*0.4));
    labelScore->setColor(Color3B(146,195,98));
    userDefault->setIntegerForKey("score", score);
    this->addChild(labelScore);
}

void ModeTwoScore::btnSignOutCallback(Ref *target)
{
    this->removeFromParentAndCleanup(true);
}
bool ModeTwoScore:: onTouchBegan(cocos2d::Touch *touch, cocos2d::Event  *unused_envent)
{
    return true;
}