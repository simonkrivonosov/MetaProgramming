//
//  Proxy.h
//  MetaProg
//
//  Created by Семен Кривоносов on 17/10/2018.
//  Copyright © 2018 Семен Кривоносов. All rights reserved.
//

#ifndef Proxy_h
#define Proxy_h
#include "C.h"
#include "IService.h"
#include <iostream>
#include <memory>

template<>
class C<Proxy>:public IService {
public:
    C(std::shared_ptr<IService> service) {
        _service = service;
    }
    void doSomething() override {
        //some actions here...and after
        std::cout<<"Proxy: transfering request to the service"<<std::endl;
        _service->doSomething();
        //some actions
    }
private:
    std::shared_ptr<IService> _service;
};

#endif /* Proxy_h */
