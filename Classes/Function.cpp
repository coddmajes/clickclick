//
//  Function.cpp
//  ClickC
//
//  Created by lanqs on 15/6/14.
//
//

#include "Function.h"
#include "ui/CocosGUI.h"
#include "time.h"
#include "stdlib.h"
#define   ERROR 1
#include "ModeOneSceneTwo.h"
USING_NS_CC;
using namespace ui;

int getHighScore()
{
    auto userDefault = UserDefault::getInstance();
    int highscore = userDefault->getIntegerForKey("highscore");
    return highscore;
}

int getScore()
{
    auto userDefault = UserDefault::getInstance();
    int  score = userDefault->getIntegerForKey("score");
    return score;
}

int getSetMusicVolumWidth()
{
    auto userDefault = UserDefault::getInstance();
    int  volumWidth = userDefault->getFloatForKey("volumWidth");
    return volumWidth;
}
int getSetMusicVolumHight()
{
    auto userDefault = UserDefault::getInstance();
    int  volumHight = userDefault->getFloatForKey("volumHight");
    return volumHight;
}
int getVolum()
{
    auto userDefault = UserDefault::getInstance();
    int  volum = userDefault->getIntegerForKey("volum");
    return volum;
}
