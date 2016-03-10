//
//  ModeThreeScene.h
//  ClickC
//
//  Created by lanqs on 15/6/11.
//
//

#ifndef __ClickC__ModeThreeScene__
#define __ClickC__ModeThreeScene__

#include "ui/CocosGUI.h"
#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;
using namespace ui;
class ModeThreeScene :public LayerColor
{
public:

    int m_tag=0;
    int m_tag1;
    int m_tag2;
    //点击次数
    int m_clickNum=0;
    //倒计时判断标注
    int m_limit = 3;
    //文字
    Label  *m_labelTime;
    void setUi();
    bool init();
    static Scene* createScene();
    //限定时间
    int m_limitTime=7;
    //button
    Button  *button;
    
    //退出btn回调
    void btnSignOutCallback(Ref *target);
    //暂停btn回调
    bool m_pause=true;
    void btnPauseCallback(Ref *target);
    
    //算法
    void btnWay();
    //按钮点击回调
    void btnModeThreeCallFunc(Ref *target,int currentNumOne,int tag,int x, int y);
    //场景切换
    void changeScene();
    void limitTime1();
    //时间限制
    void limitTime2(float time);
    CREATE_FUNC(ModeThreeScene);
    
};
#endif /* defined(__ClickC__ModeThreeScene__) */
