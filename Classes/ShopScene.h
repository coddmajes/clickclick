//
//  ShopScene.h
//  ClickC
//
//  Created by lanqs on 15/6/10.
//
//

#ifndef __ClickC__ShopScene__
#define __ClickC__ShopScene__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;
class ShopScene :public LayerColor
{
public:
    bool init();
    void setUi();
    static Scene* createScene();
    void btnSignOutCallFunc(Ref *target);
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event  *unused_envent);
    CREATE_FUNC(ShopScene);
};
#endif /* defined(__ClickC__ShopScene__) */
