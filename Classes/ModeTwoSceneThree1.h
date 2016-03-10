//
//  ModeTwoSceneThree1.h
//  ClickC
//
//  Created by lanqs on 15/6/15.
//
//

#ifndef __ClickC__ModeTwoSceneThree1__
#define __ClickC__ModeTwoSceneThree1__

#include "ui/CocosGUI.h"
#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;
using namespace ui;
class ModeTwoSceneThree1 :public LayerColor
{
public:
    //得到计算结果
    int m_resultsOne = 0;
    int m_resultsTwo = 0;
    
    //得到一个比对标准
    int m_tag;
    
    int m_maxBtn = 0;
    //限定时间
    int m_limitTime=65;
    //点击次数
    int m_clickNum=0;
    //倒计时判断标注
    int m_limit = 3;
    //文字
    Label  *m_labelTime;
    void setUi();
    bool init();
    static Scene* createScene();
    //时间限制
    void limitTime(float time);
    //button
    Button  *button;
    
    //退出btn回调
    void btnSignOutCallback(Ref *target);
    //暂停btn回调
    bool m_pause=true;
    void btnPauseCallback(Ref *target);
    
    //labelScore
    Label *m_labelScore;
    //算法
    void btnWay();
    //按钮点击回调
    void btnModeTwoCallFunc(Ref *target,int tag,int i, int j);
    //场景切换
    void changeScene();
    
    //gameover btn
    void btnGameHomeCallback(Ref *target);
    void btnGameAgainCallback(Ref *target);
    CREATE_FUNC(ModeTwoSceneThree1);
    
};

#endif /* defined(__ClickC__ModeTwoSceneThree1__) */
