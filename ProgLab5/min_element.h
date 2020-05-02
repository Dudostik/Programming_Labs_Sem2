#ifndef PROGLAB5_MIN_ELEMENT_H
#define PROGLAB5_MIN_ELEMENT_H


template <typename T>
T MinElement(T a, T b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}


#endif //PROGLAB5_MIN_ELEMENT_H
