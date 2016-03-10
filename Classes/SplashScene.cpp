#include "SplashScene.h"
#include "HomeScene.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;

Scene* SplashScene::createScene()
{
    auto scene = Scene::create();
    auto layer = SplashScene::create();
    scene->addChild(layer);
    return scene;
}

bool SplashScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    this->setUi();
    return true;
}

void SplashScene::setUi()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    //背景
    auto spriteSplash = Sprite::create("background2.png");
    spriteSplash->setPosition(visibleSize/2);
    this->addChild(spriteSplash);
    auto fadeInBackground = FadeIn::create(1);
    auto delaySplash = DelayTime::create(0.9);
    auto callFuncSplash = CallFunc::create(CC_CALLBACK_0(SplashScene::actionSplashCallback, this));
    auto actionSplash = Sequence::create(fadeInBackground,delaySplash,callFuncSplash, NULL);
    spriteSplash->runAction(actionSplash);
    
    //logo
    auto spriteLogo = Sprite::create("logo.png");
    spriteLogo->setScale(0.8);
    spriteLogo->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2+200));
    this->addChild(spriteLogo,999);
    spriteLogo->setOpacity(0);
    auto fadeIn = FadeIn::create(2);
    spriteLogo->runAction(fadeIn);
    
    //名字
    auto spriteName = Sprite::create("name1.png");
    spriteName->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2-150));
    this->addChild(spriteName);
    
    //游戏名动画
    auto scaleTo= ScaleTo::create(1, 0.8);
    auto delay = DelayTime::create(4);
    //回调动作
    auto callFunc = CallFunc::create(CC_CALLBACK_0(SplashScene::actionCallback, this));
    auto action = Sequence::create(scaleTo,delay, callFunc, NULL);
    spriteName->runAction(action);
    
}

void SplashScene::actionSplashCallback()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto _emiter =ParticleSystemQuad::create("res/splash.plist");
    //设置离子的纹理
    auto texture = Director::getInstance()->getTextureCache()->addImage("b.jpg");
    _emiter->setTexture(texture);
    _emiter->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2+200));
    this->addChild(_emiter);
}

void SplashScene::actionCallback()
{
    auto scene =HomeScene::createScene();
    //替换场景
    auto fadeScene =TransitionCrossFade::create(1, scene);
    Director::getInstance()->pushScene(fadeScene);

}
