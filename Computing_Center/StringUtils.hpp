#pragma once
#include <iostream>
#pragma warning (disable : 4996)

inline bool copyString(char*& destination, const char* source)
{
    if (!source || source == destination)
        return false;

    char* newString =
        new(std::nothrow) char[std::strlen(source) + 1];

    if (!newString)
        return false;

    std::strcpy(newString, source);

    delete[] destination;
    destination = newString;

    return true;
}