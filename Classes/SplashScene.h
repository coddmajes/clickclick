#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class SplashScene :public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    bool init();
    
    //闪屏界面
    void setUi();
    void actionSplashCallback();
    void actionCallback();
    CREATE_FUNC(SplashScene);
};

#endif // __HELLOWORLD_SCENE_H__
