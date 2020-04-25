#ifndef PROGLAB5_MINELEMENT_H
#define PROGLAB5_MINELEMENT_H

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

#endif //PROGLAB5_MINELEMENT_H
