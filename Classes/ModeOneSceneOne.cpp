//
//  ModeOneSceneOne.cpp
//  ClickC
//
//  Created by lanqs on 15/6/11.
//
//
#include "ModeOneSceneOne.h"
#include "ui/CocosGUI.h"
#include "time.h"
#include "stdlib.h"
#define OK 1
#define ERROR 0

#include "ModeOneSceneTwo.h"
#include "Function.h"
#include "PauseScene.h"
#include "SureSignOutScene.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace ui;

Scene* ModeOneSceneOne ::createScene()
{
    auto scene = Scene::create();
    auto layer = ModeOneSceneOne::create();
    scene->addChild(layer);
    return scene;
}

bool ModeOneSceneOne::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    int judge=ERROR;
    if(judge==ERROR)
    {
        auto userDefault = UserDefault::getInstance();
        userDefault->setIntegerForKey("highscore",0);
        userDefault->setIntegerForKey("score",0);
        judge=OK;
    }
    this->setUi();
    return true;
}
void ModeOneSceneOne::setUi()
{
    //开启回弹效果
    auto _scrollView  =ScrollView::create();
    _scrollView->setBounceEnabled(true);
    this->addChild(_scrollView);
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    //背景
    auto spriteModeOne = Sprite::create("modeONE2.jpg");
    spriteModeOne->setPosition(visibleSize/2);
    spriteModeOne->setScale(0.6);
    this->addChild(spriteModeOne);
    
    auto sprite = Sprite::create("mode1.png");
    sprite->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2-15));
    sprite->setScale(0.6);
    this->addChild(sprite,90);
    auto fadeOut = FadeOut::create(2);
    auto action = Sequence::create( fadeOut,NULL);
    sprite->runAction(action);
    
    //最高分
    int highscore = getHighScore();
    auto labelHighScore = Label::createWithTTF(StringUtils::format("%d", highscore), "fonts/Marker Felt.ttf",36);
    labelHighScore->setPosition(Vec2(visibleSize.width*0.79,visibleSize.height*0.9+4));
    labelHighScore->setColor(Color3B(146,195,98));
    this->addChild(labelHighScore);

    //当前分数
    int score = getScore();
    auto labelScore = Label::createWithTTF(StringUtils::format("%d", score), "fonts/Marker Felt.ttf", 36);
    labelScore->setPosition(Vec2(visibleSize.width*0.77,visibleSize.height*0.75));
    labelScore->setColor(Color3B(146,195,98));
    this->addChild(labelScore);
    
    //当前关卡
    auto labellevel = Label::createWithTTF(StringUtils::format("%d", 1), "fonts/Marker Felt.ttf", 36);
    labellevel->setPosition(Vec2(visibleSize.width*0.195,visibleSize.height*0.75));
    labellevel->setColor(Color3B(146,195,98));
    this->addChild(labellevel);
    
    //退出、返回主界面
    auto btnSignOut = Button::create("back.png");
    btnSignOut->setPosition(Vec2(visibleSize.width*0.2335,visibleSize.height*0.2232));
    btnSignOut->setScale(0.6);
    this->addChild(btnSignOut);
    btnSignOut->addClickEventListener(CC_CALLBACK_1(ModeOneSceneOne::btnSignOutCallback, this));
    
    
    //暂停
    auto btnPause = Button::create("stop.png");
    btnPause->setPosition(Vec2(visibleSize.width*0.8,visibleSize.height*0.2245));
    btnPause->setScale(0.6);
    this->addChild(btnPause);
    btnPause->addClickEventListener(CC_CALLBACK_1(ModeOneSceneOne::btnPauseCallback, this));
    
//    //当前关卡
//    auto labellevel = Label::createWithTTF(StringUtils::format("%d", 1), "fonts/Marker Felt.ttf", 36);
//    labellevel->setPosition(Vec2(visibleSize.width*0.195,visibleSize.height*0.75));
//    labellevel->setColor(Color3B(146,195,98));
//    this->addChild(labellevel);
    
    //倒计时
    auto animation = Animation::create();
    animation->setDelayPerUnit(1);
    animation->setLoops(1);
    for(int i=13; i>=11; i-- )
    {
        auto frame = SpriteFrame::create(StringUtils::format("%d.png", i), Rect(0,0, 480, 480));
        animation->addSpriteFrame(frame);
        m_limit--;
    }
    auto animate = Animate::create(animation);
    auto spriteTime = Sprite :: create("13.png");
    spriteTime->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2-15));
    this->addChild(spriteTime,88);
    auto delayTime = DelayTime::create(1);
    auto repeatTime = RepeatForever::create(animate);
    auto fadeOutTime = FadeOut::create(1);
    auto actionTime = Sequence::create(delayTime, animate,repeatTime,fadeOutTime,NULL);
    spriteTime->runAction(actionTime);
    
    //遮幕
    auto spriteVeil = Sprite::create("mode1.png");
    spriteVeil->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2-15));
    spriteVeil->setScale(0.6);
    this->addChild(spriteVeil,80);
    auto delayVeil = DelayTime::create(5);
    auto fadeOutVeil = FadeOut::create(1);
    auto actionVeil = Sequence::create(delayVeil, fadeOutVeil,NULL);
    spriteVeil->runAction(actionVeil);
    

    //设置button以及随机数
    int result[4];
    srand((unsigned)time(NULL));
    srand(rand());
    bool  sign=true;
    int temp,i=0;
    while(i<4)
    {
        sign=true;
        
        temp=rand()%4+1;
        if(i ==0 )
        {
            result[i] = temp;
            i++;
        }
        else  //以后产生的随机数和前面相比较，如果重复则重新开始
        {
            for(int j=0; j<i; j++)
            {
                if(temp == result[j])   sign=false;
            }
            if(sign)
            {
                result[i]=temp;
                i++;
            }
        }
    }
    for (int i=0; i<2; i++)
    {
        float y = visibleSize.height*(0.585-(i*0.1874));
        for(int j=0; j<2; j++)
        {
            float x = visibleSize.width*(0.325+(j*0.3333))+4;
            auto btnModeOne = Button::create("mode1btn.jpg");
            btnModeOne->setPosition(Vec2(x,y));
            btnModeOne->setScale(0.6);
            btnModeOne->setTitleText(StringUtils::format("%d", result[m_randomNum]));
            btnModeOne->setTitleFontSize(200);
            btnModeOne->setTitleFontName("fonts/Marker Felt.ttf");
            btnModeOne->setTitleColor(Color3B(255,255,255));
            this->addChild(btnModeOne);
            btnModeOne->addClickEventListener(CC_CALLBACK_1(ModeOneSceneOne::btnModeOneCallFunc, this, result[m_randomNum],x,y));
            m_randomNum++;
        }
    }
    
    //时间
    if(m_limit==0)
    {
        scheduleUpdate(); //系统调度器
        schedule(schedule_selector(ModeOneSceneOne::limitTime), 1.0f); //自定义调度器
        auto labelTime = Label::createWithTTF(StringUtils::format("%d", m_limitTime), "fonts/Marker Felt.ttf", 36);
        labelTime->setPosition(Vec2(visibleSize.width*0.5,visibleSize.height*0.75));
        labelTime->setColor(Color3B(146,195,98));
        labelTime->setOpacity(0);
        this->addChild(labelTime);
        m_labelTime = labelTime;
    }
}
void ModeOneSceneOne::btnModeOneCallFunc(Ref *target,int currentNumOne,int x, int y)
{
    m_clickNum++;
    if(m_clickNum==currentNumOne)
    {
        auto visibleSize = Director::getInstance()->getVisibleSize();
        auto spriteOne = Sprite::create("modeq.jpg");
        spriteOne->setPosition(Vec2(x,y));
        spriteOne->setScale(0.6);
        this->addChild(spriteOne);
        if (m_clickNum==4)
        {
            auto userDefault = UserDefault::getInstance();
            int score = getScore();
            score = score+1;
            auto labelScore = Label::createWithTTF(StringUtils::format("%d", score), "fonts/Marker Felt.ttf", 36);
            labelScore->setPosition(Vec2(visibleSize.width*0.77,visibleSize.height*0.75));
            labelScore->setColor(Color3B(146,195,98));
            this->addChild(labelScore);
            
            userDefault->setIntegerForKey("score", score);
        }
    }
    else
    {
        auto spriteMissOne = Sprite::create("miss.png");
        spriteMissOne->setPosition(Vec2(x,y));
        spriteMissOne->setScale(0.6);
        this->addChild(spriteMissOne);
    }
}
void ModeOneSceneOne::limitTime(float time)
{
    m_limitTime--;
    m_labelTime->setString(StringUtils::format("%dS",m_limitTime));
    if(m_limitTime<=2&&m_limitTime>=0)
    {
        m_labelTime->setOpacity(255);
        if(m_limitTime==0)
        {
            this->changeScene();
        }
    }
}

void ModeOneSceneOne::changeScene()
{
    auto sceneModeOne3 = ModeOneSceneTwo::createScene();
    auto fadeInModeOne3 = TransitionCrossFade::create(1.5, sceneModeOne3);
    Director::getInstance()->pushScene(fadeInModeOne3);
}

void ModeOneSceneOne::btnSignOutCallback(Ref *target)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    Director::getInstance()->pause();
    m_pause = false;
    auto layer = SureSignOutScene ::create();
}

void ModeOneSceneOne::btnPauseCallback(Ref *target)
{
    bool isMusic = CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying();
    if(m_pause==true&&isMusic == true)
    {
        CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
        isMusic = false;
        Director::getInstance()->pause();
        m_pause = false;
        auto layer = PauseScene ::create();
    }
    else if(m_pause==false&&isMusic == false)
    {
        CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("fonts/backgroundmusic.mp3",true);
        isMusic = true;
        Director::getInstance()->resume();
        m_pause = true;
    }
}

void ModeOneSceneOne::onEnterTransitionDidFinish()
{
    Layer::onEnterTransitionDidFinish();
    //音效相关方法
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    //预加载音效
    audio->preloadEffect("fonts/touchmusic.wav");
    //播放音效
    audio->playEffect("fonts/touchmusic.wav");
    audio->setEffectsVolume(40);
    //判断是否重新播放
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("fonts/gameMusic.mp3");
    bool isMusic = CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying();
    if(isMusic == false)
    {
        CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("fonts/gameMusic.mp3",true);
    }
}
void ModeOneSceneOne::onExit()
{
    this->unscheduleUpdate();
}
