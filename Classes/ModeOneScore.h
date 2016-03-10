//
//  ModeOneScore.h
//  ClickC
//
//  Created by lanqs on 15/6/16.
//
//

#ifndef __ClickC__ModeOneScore__
#define __ClickC__ModeOneScore__
#include "cocos2d.h"
#include <stdio.h>
USING_NS_CC;
class ModeOneScore :public LayerColor
{
public:
    bool init();
    void setUi();
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event  *unused_envent);
    void btnHighScoreChartsCallback(Ref *target);
    void btnSignOutCallback(Ref *target);
    CREATE_FUNC(ModeOneScore);
};

#endif /* defined(__ClickC__ModeOneScore__) */
