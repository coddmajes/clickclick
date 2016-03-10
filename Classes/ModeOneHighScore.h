//
//  ModeOneHighScore.h
//  ClickC
//
//  Created by lanqs on 15/6/16.
//
//

#ifndef __ClickC__ModeOneHighScore__
#define __ClickC__ModeOneHighScore__
#include "cocos2d.h"
#include <stdio.h>
USING_NS_CC;
class ModeOneHighScore :public LayerColor
{
public:
    bool init();
    void setUi();
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event  *unused_envent);
    void btnHighScoreChartsCallback(Ref *target);
    void btnSignOutCallback(Ref *target);
    CREATE_FUNC(ModeOneHighScore);
};
#endif /* defined(__ClickC__ModeOneHighScore__) */
