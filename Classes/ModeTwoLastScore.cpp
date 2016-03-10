//
//  ModeTwoLastScore.cpp
//  ClickC
//
//  Created by lanqs on 15/6/16.
//
//

#include "ModeTwoLastScore.h"
#include "ui/CocosGUI.h"
#include "Function.h"
using namespace ui;
USING_NS_CC;
#include "HomeScene.h"
bool ModeTwoLastScore::init()
{
    if ( !LayerColor::initWithColor(Color4B(160,160,160,160)))
    {
        return false;
    }
    auto _listner = EventListenerTouchOneByOne::create();
    _listner->setSwallowTouches(true);
    _listner->onTouchBegan = CC_CALLBACK_2(ModeTwoLastScore:: onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_listner, this);
    
    //加载到当前场景
    auto scene = Director::getInstance()->getRunningScene();
    scene ->addChild(this,999);
    this->setUi();
    return true;
}

void ModeTwoLastScore::setUi()
{
    //开启回弹效果
    auto _scrollView  =ScrollView::create();
    _scrollView->setBounceEnabled(true);
    this->addChild(_scrollView);
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto spriteScore = Sprite::create("m2lastscore.png");
    spriteScore->setPosition(Vec2(visibleSize/2));
    spriteScore->setScale(0.6);
    this->addChild(spriteScore);
    
    
    //退出btn
    auto btnSignOut = Button::create("m2hscore.png");
    btnSignOut ->setPosition(Vec2(visibleSize.width*0.5,visibleSize.height*0.4));
    btnSignOut->setScale(0.59);
    this->addChild(btnSignOut);
    btnSignOut->addClickEventListener(CC_CALLBACK_1(ModeTwoLastScore::btnSignOutCallback, this));
    
    //得分
    auto userDefault = UserDefault::getInstance();
    int  score = getHighScore();
    int highscore = getHighScore();
    highscore = score;
    auto labelScore = Label::createWithTTF(StringUtils::format("%d", highscore), "fonts/Marker Felt.ttf",36);
    labelScore->setPosition(Vec2(visibleSize.width*0.5,visibleSize.height*0.4));
    labelScore->setColor(Color3B(146,195,98));
    userDefault->setIntegerForKey("highscore", highscore);
    this->addChild(labelScore);
}

void ModeTwoLastScore::btnSignOutCallback(Ref *target)
{
    this->removeFromParentAndCleanup(true);
    auto sceneHome =HomeScene::createScene();
    auto fadeHome =TransitionCrossFade::create(1, sceneHome);
    Director::getInstance()->pushScene(fadeHome);
}
bool ModeTwoLastScore:: onTouchBegan(cocos2d::Touch *touch, cocos2d::Event  *unused_envent)
{
    return true;
}