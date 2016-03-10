//
//  SetScene.cpp
//  ClickC
//
//  Created by lanqs on 15/6/10.
//
//

#include "SetScene.h"
#include "ui/CocosGUI.h"
#include "cocos2d.h"
USING_NS_CC;
using namespace ui;

#include "SetMusic.h"
#include "Help.h"
#include "SimpleAudioEngine.h"

bool SetScene::init()
{
    if ( !LayerColor::initWithColor(Color4B(160,160,160,100)))
    {
        return false;
    }
    auto _listner = EventListenerTouchOneByOne::create();
    _listner->setSwallowTouches(true);
    _listner->onTouchBegan = CC_CALLBACK_2(SetScene:: onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_listner, this);
    
    //加载到当前场景
    auto scene = Director::getInstance()->getRunningScene();
    scene ->addChild(this,999);
    this->setUi();
    return true;
}

void SetScene::setUi()
{
    //开启回弹效果
    auto _scrollView  =ScrollView::create();
    _scrollView->setBounceEnabled(true);
    this->addChild(_scrollView);
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto spriteBackground = Sprite::create("setscene.jpg");
    spriteBackground->setScale(0.6);
    spriteBackground->setPosition(visibleSize/2);
    this->addChild(spriteBackground);
    
    //button 分别进行点击调用
    for (int i=0; i<2; i++)
    {
        float y = visibleSize.height*(0.564-(i*0.125));
        for(int j=0; j<2; j++)
        {
            float x = visibleSize.width*(0.382+(j*0.2222))+4;
            auto btnModeOne = Button::create("setMbtn.png");
            btnModeOne->setPosition(Vec2(x,y));
            btnModeOne->setScale(0.6);
            this->addChild(btnModeOne);
            btnModeOne->setTag(m_tag);
            
            btnModeOne->addClickEventListener(CC_CALLBACK_1(SetScene::btnSetCallFunc, this,m_tag));
            m_tag++;
        }
    }
    
    auto btnSignOut = Button::create("signbtn.png");
    btnSignOut ->setPosition(Vec2(visibleSize.width*0.76,visibleSize.height*0.65));
    btnSignOut->setScale(0.59);
    this->addChild(btnSignOut);
    btnSignOut->addClickEventListener(CC_CALLBACK_1(SetScene::btnSignOutCallFunc, this));
    
}
void SetScene:: btnSetCallFunc(cocos2d::Ref*,int tag)
{
    if(tag==0)
    {
        auto layer = SetMusic ::create();
    }
    if(tag==1)
    {
        this->removeFromParentAndCleanup(true);
    }
    if(tag==2)
    {
        auto sceneHelp =Help::createScene();
        auto fadeHelp =TransitionCrossFade::create(1, sceneHelp);
        Director::getInstance()->pushScene(fadeHelp);
    }

}
void SetScene::onEnterTransitionDidFinish()
{
    Layer::onEnterTransitionDidFinish();
    //音效相关方法
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    //预加载音效
    audio->preloadEffect("fonts/touchmusic.wav");
    //播放音效
    audio->playEffect("fonts/touchmusic.wav");
}
void SetScene::btnSignOutCallFunc(cocos2d::Ref*)
{
    this->removeFromParentAndCleanup(true);
}
bool SetScene:: onTouchBegan(cocos2d::Touch *touch, cocos2d::Event  *unused_envent)
{
    return true;
}