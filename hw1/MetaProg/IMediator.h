//
//  IMediator.h
//  MetaProg
//
//  Created by Семен Кривоносов on 18/10/2018.
//  Copyright © 2018 Семен Кривоносов. All rights reserved.
//

#ifndef IMediator_h
#define IMediator_h
#include <memory>
#include <string>


class IMediator {
public:
    virtual void notify(std::string & sender, std::string & event) = 0;
};

#endif /* IMediator_h */
