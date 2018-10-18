//
//  IPublisher.h
//  MetaProg
//
//  Created by Семен Кривоносов on 18/10/2018.
//  Copyright © 2018 Семен Кривоносов. All rights reserved.
//

#ifndef ISubscriber_h
#define ISubscriber_h
#include <string>

class ISubscriber
{
public:
    void setId(int id) {
        _id = id;
    }
    virtual void update(std::string &) = 0;
    int _id;
};

#endif /* ISubscriber_h */
