//
//  ModeOneSceneOne.h
//  ClickC
//
//  Created by lanqs on 15/6/11.
//
//

#ifndef __ClickC__ModeOneSceneOne__
#define __ClickC__ModeOneSceneOne__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;
class ModeOneSceneOne :public Layer
{
public:
    
    int m_randomNum=0;
    //限定时间
    int m_limitTime=7;
    //点击次数
    int m_clickNum=0;
    //倒计时判断标注
    int m_limit = 3;
    //文字
    Label  *m_labelTime;
    void setUi();
    bool init();
    static Scene* createScene();
    //2x2游戏按钮
    void btnModeOneCallFunc(Ref *target,int currentNumOne,int x, int y);

    //退出btn回调
    void btnSignOutCallback(Ref *target);
    //暂停btn回调
    bool m_pause=true;
    void btnPauseCallback(Ref *target);
    void onEnterTransitionDidFinish();
    //时间限制
    void limitTime(float time);

    void onExit();
    //场景切换
    void changeScene();
    CREATE_FUNC(ModeOneSceneOne);

};
#endif /* defined(__ClickC__ModeOneSceneOne__) */
