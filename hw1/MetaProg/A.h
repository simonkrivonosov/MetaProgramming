//
//  A.h
//  MetaProg
//
//  Created by Семен Кривоносов on 17/10/2018.
//  Copyright © 2018 Семен Кривоносов. All rights reserved.
//

#ifndef A_h
#define A_h

#include <utility>
#include <iostream>
#include "IClient.h"
#include "IComponent.h"
#include "ISubscriber.h"


class A: public IClient, public IComponent, public ISubscriber
{
public:
    A():IComponent() {}
    A(std::string  name):IComponent(name) {
        _name = name;
    }
    A(std::string & name):IComponent(name) {
        _name = name;
    }
    void act() override {
        std::cout << "Some actions of " << _name << " component"<<std::endl;
    }
    void call(std::string & event)
    {
        std::cout << _name << "Component " << " calls Mediator with message: " << event << std::endl;
        if (_mediator != nullptr)
        {
            _mediator->notify(_name, event);
        }
    }
    void call(std::string  event)
    {
        std::cout << _name << "Component " << " calls Mediator with message: " << event << std::endl;
        if (_mediator != nullptr)
        {
            _mediator->notify(_name, event);
        }
    }
    void apply(std::shared_ptr<IService> service) override {
        std::cout << "Client applied to service" << std::endl;
        service->doSomething();
    }
    void update(std::string & event) override {
        //some actions
        std::cout << "Subscriber with id: " << _id << " was updated after notification: "<< event << std::endl;
    }
};

#endif /* A_h */
