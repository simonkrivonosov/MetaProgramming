//
//  Reader.h
//
//  Created by Семен Кривоносов on 19/12/2018.
//  Copyright © 2018 Семен Кривоносов. All rights reserved.
//

#ifndef Reader_h
#define Reader_h

#include <fstream>
#include "Typelist.h"

template <typename TList>
void readLineFromStream(char* result, std::ifstream& input) {
    typedef typename TList::Head Type;
    Type value;
    input >> value;
    *((Type*)result) = value;
    result += sizeof(Type);
    readLineFromStream<typename TList::Tail>(result, input);
}

template <>
void readLineFromStream<EmptyList>(char* result, std::ifstream& input) {}

template <typename TList>
class Reader {
public:
    Reader(std::string filename) : input(filename) {}
    ~Reader() {
        input.close();
    }
    void* readNextLine() {
        if (input.eof() or !input.is_open()) {
            return nullptr;
        }
        void* result = std::malloc(SizeOf<TList>::value);
        readLineFromStream<TList>((char*)result, input);
        return result;
    }
private:
    std::ifstream input;
};

#endif /* Reader_h */
