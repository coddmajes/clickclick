//
//  ModeOneScore.cpp
//  ClickC
//
//  Created by lanqs on 15/6/16.
//
//

#include "ModeOneScore.h"
#include "ui/CocosGUI.h"
#include "Function.h"
using namespace ui;
USING_NS_CC;
#include "ModeOneHighScore.h"
#include "HomeScene.h"
bool ModeOneScore::init()
{
    if ( !LayerColor::initWithColor(Color4B(85,85,85,240)))
    {
        return false;
    }
    auto _listner = EventListenerTouchOneByOne::create();
    _listner->setSwallowTouches(true);
    _listner->onTouchBegan = CC_CALLBACK_2(ModeOneScore:: onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_listner, this);
    
    //加载到当前场景
    auto scene = Director::getInstance()->getRunningScene();
    scene ->addChild(this,999);
    this->setUi();
    return true;
}

void ModeOneScore::setUi()
{
    //开启回弹效果
    auto _scrollView  =ScrollView::create();
    _scrollView->setBounceEnabled(true);
    this->addChild(_scrollView);
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto spriteScore = Sprite::create("gamescore.jpg");
    spriteScore->setPosition(Vec2(visibleSize/2));
    this->addChild(spriteScore);
    
    //得分
    auto userDefault = UserDefault::getInstance();
    int  score = getScore();
    auto labelScore = Label::createWithTTF(StringUtils::format("%d", score), "fonts/Marker Felt.ttf",36);
    labelScore->setPosition(Vec2(visibleSize.width*0.5,visibleSize.height*0.6));
    labelScore->setColor(Color3B(146,195,98));
    userDefault->setIntegerForKey("score", score);
    this->addChild(labelScore);
    
    //查看个人排行榜
    auto btnCharts = Button::create("SUREBTNhs.png");
    btnCharts ->setPosition(Vec2(visibleSize.width*0.3,visibleSize.height*0.4));
    this->addChild(btnCharts);
    btnCharts->addClickEventListener(CC_CALLBACK_1(ModeOneScore::btnHighScoreChartsCallback, this));
    
    //退出btn
    auto btnSignOut = Button::create("SUREBTNout.png");
    btnSignOut ->setPosition(Vec2(visibleSize.width*0.7,visibleSize.height*0.4));
    this->addChild(btnSignOut);
    btnSignOut->addClickEventListener(CC_CALLBACK_1(ModeOneScore::btnSignOutCallback, this));
}

void ModeOneScore::btnHighScoreChartsCallback(Ref *target)
{
    auto layer =ModeOneHighScore ::create();
}

void ModeOneScore::btnSignOutCallback(Ref *target)
{
    this->removeFromParentAndCleanup(true);
    auto sceneHome =HomeScene::createScene();
    auto fadeHome =TransitionCrossFade::create(1, sceneHome);
    Director::getInstance()->pushScene(fadeHome);
}
bool ModeOneScore:: onTouchBegan(cocos2d::Touch *touch, cocos2d::Event  *unused_envent)
{
    return true;
}