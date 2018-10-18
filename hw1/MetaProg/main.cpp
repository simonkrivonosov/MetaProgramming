//
//  main.cpp
//  MetaProg
//
//  Created by Семен Кривоносов on 17/10/2018.
//  Copyright © 2018 Семен Кривоносов. All rights reserved.
//
#include "A.h"
#include "B.h"
#include <iostream>
#include "Proxy.h"
#include "Mediator.h"
#include "IClient.h"
#include "Observer.h"

int main(int argc, const char * argv[]) {
    
//    //Proxy testing
//    std::shared_ptr<A> a(new A());
//    std::shared_ptr<B> b(new B());
//    std::shared_ptr<C<Proxy>> cProxy( new C<Proxy>(std::move(b)));
//    a->apply(cProxy);
//
//    //Mediator testing
//    std::shared_ptr<A> aClient(new A("client"));
//    std::shared_ptr<B> bCheck(new B("check"));
//    std::shared_ptr<B> bfirst(new B("first"));
//    std::shared_ptr<B> bsecond(new B("second"));
//    std::map<std::string, std::shared_ptr<IComponent>> components;
//    components.emplace(bCheck->_name,bCheck);
//    components.emplace(bfirst->_name,bfirst);
//    components.emplace(bsecond->_name,bsecond);
//    std::shared_ptr<C<Mediator>> cMediator(new C<Mediator>(aClient, components));
//    aClient->setMediator(cMediator);
//    bCheck->setMediator(cMediator);
//    aClient->call("Check connection");
//    aClient->call("firstComponent call");
//    bCheck->call("sdf");
    
    

    //Observer testing
    
    std::shared_ptr<A> subscriber1(new A("first"));
    std::shared_ptr<A> subscriber2(new A("second"));
    std::shared_ptr<C<Observer>> manager (new C<Observer>());
    std::shared_ptr<B> editor(new B("editor", "data", manager));
    manager->subscribe(subscriber1, 1);
    manager->subscribe(subscriber2, 2);
    std::string data = "new data";
    editor->edit(data);
    manager->unsubscribe(1);
    editor->edit(data);
    return 0;
}
