//
//  SetMusic.cpp
//  ClickC
//
//  Created by lanqs on 15/6/15.
//
//
#include "HomeScene.h"
#include "ui/CocosGUI.h"
#include "cocos2d.h"
USING_NS_CC;
using namespace ui;
#include "SetMusic.h"
#include "SimpleAudioEngine.h"
bool SetMusic::init()
{
    if ( !LayerColor::initWithColor(Color4B(160,160,160,100)))
    {
        return false;
    }
    auto _listner = EventListenerTouchOneByOne::create();
    _listner->setSwallowTouches(true);
    _listner->onTouchBegan = CC_CALLBACK_2(SetMusic:: onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_listner, this);
    
    //加载到当前场景
    auto scene = Director::getInstance()->getRunningScene();
    scene ->addChild(this,999);
    this->setUi();
    return true;
}
void SetMusic::setUi()
{
    //开启回弹效果
    auto _scrollView  =ScrollView::create();
    _scrollView->setBounceEnabled(true);
    this->addChild(_scrollView);
    
    //背景
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto spriteBackground = Sprite::create("setmusic1.jpg");
    spriteBackground->setScale(0.6);
    spriteBackground->setPosition(visibleSize/2);
    this->addChild(spriteBackground);
    
    //加减音量
    auto btnMusicIncrease1 = Button::create("increase.png");
    int x = visibleSize.width*0.74;
    int y = visibleSize.height*0.555;
    btnMusicIncrease1->setPosition(Vec2(x, y));
    this->addChild(btnMusicIncrease1);
    btnMusicIncrease1->addClickEventListener(CC_CALLBACK_1(SetMusic::btnIncrease1, this));
    
    int p = visibleSize.width*0.32;
    int q = visibleSize.height*0.555;
    auto btnMusicDecrease1 = Button::create("decrease.png");
    btnMusicDecrease1->setPosition(Vec2(p, q));
    this->addChild(btnMusicDecrease1);
    btnMusicDecrease1->addClickEventListener(CC_CALLBACK_1(SetMusic::btnDecrease1, this));
    
    int k = visibleSize.width*0.74;
    int t = visibleSize.height*0.42;
    auto btnMusicIncrease2 = Button::create("increase.png");
    btnMusicIncrease2->setPosition(Vec2(k, t));
    this->addChild(btnMusicIncrease2);
    btnMusicIncrease2->addClickEventListener(CC_CALLBACK_1(SetMusic::btnIncrease2, this));
    
    int w = visibleSize.width*0.32;
    int s = visibleSize.height*0.42;
    auto btnMusicDecrease2 = Button::create("decrease.png");
    btnMusicDecrease2->setPosition(Vec2(w, s));
    this->addChild(btnMusicDecrease2);
    btnMusicDecrease2->addClickEventListener(CC_CALLBACK_1(SetMusic::btnDecrease2, this));
    
    
    //音量控制
    m_spriteWidth1 = visibleSize.width*0.5;
    m_spriteHeigh1 = visibleSize.height*0.553;
    auto spriteMusic1 = Sprite::create("setmusicbtn.png");
    spriteMusic1->setPosition(Vec2(m_spriteWidth1, m_spriteHeigh1));
    this->addChild(spriteMusic1);
    m_sprite1 = spriteMusic1;
    
    m_spriteWidth2 = visibleSize.width*0.5;
    m_spriteHeigh2 = visibleSize.height*0.42;
    auto spriteMusic2 = Sprite::create("setmusicbtn.png");
    spriteMusic2->setPosition(Vec2(m_spriteWidth2, m_spriteHeigh2));
    this->addChild(spriteMusic2);
    m_sprite2 = spriteMusic2;

    
    
    //退出按钮
    auto btnSignOut = Button::create("signbtn.png");
    btnSignOut ->setPosition(Vec2(visibleSize.width*0.76,visibleSize.height*0.65));
    btnSignOut->setScale(0.59);
    this->addChild(btnSignOut);
    btnSignOut->addClickEventListener(CC_CALLBACK_1(SetMusic::btnSignOutCallFunc, this));
}
void SetMusic::btnSignOutCallFunc(cocos2d::Ref*)
{
    this->removeFromParentAndCleanup(true);
    auto sceneHome =HomeScene::createScene();
    auto fadeHome =TransitionCrossFade::create(1, sceneHome);
    Director::getInstance()->pushScene(fadeHome);
}

void SetMusic::btnIncrease1(cocos2d::Ref*)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    if(m_spriteWidth1<=visibleSize.width*0.6&&m_spriteWidth1>=visibleSize.width*0.4)
    {
        m_sprite1->setPosition(Vec2(m_spriteWidth1+visibleSize.width*0.02,m_spriteHeigh1));
        m_spriteWidth1 = m_spriteWidth1+visibleSize.width*0.02;
        m_volume=m_volume+10;
    }
    else if(m_spriteWidth1<visibleSize.width*0.4)
    {
        m_sprite1->setPosition(Vec2(visibleSize.width*0.4,visibleSize.height*0.553));
        m_spriteWidth1 = visibleSize.width*0.4;
        m_volume=0;
    }
    CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(m_volume);
}
void SetMusic::btnDecrease1(cocos2d::Ref*)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    if(m_spriteWidth1<=visibleSize.width*0.6&&m_spriteWidth1>=visibleSize.width*0.4)
    {
        m_sprite1->setPosition(Vec2(m_spriteWidth1-visibleSize.width*0.02,m_spriteHeigh1));
        m_spriteWidth1 = m_spriteWidth1-visibleSize.width*0.02;
        m_volume=m_volume-10;
    }
    else if(m_spriteWidth1>visibleSize.width*0.6)
    {
        m_sprite1->setPosition(Vec2(visibleSize.width*0.6,visibleSize.height*0.553));
        m_spriteWidth1 = visibleSize.width*0.6;
        m_volume=100;
    }
    CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(m_volume);
}

void SetMusic::btnIncrease2(cocos2d::Ref*)
{
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    if(m_spriteWidth2<=visibleSize.width*0.6&&m_spriteWidth2>=visibleSize.width*0.4)
    {
        m_sprite2->setPosition(Vec2(m_spriteWidth2+visibleSize.width*0.02,m_spriteHeigh2));
        m_spriteWidth2 = m_spriteWidth2+visibleSize.width*0.02;
        m_volume1 = m_volume1+10;
    }
    else if(m_spriteWidth2<visibleSize.width*0.4)
    {
        m_sprite2->setPosition(Vec2(visibleSize.width*0.4,visibleSize.height*0.42));
        m_spriteWidth2 = visibleSize.width*0.4;
        m_volume1 = 0;
    }
    audio->setEffectsVolume(m_volume1);
}
void SetMusic::btnDecrease2(cocos2d::Ref*)
{
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    if(m_spriteWidth2<=visibleSize.width*0.6&&m_spriteWidth2>=visibleSize.width*0.4)
    {
        m_sprite2->setPosition(Vec2(m_spriteWidth2-visibleSize.width*0.02,m_spriteHeigh2));
        m_spriteWidth2 = m_spriteWidth2-visibleSize.width*0.02;
        m_volume1 = m_volume1-10;
    }
    else if(m_spriteWidth2>visibleSize.width*0.6)
    {
        m_sprite2->setPosition(Vec2(visibleSize.width*0.6,visibleSize.height*0.42));
        m_spriteWidth2 = visibleSize.width*0.6;
        m_volume1 = 100;
    }
    audio->setEffectsVolume(m_volume1);
}

bool SetMusic:: onTouchBegan(cocos2d::Touch *touch, cocos2d::Event  *unused_envent)
{
    return true;
}
