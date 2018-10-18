//
//  Client.h
//  MetaProg
//
//  Created by Семен Кривоносов on 17/10/2018.
//  Copyright © 2018 Семен Кривоносов. All rights reserved.
//

#ifndef IClient_h
#define IClient_h
#include "IService.h"
#include <memory>

class IClient {
public:
    virtual void apply(std::shared_ptr<IService>) = 0;
};

#endif /* IClient_h */
