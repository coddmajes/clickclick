//
//  ModeOneSceneTwo.h
//  ClickC
//
//  Created by lanqs on 15/6/12.
//
//

#ifndef __ClickC__ModeOneSceneTwo__
#define __ClickC__ModeOneSceneTwo__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;
class ModeOneSceneTwo :public Layer
{
public:
    int m_randomNum=0;
    //限定时间
    int m_limitTime=9;
    //点击次数
    int m_clickNum=0;
    //倒计时判断标注
    int m_limit = 3;
    //文字
    Label  *m_labelTime;
    void setUi();
    bool init();
    static Scene* createScene();
    //3x3游戏按钮
    void btnModeOneCallFunc(Ref *target,int currentNumOne,int x, int y);
    //时间限制
    void limitTime(float time);
    
    //退出btn回调
    void btnSignOutCallback(Ref *target);
    //暂停btn回调
    bool m_pause=true;
    void btnPauseCallback(Ref *target);
    void onExit();
    //场景切换
    void changeScene();
    CREATE_FUNC(ModeOneSceneTwo);
    
};
#endif /* defined(__ClickC__ModeOneSceneTwo__) */
