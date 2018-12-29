//
//  type_list.h
//  bonus_task4
//
//  Created by Семен Кривоносов on 29/12/2018.
//  Copyright © 2018 Семен Кривоносов. All rights reserved.
//

#ifndef typelist_h
#define typelist_h

struct NullType {};

template <typename ...Args>
struct TypeList {
    using Head = NullType;
    using Tail = NullType;
};

typedef TypeList<> EmptyList;

template <typename H, typename ...T>
struct TypeList<H, T...> {
    using Head = H;
    using Tail = TypeList<T...>;
};


template <typename TList> struct Length;

template <>
struct Length<EmptyList> {
    enum { value = 0 };
};

template <typename H, typename ...T>
struct Length<TypeList<H, T...>> {
    enum {value = 1 + Length<TypeList<T...>>::value};
};

template <typename TList, typename T> struct EraseFirst;

template <typename T>
struct EraseFirst<EmptyList, T> {
    using Result = EmptyList;
};

template <typename ...Tail, typename T>
struct EraseFirst<TypeList<T, Tail...>, T> {
    using Result = TypeList<Tail...>;
};

template <typename Head, typename ...Tail, typename T>
struct EraseFirst<TypeList<Head, Tail...>, T> {
    using Result = TypeList<Head, EraseFirst<TypeList<Tail...>, T>>;
};

template <typename TList>
struct SizeOf;

template <>
struct SizeOf<EmptyList> {
    static const int value = 0;
};

template <typename Head, typename ...Tail>
struct SizeOf<TypeList<Head, Tail...>> {
    static const int value = sizeof(Head) + SizeOf<TypeList<Tail...>>::value;
};

#endif /* typelist_h */
