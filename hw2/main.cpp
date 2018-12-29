//
//  main.cpp
//  task2
//
//  Created by Семен Кривоносов on 28/12/2018.
//  Copyright © 2018 Семен Кривоносов. All rights reserved.
//

#include "typelist.h"
#include <iostream>
#include <vector>
#include <list>


template <typename T, class Derive> struct Unit;

template <typename T, class Derive>
struct Unit : public Derive {
    T* value;
};

template <unsigned i>
struct FibonacciNumber {
    enum { value = FibonacciNumber<i-1>::value + FibonacciNumber<i-2>::value };
};

template <>
struct FibonacciNumber<0> {
    enum { value = 1 };
};

template <>
struct FibonacciNumber<1> {
    enum { value = 1 };
};

template <typename TList, template <typename Base, typename Derive> class Unit> struct GenLinearHierarchy;

template <typename Head, typename ...Tail, template <typename Base, typename Derive> class Unit>
struct GenLinearHierarchy<TypeList<Head, Tail...>, Unit> : public Unit<Head, GenLinearHierarchy<TypeList<Tail...>, Unit>> {};

template <template <typename Base, typename Derive> class Unit>
struct GenLinearHierarchy<EmptyList, Unit> : public Unit<NullType, NullType> {};

template <typename TList, typename AccTList, unsigned i, unsigned acc_size, unsigned requested_size, template <typename Base, typename Derive> class Unit>
struct GenInnerFibonacciHierarchy;

template <typename Head, typename ...Tail,
typename ...AccTail,
unsigned i, unsigned acc_size, unsigned requested_size,
template <typename Base, typename Derive> class Unit>
struct GenInnerFibonacciHierarchy<TypeList<Head, Tail...>, TypeList<AccTail...>,
i, acc_size, requested_size, Unit> : public GenInnerFibonacciHierarchy<TypeList<Tail...>, TypeList<Head, AccTail...>,
i, acc_size+1, requested_size, Unit> {};

template <typename Head, typename ...Tail,
typename ...AccTail,
unsigned i, unsigned requested_size,
template <typename Base, typename Derive> class Unit>
struct GenInnerFibonacciHierarchy<TypeList<Head, Tail...>, TypeList<AccTail...>,
i, requested_size, requested_size, Unit>
: public GenLinearHierarchy<TypeList<AccTail...>, Unit>,
public GenInnerFibonacciHierarchy<TypeList<Head, Tail...>, EmptyList,
i+1, 0, FibonacciNumber<i+1>::value+1, Unit> {};

template <typename ...AccTail,
unsigned i, unsigned acc_size, unsigned requested_size,
template <typename Base, typename Derive> class Unit>
struct GenInnerFibonacciHierarchy<EmptyList, TypeList<AccTail...>,
i, acc_size, requested_size, Unit> : public GenLinearHierarchy<TypeList<AccTail...>, Unit> {};

template <typename ...AccTail,
unsigned i, unsigned requested_size,
template <typename Base, typename Derive> class Unit>
struct GenInnerFibonacciHierarchy<EmptyList, TypeList<AccTail...>,
i, requested_size, requested_size, Unit> : public GenLinearHierarchy<TypeList<AccTail...>, Unit> {};

template <typename TList, template <typename Base, typename Derive> class Unit>
struct GenFibonacciHierarchy : public GenInnerFibonacciHierarchy<TList, EmptyList, 0, 0, FibonacciNumber<0>::value+1, Unit> {};

int main(int argc, const char * argv[]) {
    using Hierarchy = GenFibonacciHierarchy<TypeList<int, double, float, char, bool,
    std::vector<int>, std::vector<double>, std::vector<float>, std::vector<char>, std::vector<bool>,
    std::list<int>, std::list<double>, std::list<float>, std::list<char>, std::list<bool>>, Unit>;
    
    std::cout << FibonacciNumber<5>::value << std::endl;
    
    return 0;
}
