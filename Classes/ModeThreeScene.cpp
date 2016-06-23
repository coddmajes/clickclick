//
//  ModeThreeScene.cpp
//  ClickC
//
//  Created by lanqs on 15/6/11.
//
//

#include "ModeThreeScene.h"
#include "PauseScene.h"
#include "SureSignOutScene.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace ui;

Scene* ModeThreeScene ::createScene()
{
    auto scene = Scene::create();
    auto layer = ModeThreeScene::create();
    scene->addChild(layer);
    return scene;
}

bool ModeThreeScene::init()
{
    if (!LayerColor::initWithColor(Color4B(255, 0, 0, 255)) )
    {
        return false;
    }
    
    this->setUi();
    return true;
}
void ModeThreeScene::setUi()
{
    //开启回弹效果
    auto _scrollView  =ScrollView::create();
    _scrollView->setBounceEnabled(true);
    this->addChild(_scrollView);
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto spriteModeThree = Sprite::create("Mode3.png");
    spriteModeThree->setPosition(visibleSize/2);
    spriteModeThree->setScale(0.6);
    this->addChild(spriteModeThree);
    
    auto sprite = Sprite::create("mode3-1.png");
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
    
    //退出、返回主界面
    auto btnSignOut = Button::create("back.png");
    btnSignOut->setPosition(Vec2(visibleSize.width*0.2335,visibleSize.height*0.2232));
    btnSignOut->setScale(0.6);
    this->addChild(btnSignOut);
    btnSignOut->addClickEventListener(CC_CALLBACK_1(ModeThreeScene::btnSignOutCallback, this));
    
    
    //暂停
    auto btnPause = Button::create("stop.png");
    btnPause->setPosition(Vec2(visibleSize.width*0.8,visibleSize.height*0.2245));
    btnPause->setScale(0.6);
    this->addChild(btnPause);
    btnPause->addClickEventListener(CC_CALLBACK_1(ModeThreeScene::btnPauseCallback, this));
    
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
    auto spriteVeil = Sprite::create("mode3-1.png");
    spriteVeil->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2-15));
    spriteVeil->setScale(0.6);
    this->addChild(spriteVeil,80);
    auto delayVeil = DelayTime::create(5);
    auto fadeOutVeil = FadeOut::create(1);
    auto actionVeil = Sequence::create(delayVeil, fadeOutVeil,NULL);
    spriteVeil->runAction(actionVeil);
    
    this->btnWay();
}
void ModeThreeScene::btnWay()
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
        m_tag++;
        int hight = result1[j];
        int width = result1[j+1];
        float x = visibleSize.width*(0.25+(width*0.1666));
        float y = visibleSize.height*(0.347+(hight*0.09375));
        
        auto btnModeOne = Button::create("buttonmode2-1.png");
        btnModeOne->setPosition(Vec2(x,y));
        btnModeOne->setScale(0.55);
        btnModeOne->setTitleText(StringUtils::format("%d", result[j]));
        btnModeOne->setTitleFontSize(100);
        btnModeOne->setTitleFontName("fonts/Marker Felt.ttf");
        btnModeOne->setTitleColor(Color3B(255,255,255));
        btnModeOne->setTag(m_tag);
        this->addChild(btnModeOne);
        btnModeOne->addClickEventListener(CC_CALLBACK_1(ModeThreeScene::btnModeThreeCallFunc, this,result[j],m_tag, width,hight));
        button = btnModeOne;
        if(j==0)
        {
            m_tag1=m_tag;
        }
        if(j==1)
        {
            m_tag2=m_tag;
        }
    }
}
void ModeThreeScene::btnModeThreeCallFunc(Ref *target, int currentNumOne,int tag, int width, int hight)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    if(tag==m_tag1)
    {
        m_clickNum++;
        while(m_clickNum==currentNumOne)
        {
            auto spriteOne = Sprite::create("yes.png");
            spriteOne->setPosition(visibleSize.width*(0.25+(width*0.1666)),visibleSize.height*(0.347+(hight*0.09375)));
            spriteOne->setScale(0.5);
            this->addChild(spriteOne,100);
            this->removeChild(spriteOne);
            m_clickNum=0;
            this->btnWay();
        }
        if(m_clickNum>currentNumOne)
        {
            auto missOne = Sprite::create("miss.png");
            missOne->setPosition(visibleSize.width*(0.25+(width*0.1666)),visibleSize.height*(0.347+(hight*0.09375)));
            missOne->setScale(0.4);
            this->addChild(missOne,100);
            this->removeChild(missOne);
            auto gameOver = Sprite::create("miss.png");
            gameOver->setPosition(visibleSize/2);
            gameOver->setScale(0.4);
            this->addChild(gameOver,100);
        }
    }
    if(tag==m_tag2)
    {
        m_clickNum++;
        if(m_clickNum==currentNumOne)
        {
            auto spriteOne = Sprite::create("yes.png");
            spriteOne->setPosition(visibleSize.width*(0.25+(width*0.1666)),visibleSize.height*(0.347+(hight*0.09375)));
            spriteOne->setScale(0.5);
            this->addChild(spriteOne,100);
            this->removeChild(spriteOne);
            this->btnWay();
        }
        else
        {
            auto missOne = Sprite::create("miss.png");
            missOne->setPosition(visibleSize.width*(0.25+(width*0.1666)),visibleSize.height*(0.347+(hight*0.09375)));
            missOne->setScale(0.4);
            this->addChild(missOne,100);
            this->removeChild(missOne);
            auto gameOver = Sprite::create("miss.png");
            gameOver->setPosition(visibleSize/2);
            gameOver->setScale(0.4);
            this->addChild(gameOver,100);
        }
    }
}

void ModeThreeScene::changeScene()
{
    auto sceneModeThree = ModeThreeScene::createScene();
    auto fadeInModeThree = TransitionCrossFade::create(1.5, sceneModeThree);
    Director::getInstance()->pushScene(fadeInModeThree);
}
void ModeThreeScene::limitTime1()
{
    //时间
    if(m_limit==0)
    {
        auto visibleSize = Director::getInstance()->getVisibleSize();
        scheduleUpdate(); //系统调度器
        schedule(schedule_selector(ModeThreeScene::limitTime2), 1.0f); //自定义调度器
        auto labelTime = Label::createWithTTF(StringUtils::format("%d", m_limitTime), "fonts/Marker Felt.ttf", 36);
        labelTime->setPosition(Vec2(visibleSize.width*0.5,visibleSize.height*0.75));
        labelTime->setColor(Color3B(146,195,98));
        labelTime->setOpacity(0);
        this->addChild(labelTime);
        m_labelTime = labelTime;
    }
}
void ModeThreeScene::limitTime2(float time)
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

void ModeThreeScene::btnSignOutCallback(Ref *target)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    Director::getInstance()->pause();
    m_pause = false;
    auto layer = SureSignOutScene ::create();
}

void ModeThreeScene::btnPauseCallback(Ref *target)
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
