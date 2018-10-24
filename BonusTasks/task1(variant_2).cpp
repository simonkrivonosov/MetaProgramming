
//  main.cpp
//  MetaProgrammingBonus

//  Created by Семен Кривоносов on 24/10/2018.
//  Copyright © 2018 Семен Кривоносов. All rights reserved.
#include <iostream>

class NullType {};

template<typename T=NullType, typename ... U>
struct TypeList {
    using head = T;
    using tail = TypeList<U ...>;
};
template<typename T>
struct TypeList<T> {
    using head = T;
    using tail = NullType;
};

template <typename TypeList>
struct Length {
    enum { value = Length<typename TypeList::tail>::value + 1 };
};
template <>
struct Length<NullType> {
    enum { value = 0 };
};
template <>
struct Length<TypeList<>> {
    enum { value = 0 };
};

int main(int argc, const char * argv[]) {
    using EmptyList = TypeList<>;
    std::cout << Length<EmptyList>::value << std::endl;
    return 0;
}
