//
//  Mediator.h
//  MetaProg
//
//  Created by Семен Кривоносов on 17/10/2018.
//  Copyright © 2018 Семен Кривоносов. All rights reserved.
//

#ifndef Mediator_h
#define Mediator_h
#include <cstring>
#include "IMediator.h"
#include <iostream>
#include <memory>
#include <string>
#include "IComponent.h"
#include "IMediator.h"
#include "C.h"
#include <map>

template <>
class C<Mediator>: public IMediator {
public:
    C(std::shared_ptr<IComponent> a, std::map<std::string, std::shared_ptr<IComponent>>& components)
    {
        _a = a;
        _components = std::move(components);
        
    }
    void notify(std::string & sender, std::string & event) override {
        if (sender == _a->_name) {
            std::cout << "Mediator was notified from Client A with message : "<< event <<  std::endl;
            if (event == "Check connection")
                _components["check"]->act();
            else if (event == "firstComponent call") {
               _components["first"]->act();
            }
            // and so on
            else {
                //some other actions for different events inserts here ...
                std::cout<<"some other actions"<<std::endl;
                return;
            }
        }
        else {
            std::cout << "Mediator was notified from " << sender << "with message: " << event << std::endl;
            std::cout << "some actions"<< std::endl;
            //sone actions
            return;
        }
    }
private:
    std::shared_ptr<IComponent> _a;  // (Client A in task description)
    std::map<std::string, std::shared_ptr<IComponent>> _components; // other possible notifiers
};

#endif /* Mediator_h */
