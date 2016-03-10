//
//  Help.h
//  ClickC
//
//  Created by lanqs on 15/6/15.
//
//

#ifndef __ClickC__Help__
#define __ClickC__Help__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;
class Help :public LayerColor
{
public:
    bool init();
    void setUi();
    static Scene* createScene();
    void btnSignOutCallFunc(Ref *target);
    CREATE_FUNC(Help);
};
#endif /* defined(__ClickC__Help__) */
