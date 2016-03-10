//
//  SureSignOutScene.h
//  ClickC
//
//  Created by lanqs on 15/6/16.
//
//

#ifndef __ClickC__SureSignOutScene__
#define __ClickC__SureSignOutScene__
#include "cocos2d.h"
#include <stdio.h>
USING_NS_CC;
class SureSignOutScene :public LayerColor
{
public:
    bool init();
    void setUi();
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event  *unused_envent);
    void btnSignOutCallback(Ref *target);
    void btnContinueCallback(Ref *target);
    CREATE_FUNC(SureSignOutScene);
};
#endif /* defined(__ClickC__SureSignOutScene__) */
