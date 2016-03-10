//
//  PauseScene.h
//  ClickC
//
//  Created by lanqs on 15/6/16.
//
//

#ifndef __ClickC__PauseScene__
#define __ClickC__PauseScene__
#include "cocos2d.h"
#include <stdio.h>
USING_NS_CC;
class PauseScene :public LayerColor
{
public:
    bool init();
    void setUi();
    void btnContinueCallback(Ref *target);
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event  *unused_envent);
    CREATE_FUNC(PauseScene);
};
#endif /* defined(__ClickC__PauseScene__) */
