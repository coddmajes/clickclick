//
//  ModeTwoScore.h
//  ClickC
//
//  Created by lanqs on 15/6/17.
//
//

#ifndef __ClickC__ModeTwoScore__
#define __ClickC__ModeTwoScore__
#include "cocos2d.h"
#include <stdio.h>
USING_NS_CC;
class ModeTwoScore :public LayerColor
{
public:
    bool init();
    void setUi();
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event  *unused_envent);
    void btnHighScoreChartsCallback(Ref *target);
    void btnSignOutCallback(Ref *target);
    CREATE_FUNC(ModeTwoScore);
};
#endif /* defined(__ClickC__ModeTwoScore__) */
