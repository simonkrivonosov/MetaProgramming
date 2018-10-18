//
//  IManager.h
//  MetaProg
//
//  Created by Семен Кривоносов on 18/10/2018.
//  Copyright © 2018 Семен Кривоносов. All rights reserved.
//

#ifndef IManager_h
#define IManager_h
#include <string>
#include "ISubscriber.h"


class IManager
{
public:
    virtual void notify(std::string & event) = 0;
    virtual void subscribe(std::shared_ptr<ISubscriber>, int) = 0;
    virtual void unsubscribe(int) = 0;
};

#endif /* IManager_h */
