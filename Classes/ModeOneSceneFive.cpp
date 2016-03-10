//
//  ModeOneSceneFive.cpp
//  ClickC
//
//  Created by lanqs on 15/6/12.
//
//

#include "ModeOneSceneFive.h"
#include "ui/CocosGUI.h"
#include "time.h"
#include "stdlib.h"
#include "unistd.h"

#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace ui;
Scene* ModeOneSceneFive ::createScene()
{
    auto scene = Scene::create();
    auto layer = ModeOneSceneFive::create();
    scene->addChild(layer);
    return scene;
}

bool ModeOneSceneFive::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    this->setUi();
    return true;
}
void ModeOneSceneFive::setUi()
{
    //开启回弹效果
    auto _scrollView  =ScrollView::create();
    _scrollView->setBounceEnabled(true);
    this->addChild(_scrollView);
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto spriteModeFive = Sprite::create("modeONE2.jpg");
    spriteModeFive->setPosition(visibleSize/2);
    spriteModeFive->setScale(0.6);
    this->addChild(spriteModeFive);
    
    auto sprite = Sprite::create("mode1.png");
    sprite->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2-15));
    sprite->setScale(0.6);
    this->addChild(sprite,90);
    auto fadeOut = FadeOut::create(2);
    auto action = Sequence::create( fadeOut,NULL);
    sprite->runAction(action);
    
    //最高分
    auto userDefault = UserDefault::getInstance();
    int  highscore = userDefault->getIntegerForKey("highscore", 1);
    auto labelHighScore = Label::createWithTTF(StringUtils::format("%d", highscore), "fonts/Marker Felt.ttf",36);
    labelHighScore->setPosition(Vec2(visibleSize.width*0.79,visibleSize.height*0.9+4));
    labelHighScore->setColor(Color3B(146,195,98));
    this->addChild(labelHighScore);
    userDefault->setIntegerForKey ("highscore", 0);
    
    
    //当前关卡
    int  level = userDefault->getIntegerForKey("level", 0);
    auto labellevel = Label::createWithTTF(StringUtils::format("%d", level), "fonts/Marker Felt.ttf", 36);
    labellevel->setPosition(Vec2(visibleSize.width*0.195,visibleSize.height*0.75));
    labellevel->setColor(Color3B(146,195,98));
    this->addChild(labellevel);
    userDefault->setIntegerForKey("level", 1);
    
    
    
    //当前分数
    int score = userDefault->getIntegerForKey("score", 0);
    auto labelScore = Label::createWithTTF(StringUtils::format("%d", score), "fonts/Marker Felt.ttf", 36);
    labelScore->setPosition(Vec2(visibleSize.width*0.77,visibleSize.height*0.75));
    labelScore->setColor(Color3B(146,195,98));
    this->addChild(labelScore);
    userDefault->setIntegerForKey("score", 0);
    
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
        float y = visibleSize.height*(0.5833-(i*0.187));
        for(int j=0; j<2; j++)
        {
            float x = visibleSize.width*(0.3315+(j*0.3324));
            auto btnModeOne = Button::create("mode5.png");
            btnModeOne->setPosition(Vec2(x,y));
            btnModeOne->setScale(0.5);
            btnModeOne->setTitleText(StringUtils::format("%d", result[m_randomNum]));
            btnModeOne->setTitleFontSize(200);
            btnModeOne->setTitleFontName("fonts/Marker Felt.ttf");
            this->addChild(btnModeOne);
            if(result[m_randomNum]%2==0)
            {
                btnModeOne->setTitleColor(Color3B(255,255,255));
            }
            else
            {
                btnModeOne->setTitleColor(Color3B(255,204,153));
            }
            btnModeOne->addClickEventListener(CC_CALLBACK_1(ModeOneSceneFive::btnModeOneCallFunc, this, result[m_randomNum], i, j));
            m_randomNum++;
        }
    }
    
    
    //时间
    if(m_limit==0)
    {
        this->scheduleUpdate(); //系统调度器
        schedule(schedule_selector(ModeOneSceneFive::limitTime), 1.0f); //自定义调度器
        auto labelTime = Label::createWithTTF(StringUtils::format("%d", m_limitTime), "fonts/Marker Felt.ttf", 36);
        labelTime->setPosition(Vec2(visibleSize.width*0.5,visibleSize.height*0.75));
        labelTime->setColor(Color3B(146,195,98));
        this->addChild(labelTime);
        m_labelTime = labelTime;
    }
}
void ModeOneSceneFive ::btnModeOneCallFunc(Ref *target,int currentNumOne,int i, int j)
{
    m_clickNum+=2;
    if(currentNumOne==m_clickNum)
    {
        auto visibleSize = Director::getInstance()->getVisibleSize();
        auto spriteOne = Sprite::create("mode5.png");
        spriteOne->setPosition(visibleSize.width*(0.23+(j*0.1324))+4,visibleSize.height*(0.5833-(i*0.187)));
        spriteOne->setScale(0.5);
        this->addChild(spriteOne,100);
        if (m_clickNum==4)
        {
            this->changeScene();
        }
    }
    else
    {
        auto visibleSize = Director::getInstance()->getVisibleSize();
        auto spriteMissOne = Sprite::create("miss.png");
        spriteMissOne->setPosition(visibleSize.width*(0.3315+(j*0.3324)),visibleSize.height*(0.625-(i*0.09372))+6);
        spriteMissOne->setScale(0.59);
        this->addChild(spriteMissOne);
    }
}


void ModeOneSceneFive::limitTime(float time)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    m_limitTime--;
    m_labelTime->setString(StringUtils::format("%dS",m_limitTime));
    if(m_limitTime<=10&&m_limitTime>=0)
    {
        m_labelTime->setOpacity(255);
        if(m_limitTime==0)
        {
            //        this->changeScene();
        }
    }
//        for (int i=0; i<2; i++)
//        {
//            float y = visibleSize.height*(0.5833-(i*0.187));
//            for(int j=0; j<2; j++)
//            {
//                float x = visibleSize.width*(0.3315+(j*0.3324));
//                auto spriteModeOne = Button::create("modeq.jpg");
//                spriteModeOne->setPosition(Vec2(x,y));
//                spriteModeOne->setScale(0.6);
//                this->addChild(spriteModeOne);
//            }
//        }
//    }
}

void ModeOneSceneFive::changeScene()
{
//    auto sceneModeOne4 = ModeOneSceneFive::createScene();
//    auto fadeInModeOne4 = TransitionCrossFade::create(1.5, sceneModeOne4);
//    Director::getInstance()->pushScene(fadeInModeOne4);
}