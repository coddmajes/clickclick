//
//  ModeTwoSceneTwo1.cpp
//  ClickC
//
//  Created by lanqs on 15/6/15.
//
//

#include "ModeTwoSceneTwo1.h"
#include "ui/CocosGUI.h"
#include "time.h"
#include "stdlib.h"
#include "unistd.h"

#include "Function.h"
#include "ModeTwoSceneThree.h"
#include "PauseScene.h"
#include "SureSignOutScene.h"
#include "SimpleAudioEngine.h"
#include "ModeTwoSceneOne.h"
#include "HomeScene.h"
#include "ModeTwoScore.h"
USING_NS_CC;
using namespace ui;

Scene* ModeTwoSceneTwo1 ::createScene()
{
    auto scene = Scene::create();
    auto layer = ModeTwoSceneTwo1::create();
    scene->addChild(layer);
    return scene;
}

bool ModeTwoSceneTwo1::init()
{
    if ( !LayerColor::init() )
    {
        return false;
    }
    this->setUi();
    return true;
}
void ModeTwoSceneTwo1::setUi()
{
    //开启回弹效果
    auto _scrollView  =ScrollView::create();
    _scrollView->setBounceEnabled(true);
    this->addChild(_scrollView);
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto spriteModeTwo = Sprite::create("mode2-3background.png");
    spriteModeTwo->setPosition(visibleSize/2);
    spriteModeTwo->setScale(0.6);
    this->addChild(spriteModeTwo);
    
    auto sprite = Sprite::create("mode1-2.png");
    sprite->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2-15));
    sprite->setScale(0.6);
    this->addChild(sprite,90);
    auto fadeOut = FadeOut::create(2);
    auto action = Sequence::create( fadeOut,NULL);
    sprite->runAction(action);
    
    //最高分
    int  highscore = getHighScore();
    auto labelHighScore = Label::createWithTTF(StringUtils::format("%d", highscore), "fonts/Marker Felt.ttf",36);
    labelHighScore->setPosition(Vec2(visibleSize.width*0.79,visibleSize.height*0.9+4));
    labelHighScore->setColor(Color3B(146,195,98));
    this->addChild(labelHighScore);
    
    //提示
    auto labelSign = Label::createWithSystemFont("前方高能！当前关卡需要答对90题才能过关哦！", "", 24);
    labelSign->setPosition(Vec2(visibleSize.width*0.5,visibleSize.height*0.825));
    labelSign->setColor(Color3B(204,0,51));
    this->addChild(labelSign);
    
    //当前关卡
    auto labellevel = Label::createWithTTF(StringUtils::format("%d", 4), "fonts/Marker Felt.ttf", 36);
    labellevel->setPosition(Vec2(visibleSize.width*0.195,visibleSize.height*0.75));
    labellevel->setColor(Color3B(146,195,98));
    this->addChild(labellevel);
    
    //退出、返回主界面
    auto btnSignOut = Button::create("back.png");
    btnSignOut->setPosition(Vec2(visibleSize.width*0.2335,visibleSize.height*0.2232));
    btnSignOut->setScale(0.6);
    this->addChild(btnSignOut);
    btnSignOut->addClickEventListener(CC_CALLBACK_1(ModeTwoSceneTwo1::btnSignOutCallback, this));
    
    
    //暂停
    auto btnPause = Button::create("stop.png");
    btnPause->setPosition(Vec2(visibleSize.width*0.8,visibleSize.height*0.2245));
    btnPause->setScale(0.6);
    this->addChild(btnPause);
    btnPause->addClickEventListener(CC_CALLBACK_1(ModeTwoSceneTwo1::btnPauseCallback, this));
    
    //倒计时
    auto animation = Animation::create();
    animation->setDelayPerUnit(1);
    animation->setLoops(1);
    for(int i=13; i>=11; i-- )
    {
        auto frame = SpriteFrame::create(StringUtils::format("%d.png", i), Rect(0,0, 480, 480));
        animation->addSpriteFrame(frame);
        m_limit--;
        
        //当前分数
        int score = getScore();
        auto labelScore = Label::createWithTTF(StringUtils::format("%d", score), "fonts/Marker Felt.ttf", 36);
        labelScore->setPosition(Vec2(visibleSize.width*0.77,visibleSize.height*0.75));
        labelScore->setColor(Color3B(146,195,98));
        this->addChild(labelScore);
        auto fadeOutLabelScore = FadeOut::create(5);
        labelScore->runAction(fadeOutLabelScore);
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
    auto spriteVeil = Sprite::create("mode1-2.png");
    spriteVeil->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2-15));
    spriteVeil->setScale(0.6);
    this->addChild(spriteVeil,80);
    auto delayVeil = DelayTime::create(5);
    auto fadeOutVeil = FadeOut::create(1);
    auto actionVeil = Sequence::create(delayVeil, fadeOutVeil,NULL);
    spriteVeil->runAction(actionVeil);
    
    //时间
    if(m_limit==0)
    {
        scheduleUpdate(); //系统调度器
        schedule(schedule_selector(ModeTwoSceneTwo1::limitTime), 1.0f); //自定义调度器
        auto labelTime = Label::createWithTTF(StringUtils::format("%d", m_limitTime), "fonts/Marker Felt.ttf", 36);
        labelTime->setPosition(Vec2(visibleSize.width*0.5,visibleSize.height*0.75));
        labelTime->setColor(Color3B(146,195,98));
        labelTime->setOpacity(0);
        this->addChild(labelTime);
        m_labelTime = labelTime;
    }
    this->btnWay();
}

void ModeTwoSceneTwo1::btnWay()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    //设置button以及随机数
    int result[20];
    srand((unsigned)time(NULL));
    srand(rand());
    
    bool  sign=true;
    int temp,i=0;
    while(i<20)
    {
        sign=true;
        temp=rand()%20;
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
    int result1[3];
    bool  sign1=true;
    int temp1; i=0;
    while(i<3)
    {
        sign1=true;
        
        temp1=rand()%3;
        if(i ==0 )
        {
            result1[i] = temp1;
            i++;
        }
        else  //以后产生的随机数和前面相比较，如果重复则重新开始
        {
            for(int j=0; j<i; j++)
            {
                if(temp1 == result1[j])   sign1=false;
            }
            if(sign1)
            {
                result1[i]=temp1;
                i++;
            }
        }
    }
    //button
    for (int j=0; j<2; j++)
    {
        int hight = result1[j];
        int width = result1[j+1];
        float x = visibleSize.width*(0.25+(width*0.1666));
        float y = visibleSize.height*(0.347+(hight*0.09375));
        
        auto btnModeOne = Button::create("buttonmode2-3.png");
        btnModeOne->setPosition(Vec2(x,y));
        btnModeOne->setScale(0.55);
        
        if(j==0)
        {
            switch (result1[j])
            {
                case 0:
                    btnModeOne->setTitleText(StringUtils::format("%d+%d",result[j], result[j+1]));
                    m_resultsOne=result[j]+result[j+1];
                    break;
                case 1:
                    btnModeOne->setTitleText(StringUtils::format("%d-%d",result[j], result[j+1]));
                    m_resultsOne=result[j]-result[j+1];
                    break;
                case 2:
                    btnModeOne->setTitleText(StringUtils::format("%d*%d",result[j], result[j+1]));
                    m_resultsOne=result[j]*result[j+1];
                    break;
                case 3:
                    btnModeOne->setTitleText(StringUtils::format("%d/%d",result[j], result[j+1]));
                    m_resultsOne=result[j]/result[j+1];
                    break;
            }
            btnModeOne->setTag(m_resultsOne);
            btnModeOne->addClickEventListener(CC_CALLBACK_1(ModeTwoSceneTwo1::btnModeTwoCallFunc, this,m_resultsOne, x, y));
        }
        if(j==1)
        {
            switch (result1[j])
            {
                case 0:
                    btnModeOne->setTitleText(StringUtils::format("%d+%d",result[j], result[j+1]));
                    m_resultsTwo=result[j]+result[j+1];
                    break;
                case 1:
                    btnModeOne->setTitleText(StringUtils::format("%d-%d",result[j], result[j+1]));
                    m_resultsTwo=result[j]-result[j+1];
                    break;
                case 2:
                    btnModeOne->setTitleText(StringUtils::format("%d*%d",result[j], result[j+1]));
                    m_resultsTwo=result[j]*result[j+1];
                    break;
                case 3:
                    btnModeOne->setTitleText(StringUtils::format("%d/%d",result[j], result[j+1]));
                    m_resultsTwo=result[j]/result[j+1];
                    break;
            }
            btnModeOne->setTag(m_resultsTwo);
            btnModeOne->addClickEventListener(CC_CALLBACK_1(ModeTwoSceneTwo1::btnModeTwoCallFunc, this,m_resultsTwo, x, y));
        }
        btnModeOne->setTitleColor(Color3B(153,204,204));
        btnModeOne->setTitleFontSize(70);
        btnModeOne->setTitleFontName("fonts/Marker Felt.ttf");
        this->addChild(btnModeOne);
        button = btnModeOne;
        
    }
    if(m_resultsOne>m_resultsTwo)
    {
        m_tag = m_resultsOne;
    }
    else
    {
        m_tag = m_resultsTwo;
    }
}
void ModeTwoSceneTwo1::btnModeTwoCallFunc(Ref *target, int tag,int x, int y)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    if(m_tag==tag)
    {
        auto userDefault = UserDefault::getInstance();
        int score = getScore();
        score = score+1;
        auto labelScore = Label::createWithTTF(StringUtils::format("%d", score), "fonts/Marker Felt.ttf", 36);
        labelScore->setPosition(Vec2(visibleSize.width*0.77,visibleSize.height*0.75));
        labelScore->setColor(Color3B(146,195,98));
        this->addChild(labelScore);
        m_labelScore = labelScore;
        auto fadeOutLabel = FadeOut::create(3);
        m_labelScore->runAction(fadeOutLabel);
        
        userDefault->setIntegerForKey("score", score);
        this->removeChildByTag(m_resultsOne);
        this->removeChildByTag(m_resultsTwo);
        this->removeChildByTag(m_tag);
        this->btnWay();
    }
    else
    {
        auto missOne = Sprite::create("miss.png");
        missOne->setPosition(Vec2(x, y));
        missOne->setScale(0.4);
        this->addChild(missOne,100);
        auto fadeOutMiss = FadeOut::create(0.5);
        missOne->runAction(fadeOutMiss);
        this->removeChildByTag(m_resultsOne);
        this->removeChildByTag(m_resultsTwo);
        this->removeChild(missOne);
        this->btnWay();
    }
}
void ModeTwoSceneTwo1::limitTime(float time)
{
    m_limitTime--;
    auto visibleSize = Director::getInstance()->getVisibleSize();
    m_labelTime->setString(StringUtils::format("%dS",m_limitTime));
    if(m_limitTime<=40&&m_limitTime>=0)
    {
        m_labelTime->setOpacity(255);
        auto userDefault = UserDefault::getInstance();
        int score = getScore();
        if(score==90)
        {
            m_labelScore->setColor(Color3B(204, 0, 51));
        }
        if(m_limitTime==0&&score>=90)
        {
            this->changeScene();
        }
        else if(m_limitTime==0&&score<90)
        {
            CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
            auto gameOver = Sprite::create("gameover.jpg");
            gameOver->setPosition(visibleSize/2);
            gameOver->setScale(1.2,1.3);
            this->addChild(gameOver);
            
            auto gameHome = Button::create("signbtn.png");
            gameHome->setPosition(Vec2( visibleSize.width*0.32,visibleSize.height*0.38));
            gameHome->setScale(1.2);
            this->addChild(gameHome);
            gameHome->addClickEventListener(CC_CALLBACK_1(ModeTwoSceneTwo1::btnGameHomeCallback, this));
            
            auto gameAgain = Button::create("signbtn.png");
            gameAgain->setPosition(Vec2( visibleSize.width*0.72,visibleSize.height*0.36));
            gameAgain->setScale(1.2);
            this->addChild(gameAgain);
            gameAgain->addClickEventListener(CC_CALLBACK_1(ModeTwoSceneTwo1::btnGameAgainCallback, this));
            
            auto layer = ModeTwoScore ::create();
        }
        userDefault->setIntegerForKey("score", score);
    }
}

void ModeTwoSceneTwo1::changeScene()
{
    auto sceneModeTwo2 = ModeTwoSceneThree::createScene();
    auto fadeInModeTwo2 = TransitionCrossFade::create(1.5, sceneModeTwo2);
    Director::getInstance()->pushScene(fadeInModeTwo2);
}

void ModeTwoSceneTwo1::btnSignOutCallback(Ref *target)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    Director::getInstance()->pause();
    m_pause = false;
    auto layer = SureSignOutScene ::create();
}

void ModeTwoSceneTwo1::btnPauseCallback(Ref *target)
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

void ModeTwoSceneTwo1::btnGameHomeCallback(Ref *target)
{
    auto sceneHome =HomeScene::createScene();
    auto fadeHome =TransitionCrossFade::create(1, sceneHome);
    Director::getInstance()->pushScene(fadeHome);
}
void ModeTwoSceneTwo1::btnGameAgainCallback(Ref *target)
{
    auto sceneOne =ModeTwoSceneOne::createScene();
    auto fadeOne =TransitionCrossFade::create(1, sceneOne);
    Director::getInstance()->pushScene(fadeOne);
}
void ModeTwoSceneTwo1::onExit()
{
    this->unscheduleUpdate();
}