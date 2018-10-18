//
//  IEditor.h
//  MetaProg
//
//  Created by Семен Кривоносов on 18/10/2018.
//  Copyright © 2018 Семен Кривоносов. All rights reserved.
//

#ifndef IEditor_h
#define IEditor_h
#include <memory>
#include <string>
#include "IManager.h"
#include <utility>

class IEditor {
public:
    IEditor(std::string & data, std::shared_ptr<IManager> observer): _data(data), _observer(observer)
    {}
    virtual void edit(std::string &) = 0;
protected:
    std::shared_ptr<IManager> _observer;
    std::string _data;
};

#endif /* IEditor_h */
