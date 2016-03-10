//
//  ModeOneHighScore.cpp
//  ClickC
//
//  Created by lanqs on 15/6/16.
//
//

#include "ModeOneHighScore.h"
#include "ui/CocosGUI.h"
#include "Function.h"
using namespace ui;
USING_NS_CC;
#include "HomeScene.h"
bool ModeOneHighScore::init()
{
    if ( !LayerColor::initWithColor(Color4B(255,255,255,100)))
    {
        return false;
    }
    auto _listner = EventListenerTouchOneByOne::create();
    _listner->setSwallowTouches(true);
    _listner->onTouchBegan = CC_CALLBACK_2(ModeOneHighScore:: onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_listner, this);
    
    //加载到当前场景
    auto scene = Director::getInstance()->getRunningScene();
    scene ->addChild(this,999);
    this->setUi();
    return true;
}

void ModeOneHighScore::setUi()
{
    //开启回弹效果
    auto _scrollView  =ScrollView::create();
    _scrollView->setBounceEnabled(true);
    this->addChild(_scrollView);
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto spriteScore = Sprite::create("charts.jpg");
    spriteScore->setPosition(Vec2(visibleSize/2));
    spriteScore->setScale(0.6);
    this->addChild(spriteScore);
    
    //得分
    for (int i=0; i<5; i++)
    {
        int  highscore = getHighScore();
        auto labelScore = Label::createWithTTF(StringUtils::format("%d", highscore), "fonts/Marker Felt.ttf",36);
        labelScore->setPosition(Vec2(visibleSize.width*0.5,visibleSize.height*(0.6-0.073*i)));
        labelScore->setColor(Color3B(146,195,98));
        this->addChild(labelScore);
    }
    
    //退出btn
    auto btnSignOut = Button::create("SUREBTNout.png");
    btnSignOut ->setPosition(Vec2(visibleSize.width*0.5,visibleSize.height*0.23));
    this->addChild(btnSignOut);
    btnSignOut->addClickEventListener(CC_CALLBACK_1(ModeOneHighScore::btnSignOutCallback, this));
}

void ModeOneHighScore::btnSignOutCallback(Ref *target)
{
    this->removeFromParentAndCleanup(true);
    auto sceneHome =HomeScene::createScene();
    auto fadeHome =TransitionCrossFade::create(1, sceneHome);
    Director::getInstance()->pushScene(fadeHome);
}
bool ModeOneHighScore:: onTouchBegan(cocos2d::Touch *touch, cocos2d::Event  *unused_envent)
{
    return true;
}