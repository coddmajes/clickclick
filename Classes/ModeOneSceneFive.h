//
//  ModeOneSceneFive.h
//  ClickC
//
//  Created by lanqs on 15/6/12.
//
//

#ifndef __ClickC__ModeOneSceneFive__
#define __ClickC__ModeOneSceneFive__
#include "ui/CocosGUI.h"
#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;
using namespace ui;
class ModeOneSceneFive :public Layer
{
public:
    //限定时间
    int m_limitTime=8;
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
    
    //时间限制
    void limitTime(float time);
    
    //场景切换
    void changeScene();
    CREATE_FUNC(ModeOneSceneFive);
};
#endif /* defined(__ClickC__ModeOneSceneFive__) */
