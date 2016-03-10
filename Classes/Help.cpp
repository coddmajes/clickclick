//
//  Help.cpp
//  ClickC
//
//  Created by lanqs on 15/6/15.
//
//

#include "Help.h"
#include "ui/CocosGUI.h"
#include "cocos2d.h"
USING_NS_CC;
using namespace ui;
#include "HomeScene.h"
Scene* Help ::createScene()
{
    auto scene = Scene::create();
    auto layer = Help::create();
    scene->addChild(layer);
    return scene;
}

bool Help::init()
{
    if ( !LayerColor::initWithColor(Color4B(160,160,160,120)))
    {
        return false;
    }
        
    this->setUi();
    return true;
}
void Help::setUi()
{
    //开启回弹效果
    auto _scrollView  =ScrollView::create();
    _scrollView->setBounceEnabled(true);
    this->addChild(_scrollView);
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto spriteBackground = Sprite::create("help1.jpg");
    spriteBackground->setScale(0.6);
    spriteBackground->setPosition(visibleSize/2);
    this->addChild(spriteBackground);
    
    auto btnSignOut = Button::create("signbtn.png");
    btnSignOut ->setPosition(Vec2(visibleSize.width*0.925,visibleSize.height*0.96));
    btnSignOut->setScale(0.8);
    this->addChild(btnSignOut);
    btnSignOut->addClickEventListener(CC_CALLBACK_1(Help::btnSignOutCallFunc, this));
}
void Help::btnSignOutCallFunc(cocos2d::Ref*)
{
    auto sceneHome =HomeScene::createScene();
    auto fadeHome =TransitionCrossFade::create(1, sceneHome);
    Director::getInstance()->pushScene(fadeHome);
}