//
//  main.cpp
//  bonus_task4
//
//  Created by Семен Кривоносов on 29/12/2018.
//  Copyright © 2018 Семен Кривоносов. All rights reserved.
//

#include <type_traits>
#include <typeinfo>
#include <iostream>
#include "type_list.h"

template <class TList, template <class> class Unit>
struct GenScatterHierarchy;

template <class T1, class... T2, template <class> class Unit>
struct GenScatterHierarchy<TypeList<T1, T2...>, Unit>: public GenScatterHierarchy<T1, Unit>, public GenScatterHierarchy<TypeList<T2...>, Unit> {
public:
    using TList = TypeList<T1, T2...>;
    using LeftBase = GenScatterHierarchy<T1, Unit>;
    using RightBase = GenScatterHierarchy<TypeList<T2...>, Unit>;
};

template <class AtomicType, template <class> class Unit>
struct GenScatterHierarchy: public Unit<AtomicType> {
public:
    using LeftBase = Unit<AtomicType>;
};

template <template <class> class Unit>
struct GenScatterHierarchy<NullType, Unit> {};

template<class T>
struct Holder {
    T value_;
};

template<class T, template<class> class Unit, class TList>
Unit<T>& Field(GenScatterHierarchy<TList, Unit>& obj) {
    return obj;
}

using WidgetInfo = GenScatterHierarchy<TypeList<int, std::string, double>, Holder>;

int main() {
    WidgetInfo obj;
    static_cast<Holder<int>&>(obj).value_ = 10;
    static_cast<Holder<std::string>&>(obj).value_ = "loko";
    std::cout << Field<int>(obj).value_<< std::endl;
    std::cout << Field<std::string>(obj).value_<< std::endl;
    return 0;
}
