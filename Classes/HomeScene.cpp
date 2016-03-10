//
//  HomeScene.cpp
//  ClickC
//
//  Created by lanqs on 15/6/10.
//
//

#include "HomeScene.h"
#include "ModeOneSceneOne.h"
#include "ModeTwoSceneOne.h"
#include "ModeThreeScene.h"
#include "ShopScene.h"
#include "SetScene.h"

#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;

Scene* HomeScene ::createScene()
{
    auto scene = Scene::create();
    auto layer = HomeScene::create();
    scene->addChild(layer);
    return scene;
}

bool HomeScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    this->setUi();
    return true;
}

void HomeScene::setUi()
{
    //开启回弹效果
    auto _scrollView  =ScrollView::create();
    _scrollView->setBounceEnabled(true);
    this->addChild(_scrollView);
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto spriteBackground = Sprite::create("mainscene.png");
    spriteBackground->setPosition(visibleSize/2);
    spriteBackground->setScale(0.6);
    this->addChild(spriteBackground);
    
    //设置部分button
    auto spriteButtonOne = Sprite::create("1.png");
    spriteButtonOne->setPosition(Vec2(visibleSize.width*0.129,visibleSize.height*0.743));
    spriteButtonOne->setScale(0.6);
    this->addChild(spriteButtonOne);
    auto jumpOne = JumpBy::create(0.5, Vec2(0,0), 100, 1);
    auto delayOne = DelayTime::create(8);
    auto actionOne = Sequence::create(jumpOne,delayOne,NULL);
    spriteButtonOne->runAction(actionOne);
    auto repeatOne = RepeatForever::create(actionOne);
    spriteButtonOne->runAction(repeatOne);
//    auto musicCallback = CallFunc::create(CC_CALLBACK_0( HomeScene::actionCallback,this));
//    spriteButtonOne->runAction(musicCallback);
    
    
    auto spriteButtonTwo = Sprite::create("2.png");
    spriteButtonTwo->setPosition(Vec2(visibleSize.width*0.31,visibleSize.height*0.743));
    spriteButtonTwo->setScale(0.6);
    this->addChild(spriteButtonTwo);
    auto delayTw = DelayTime::create(1);
    auto jumpTwo = JumpBy::create(1, Vec2(0,0), 80, 2);
    auto delayTwo = DelayTime::create(8);
    auto actionTwo = Sequence::create(delayTw,jumpTwo,delayTwo,NULL);
    spriteButtonTwo->runAction(actionTwo);
    auto repeatTwo = RepeatForever::create(actionTwo);
    spriteButtonTwo->runAction(repeatTwo);
    
    auto spriteButtonThree = Sprite::create("3.png");
    spriteButtonThree->setPosition(Vec2(visibleSize.width*0.49,visibleSize.height*0.743));
    spriteButtonThree->setScale(0.6);
    this->addChild(spriteButtonThree);
    auto delayThre = DelayTime::create(2);
    auto jumpThree = JumpBy::create(1.5, Vec2(0,0), 60, 3);
    auto delayThree = DelayTime::create(8);
    auto actionThree = Sequence::create(delayThre,jumpThree,delayThree,NULL);
    spriteButtonThree->runAction(actionThree);
    auto repeatThree = RepeatForever::create(actionThree);
    spriteButtonThree->runAction(repeatThree);
    
    auto spriteButtonFour = Sprite::create("4.png");
    spriteButtonFour->setPosition(Vec2(visibleSize.width*0.67,visibleSize.height*0.743));
    spriteButtonFour->setScale(0.6);
    this->addChild(spriteButtonFour);
    auto delayFou = DelayTime::create(3);
    auto jumpFour = JumpBy::create(2, Vec2(0,0), 40, 4);
    auto delayFour = DelayTime::create(8);
    auto actionFour = Sequence::create(delayFou,jumpFour,delayFour,NULL);
    spriteButtonFour->runAction(actionFour);
    auto repeatFour = RepeatForever::create(actionFour);
    spriteButtonFour->runAction(repeatFour);
    
    auto spriteButtonFive = Sprite::create("5.png");
    spriteButtonFive->setPosition(Vec2(visibleSize.width*0.129,visibleSize.height*0.21));
    spriteButtonFive->setScale(0.6);
    this->addChild(spriteButtonFive);
    auto delayFiv = DelayTime::create(4);
    auto jumpFive = JumpBy::create(0.5, Vec2(0,0), 100, 1);
    auto delayFive = DelayTime::create(8);
    auto actionFive = Sequence::create(delayFiv,jumpFive,delayFive,NULL);
    spriteButtonFive->runAction(actionFive);
    auto repeatFive = RepeatForever::create(actionFive);
    spriteButtonFive->runAction(repeatFive);
    
    auto spriteButtonSix = Sprite::create("6.png");
    spriteButtonSix->setPosition(Vec2(visibleSize.width*0.31,visibleSize.height*0.21));
    spriteButtonSix->setScale(0.6);
    this->addChild(spriteButtonSix);
    auto delaySi = DelayTime::create(5);
    auto jumpSix = JumpBy::create(1, Vec2(0,0), 80, 2);
    auto delaySix = DelayTime::create(8);
    auto actionSix = Sequence::create(delaySi,jumpSix,delaySix,NULL);
    spriteButtonSix->runAction(actionSix);
    auto repeatSix = RepeatForever::create(actionSix);
    spriteButtonSix->runAction(repeatSix);
    
    auto spriteButtonSeven = Sprite::create("7.png");
    spriteButtonSeven->setPosition(Vec2(visibleSize.width*0.49,visibleSize.height*0.21));
    spriteButtonSeven->setScale(0.6);
    this->addChild(spriteButtonSeven);
    auto delaySeve = DelayTime::create(6);
    auto jumpSeven = JumpBy::create(1.5, Vec2(0,0), 60, 3);
    auto delaySeven = DelayTime::create(8);
    auto actionSeven = Sequence::create(delaySeve,jumpSeven,delaySeven,NULL);
    spriteButtonSeven->runAction(actionSeven);
    auto repeatSeven = RepeatForever::create(actionSeven);
    spriteButtonSeven->runAction(repeatSeven);
    
    auto spriteButtonEight = Sprite::create("8.png");
    spriteButtonEight->setPosition(Vec2(visibleSize.width*0.67,visibleSize.height*0.21));
    spriteButtonEight->setScale(0.6);
    this->addChild(spriteButtonEight);
    auto delayEigh = DelayTime::create(7);
    auto jumpEight = JumpBy::create(2, Vec2(0,0), 80, 4);
    auto delayEight = DelayTime::create(8);
    auto actionEight = Sequence::create(delayEigh,jumpEight,delayEight,NULL);
    spriteButtonEight->runAction(actionEight);
    auto repeatEight = RepeatForever::create(actionEight);
    spriteButtonEight->runAction(repeatEight);
    
    //设置btn
    auto buttonSet = Button::create("set.jpg");
    buttonSet->setPosition(Vec2(visibleSize.width*0.862,visibleSize.height*0.743));
    buttonSet->setScale(0.6);
    this->addChild(buttonSet);
    buttonSet->addClickEventListener(CC_CALLBACK_1(HomeScene::btnSetCallFunc, this));
    
    //商店btn
    auto buttonShop = Button::create("shop.jpg");
    buttonShop->setPosition(Vec2(visibleSize.width*0.862,visibleSize.height*0.21));
    buttonShop->setScale(0.6);
    this->addChild(buttonShop);
    buttonShop->addClickEventListener(CC_CALLBACK_1(HomeScene::btnShopCallFunc, this));
    
    //静音btn
    auto buttonMusic = Button::create("stopmusic.png");
    buttonMusic->setPosition(Vec2(visibleSize.width*0.86,visibleSize.height*0.93));
    buttonMusic->setScale(0.5);
    this->addChild(buttonMusic);
    buttonMusic->addClickEventListener(CC_CALLBACK_1(HomeScene::btnMusicCallFunc, this));
    
    auto btnModeOne = Button::create("modeone.jpg");
    btnModeOne->setPosition(Vec2(visibleSize.width/2-78,visibleSize.height/2+75));
    btnModeOne->setScale(0.4);
    btnModeOne->setTitleText("1");
    btnModeOne->setTitleFontSize(200);
    btnModeOne->setTitleFontName("fonts/Marker Felt.ttf");
    btnModeOne->setTitleColor(Color3B(255,255,255));
    this->addChild(btnModeOne);
    btnModeOne->addClickEventListener(CC_CALLBACK_1(HomeScene::btnModeOneCallFunc, this));
    
    auto btnModeTwo = Button::create("modetwo.jpg");
    btnModeTwo->setPosition(Vec2(visibleSize.width/2+78,visibleSize.height/2+75));
    btnModeTwo->setScale(0.4);
    btnModeTwo->setTitleText("2");
    btnModeTwo->setTitleFontSize(200);
    btnModeTwo->setTitleColor(Color3B(255,255,255));
    btnModeTwo->setTitleFontName("fonts/Marker Felt.ttf");
    this->addChild(btnModeTwo);
    btnModeTwo->addClickEventListener(CC_CALLBACK_1(HomeScene::btnModeTwoCallFunc, this));
    
    auto btnModeThree = Button::create("modethree.jpg");
    btnModeThree->setPosition(Vec2(visibleSize.width/2-78,visibleSize.height/2-75));
    btnModeThree->setScale(0.41);
    btnModeThree->setTitleText("3");
    btnModeThree->setTitleFontSize(200);
    btnModeThree->setTitleColor(Color3B(255,255,255));
    btnModeThree->setTitleFontName("fonts/Marker Felt.ttf");
    this->addChild(btnModeThree);
    btnModeThree->addClickEventListener(CC_CALLBACK_1(HomeScene::btnModeThreeCallFunc, this));
    
    auto btnModeFour = Button::create("modefour.png");
    btnModeFour->setPosition(Vec2(visibleSize.width/2+78,visibleSize.height/2-75));
    btnModeFour->setScale(0.41);
    this->addChild(btnModeFour);
    btnModeFour->addClickEventListener(CC_CALLBACK_1(HomeScene::btnModeFourCallFunc, this));
    
}

void HomeScene::btnSetCallFunc(Ref *target)
{
    this->btnEffect();
    auto layer = SetScene::create();
}

void HomeScene::btnShopCallFunc(Ref *target)
{
    this->btnEffect();
    auto layer = ShopScene ::create();
}
void HomeScene:: btnModeOneCallFunc(Ref *target)
{
    this->btnEffect();
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    auto sceneModeOne =ModeOneSceneOne::createScene();
    auto fadeSceneModeOne =TransitionCrossFade::create(1, sceneModeOne);
    Director::getInstance()->pushScene(fadeSceneModeOne);
}
void HomeScene:: btnModeTwoCallFunc(Ref *target)
{
    this->btnEffect();
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    auto sceneModeTwo =ModeTwoSceneOne::createScene();
    Director::getInstance()->pushScene(sceneModeTwo);
}
void HomeScene:: btnModeThreeCallFunc(Ref *target)
{
    this->btnEffect();
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    auto sceneModeThree =ModeThreeScene::createScene();
    auto fadeSceneModeThree =TransitionCrossFade::create(1, sceneModeThree);
    Director::getInstance()->pushScene(fadeSceneModeThree);
}
void HomeScene:: btnModeFourCallFunc(Ref *target)
{
    this->btnEffect();
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto btnFour = Button::create("EXITbutton.png");
    btnFour->setPosition(Vec2(visibleSize.width/2+78,visibleSize.height/2-75));
    btnFour->setScale(0.3);
    this->addChild(btnFour);
    btnFour->addClickEventListener(CC_CALLBACK_1(HomeScene::btnModeFourSignOutCallFunc, this));
}

void HomeScene::btnModeFourSignOutCallFunc(Ref *target)
{
    this->btnEffect();
    Director::getInstance()->end();
}

void HomeScene::onEnterTransitionDidFinish()
{
    Layer::onEnterTransitionDidFinish();
    //判断是否重新播放
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("fonts/backgroundmusic.mp3");
    bool isMusic = CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying();
    if(isMusic == false)
    {
        CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("fonts/backgroundmusic.mp3",true);
    }
}

void HomeScene::btnMusicCallFunc(Ref *target)
{
    bool isMusic = CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying();
    if(isMusic == false)
    {
        CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("fonts/backgroundmusic.mp3",true);
        isMusic = true;
    }
    else if(isMusic == true)
    {
        CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
        isMusic = false;
    }
}
void HomeScene::btnEffect()
{
    //音效相关方法
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    //预加载音效
    audio->preloadEffect("fonts/touchmusic.wav");
    //播放音效
    audio->playEffect("fonts/touchmusic.wav");
}

//    //音效相关方法
//    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();

//    //预加载音效
//    audio->preloadEffect("fonts/backgroundmusic.mp3");
//    //播放音效
//    audio->playEffect("");
//    //停止所有音效
//    audio->stopAllEffects();
//设置音量，，和音乐的音量不同，分开的
//    audio->setEffectsVolume(50);

//预加载音乐  在某个进程开始时 加载进度去加载音乐以及其他 素材
//    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("");

//改变音量


//播放背景音乐  //true表示循环播放