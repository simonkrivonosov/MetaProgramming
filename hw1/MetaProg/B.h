//
//  B.h
//  MetaProg
//
//  Created by Семен Кривоносов on 17/10/2018.
//  Copyright © 2018 Семен Кривоносов. All rights reserved.
//

#ifndef B_h
#define B_h

#include <utility>
#include <iostream>
#include "IService.h"
#include "IComponent.h"
#include "IEditor.h"


class B: public IService, public IComponent, public IEditor
{
public:
    //B():IComponent() {}
    B(std::string name = "component",std::string  data = "data", std::shared_ptr<IManager> observer= nullptr):IComponent(name), IEditor(data, observer) {
    }
//    B(std::string & name):IComponent(name) {
//        _name = name;
//    }
    void doSomething() override {
        std::cout << "Service received the request" << std::endl;
    }
    void act() override {
        std::cout << "Some actions of "<< _name <<"Component" << std::endl;
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
    void edit(std::string & data) override{
        _data = data;
        std::cout << "data of Editor was changed with " << data << std::endl;
        _observer->notify(data);
    }
};

#endif /* B_h */
