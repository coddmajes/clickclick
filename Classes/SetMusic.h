//
//  SetMusic.h
//  ClickC
//
//  Created by lanqs on 15/6/15.
//
//

#ifndef __ClickC__SetMusic__
#define __ClickC__SetMusic__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;
class SetMusic :public LayerColor
{
private:
    bool init();
    void setUi();
public:
    int m_tag=0;
    //按钮关闭和继续
    void btnSignOutCallFunc(Ref *target);
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event  *unused_envent);
    void btnIncrease1(cocos2d::Ref*);
    void btnDecrease1(cocos2d::Ref*);
    void btnIncrease2(cocos2d::Ref*);
    void btnDecrease2(cocos2d::Ref*);
    
    int m_volume=50;
    int m_volume1=50;
    
    Sprite *m_sprite1;
    Sprite *m_sprite2;
    
    int m_spriteWidth1;
    int m_spriteHeigh1;
    
    int m_spriteWidth2;
    int m_spriteHeigh2;
    CREATE_FUNC(SetMusic);
};
#endif /* defined(__ClickC__SetMusic__) */
