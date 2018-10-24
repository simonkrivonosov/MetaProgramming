//
//  main.cpp
//  MetaProgTest
//
//  Created by Семен Кривоносов on 24/10/2018.
//  Copyright © 2018 Семен Кривоносов. All rights reserved.
//
#include <iostream>

struct NullType {};

template <typename T, typename U>
struct TypeList {
    using head = T;
    using tail = U;
};

template <typename...> struct MakeTypeList;

template <>
struct MakeTypeList<> {
    using result = NullType;
};

template <typename T, typename... U>
struct MakeTypeList<T, U ...> {
    using result = TypeList<T, typename MakeTypeList<U ...>::result>;
};

template <typename> struct Length;

template <>
struct Length<NullType> {
    enum { value = 0 };
};

template <typename T, typename U>
struct Length<TypeList<T, U>> {
    enum { value = Length<U>::value + 1 };
};

int main() {
    using Types = typename MakeTypeList<>::result;
    using Types1 = typename MakeTypeList<char>::result;
    std::cout << Length<Types>::value << std::endl;
    std::cout << Length<Types1>::value << std::endl;
}
