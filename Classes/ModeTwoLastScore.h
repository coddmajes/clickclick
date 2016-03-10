//
//  ModeTwoLastScore.h
//  ClickC
//
//  Created by lanqs on 15/6/16.
//
//

#ifndef __ClickC__ModeTwoLastScore__
#define __ClickC__ModeTwoLastScore__
#include "cocos2d.h"
#include <stdio.h>
USING_NS_CC;
class ModeTwoLastScore :public LayerColor
{
public:
    bool init();
    void setUi();
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event  *unused_envent);
    void btnHighScoreChartsCallback(Ref *target);
    void btnSignOutCallback(Ref *target);
    CREATE_FUNC(ModeTwoLastScore);
};

#endif /* defined(__ClickC__ModeTwoLastScore__) */
