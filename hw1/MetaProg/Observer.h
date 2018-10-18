//
//  Observer.h
//  MetaProg
//
//  Created by Семен Кривоносов on 17/10/2018.
//  Copyright © 2018 Семен Кривоносов. All rights reserved.
//

#ifndef Observer_h
#define Observer_h

#include <iostream>
#include <memory>
#include <map>
#include <string>
#include "IManager.h"
#include "ISubscriber.h"
#include "C.h"

template <>
class C<Observer>: public IManager {
public:
    void notify(std::string & event) override {
        std::cout << "Manager sent notifications" << std::endl;
        for (auto it=_subscribers.begin(); it != _subscribers.end(); ++it) {
            it->second->update(event);
        }
    }
    void subscribe(std::shared_ptr<ISubscriber> subscriber, int id) override {
        auto res = _subscribers.insert(std::pair<int, std::shared_ptr<ISubscriber>>(id, subscriber));
        subscriber->setId(id);
        if (res.second == false) {
            std::cout << "element with this id is already existed";
            return;
        }
        else
            std::cout << "New subscriber with id "<< id <<" was added"<<std::endl;
    }
    void unsubscribe(int id) override {
        auto search = _subscribers.find(id);
        if (search != _subscribers.end()) {
            _subscribers.erase(search);
            std::cout << "Subscriber with id "<< id <<" was deleted"<<std::endl;
        }
        else {
            std::cout << "No Subscriber with id "<< id <<std::endl;
            return;
        }
    }
private:
    std::map<int,std::shared_ptr<ISubscriber>> _subscribers;
};

#endif /* Observer_h */
