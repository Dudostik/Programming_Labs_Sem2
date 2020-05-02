#ifndef UNTITLED2_INTERFACE_H
#define UNTITLED2_INTERFACE_H


class InterfaceGeoFig
{
public:
// Square
    [[nodiscard]] virtual double square() const = 0;
// Perimeter
    [[nodiscard]] virtual double perimeter() const = 0;
};


class InterfacePhysObject
{
public:
// Mass. kg
    [[nodiscard]] virtual double mass() const = 0;
// Position. m
    [[nodiscard]] virtual Point position() const = 0;
// Weight comparison
    virtual bool operator==(const InterfacePhysObject &ob) const = 0;
// Weight comparison
    virtual bool operator<(const InterfacePhysObject &ob) const = 0;
};


class InterfacePrintable
{
public:
// Display on the screen
// (Display in text form the parameters of the figure).
    virtual void draw() const = 0;
};


class InterfaceDialogInitiable
{
// Set your object settings with a conversation with the user
public:
    virtual void initFromDialog() = 0;
};


class BaseObject
{
public:
// Class name (data type)
    [[nodiscard]] virtual const char *classname() const = 0;
// The size of the memory occupied
    [[nodiscard]] virtual unsigned int size() const = 0;
};


#endif //UNTITLED2_INTERFACE_H
