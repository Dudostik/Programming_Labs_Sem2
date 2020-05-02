#ifndef UNTITLED2_BASE_CLASS_H
#define UNTITLED2_BASE_CLASS_H

#include "vector2d.h"

class BaseClass: public BaseObject, public InterfaceGeoFig, public Vector2D, public InterfaceDialogInitiable,
                 public InterfacePrintable, public InterfacePhysObject
{
public:
    virtual ~BaseClass() = default;
};

#endif //UNTITLED2_BASE_CLASS_H
