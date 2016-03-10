//
//  HomeScene.h
//  ClickC
//
//  Created by lanqs on 15/6/10.
//
//

#ifndef __ClickC__HomeScene__
#define __ClickC__HomeScene__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
class HomeScene :public Layer
{
public:
    static Scene* createScene();
    bool init();
    
    //闪屏界面
    void setUi();
    //设置按钮
    void btnSetCallFunc(Ref *target);
    //商店按钮
    void btnShopCallFunc(Ref *target);
    //设置mode的按钮
    void btnModeOneCallFunc(Ref *target);
    void btnModeTwoCallFunc(Ref *target);
    void btnModeThreeCallFunc(Ref *target);
    void btnModeFourCallFunc(Ref *target);
    void btnModeFourSignOutCallFunc(Ref *target);
    
    void onEnterTransitionDidFinish();
    
    //背景音乐回调
    void actionCallback();
    //静音btn回调
    void btnMusicCallFunc(Ref *target);
    //音效
    void btnEffect();
    CREATE_FUNC(HomeScene);
};

#endif /* defined(__ClickC__HomeScene__) */
