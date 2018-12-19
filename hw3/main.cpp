//
//  main.cpp
//  task3
//
//  Created by Семен Кривоносов on 19/12/2018.
//  Copyright © 2018 Семен Кривоносов. All rights reserved.
//
#include <iostream>
#include <string>
#include <fstream>
#include "Reader.h"
#include "Typelist.h"

template <typename TList>
void print(char* result) {
    typedef typename TList::Head Type;
    std::cout << *((Type*)result) << " ";
    result += sizeof(Type);
    print<typename TList::Tail>(result);
}

template <>
void print<EmptyList>(char* result) {
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {
    typedef TypeList<int, double, std::string> TList;
    Reader<TList> reader("/Users/simon/Desktop/input.txt");
    
    void* result = reader.readNextLine();
    while (result != nullptr) {
        print<TList>((char*)result);
        result = reader.readNextLine();
    }
    
    std::free(result);

    std::cout << std::endl;
    
    return 0;
}

