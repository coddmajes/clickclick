//
//  SetScene.h
//  ClickC
//
//  Created by lanqs on 15/6/10.
//
//

#ifndef __ClickC__SetScene__
#define __ClickC__SetScene__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;
class SetScene :public LayerColor
{
private:
    bool init();
    void setUi();
public:
    int m_tag=0;
    //按钮关闭和继续
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event  *unused_envent);
    void btnSetCallFunc(Ref *target,int tag);
    void btnSignOutCallFunc(Ref *target);
    void onEnterTransitionDidFinish();
    CREATE_FUNC(SetScene);

};
#endif /* defined(__ClickC__SetScene__) */



