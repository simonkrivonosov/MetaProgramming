//
//  IComponent.h
//  MetaProg
//
//  Created by Семен Кривоносов on 18/10/2018.
//  Copyright © 2018 Семен Кривоносов. All rights reserved.
//

#ifndef IComponent_h
#define IComponent_h

#include <utility>
#include "IMediator.h"


class IComponent {
public:
    std::string _name;
    IComponent() {
        _name = "Component";
    }
    IComponent(std::string & name):_name (name)
    {}
    void setMediator(std::shared_ptr<IMediator> mediator) {
        _mediator = mediator;
    }
    virtual void act() = 0;
protected:
    std::shared_ptr<IMediator> _mediator;
};

#endif /* IComponent_h */
