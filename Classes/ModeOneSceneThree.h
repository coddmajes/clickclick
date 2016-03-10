//
//  ModeOneSceneThree.h
//  ClickC
//
//  Created by lanqs on 15/6/12.
//
//

#ifndef __ClickC__ModeOneSceneThree__
#define __ClickC__ModeOneSceneThree__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;
class ModeOneSceneThree :public Layer
{
public:
    //限定时间
    int m_limitTime=11;
    //点击次数
    int m_clickNum=0;
    //倒计时判断标注
    int m_limit = 3;
    //文字
    Label  *m_labelTime;
    //随机数的数字
    int m_randomNum=0;
    void setUi();
    bool init();
    static Scene* createScene();
    //4x4游戏按钮
    void btnModeOneCallFunc(Ref *target,int currentNumOne,int x, int y);
    void onExit();
    //时间限制
    void limitTime(float time);
    
    //退出btn回调
    void btnSignOutCallback(Ref *target);
    //暂停btn回调
    bool m_pause=true;
    void btnPauseCallback(Ref *target);
    
    //场景切换
    void changeScene();
    CREATE_FUNC(ModeOneSceneThree);
};
#endif /* defined(__ClickC__ModeOneSceneThree__) */
