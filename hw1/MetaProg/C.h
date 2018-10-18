//
//  C.h
//  MetaProg
//
//  Created by Семен Кривоносов on 17/10/2018.
//  Copyright © 2018 Семен Кривоносов. All rights reserved.
//

#ifndef C_h
#define C_h

enum Pattern {
    Proxy,
    Mediator,
    Observer
};


template <Pattern> class C;

#endif /* C_h */
