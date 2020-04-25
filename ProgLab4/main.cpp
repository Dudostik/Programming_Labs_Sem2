#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


class Point
{
public:
    double x, y;
    void InitFromDialog()
    {
        cin >> x >> y;
    }

    [[nodiscard]] double distance_to_point(Point A) const
    {
        return sqrt((x - A.x) * (x - A.x) + (y - A.y) * (y - A.y));
    }

    void print() const
    {
        cout << "(" << x << "; " << y << ")" << endl;
    }
};


class Vector2D
{
public:
    Point X, Y;
    [[nodiscard]] Point center() const
    {
        return {(X.x + Y.x) / 2.0, (X.y + Y.y) / 2.0};
    }

    [[nodiscard]] double length() const
    {
        return X.distance_to_point(Y);
    }

    void print() const
    {
        cout << "First point coordinates:";
        X.print();
        cout << "Second point coordinates:";
        Y.print();
    }
};


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


// Interface "Class"
class BaseObject
{
public:
// Class name (data type)
    [[nodiscard]] virtual const char *classname() const = 0;
// The size of the memory occupied
    [[nodiscard]] virtual unsigned int size() const = 0;
};


class BaseClass: public BaseObject, public InterfaceGeoFig, public Vector2D, public InterfaceDialogInitiable,
                 public InterfacePrintable, public InterfacePhysObject
{
public:
    virtual ~BaseClass() = default;
};


class EquilateralTriangle: public BaseClass
{
public:
    ~EquilateralTriangle() override = default;

    Point center{0, 0};
    double length = 0;

    [[nodiscard]] double square() const override
    {
        return (length * sqrt((3 * pow(length,2))/4))/2;
    }

    [[nodiscard]] double perimeter() const override
    {
        return 3 * length;
    }

    void draw() const override
    {
        cout << "Triangle center: ";
        center.print();
        cout << "The length of the base: " << length << endl;
    }

    [[nodiscard]] const char *classname() const override
    {
        return "EquilateralTriangle";
    }

    [[nodiscard]] unsigned int size() const override
    {
        return sizeof(*this);
    }

    void initFromDialog() override
    {
        cout << "Initialization" << endl;
        cout << "Enter the coordinates of the center point through the gaps:";
        center.InitFromDialog();
        cout << "Enter the length of the triangle edge: ";
        cin >> length;
    }

    [[nodiscard]] double mass() const override
    {
        return square();
    }

    [[nodiscard]] Point position() const override
    {
        return center;
    }

    bool operator==(const InterfacePhysObject &ob) const override
    {
        return this->mass() == ob.mass();
    }

    bool operator<(const InterfacePhysObject &ob) const override
    {
        return this->mass() < ob.mass();
    }
};


class Parallelogram: public BaseClass
{
public:
    ~Parallelogram() override = default;

    // Let the parallelogram set through two co-directed vectors denoting its foundations
    Vector2D a{{0, 0}, {0, 0}};
    Vector2D b{{0, 0}, {0, 0}};

    [[nodiscard]] double square() const override
    {
        return a.center().distance_to_point(b.center()) * a.length();
    }

    [[nodiscard]] double perimeter() const override
    {
        return a.length() + b.length() + a.X.distance_to_point(b.X) + a.Y.distance_to_point(b.Y);
    }

    void draw() const override
    {
        cout << "The first base of the parallelogram" << endl;
        a.print();
        cout << "\nThe second base of the parallelogram" << endl;
        b.print();
    }

    [[nodiscard]] const char *classname() const override
    {
        return "Parallelogram";
    }

    [[nodiscard]] unsigned int size() const override
    {
        return sizeof(*this);
    }

    void initFromDialog() override
    {
        cout << "Initialization" << endl;
        cout << "The first base of the parallelogram" << endl;
        cout << "Enter the coordinates of the first point through the space:";
        a.X.InitFromDialog();

        cout << "Enter the coordinates of the second point through the space: ";
        a.Y.InitFromDialog();

        cout << "\nThe second base of the parallelogram" << endl;
        cout << "Enter the coordinates of the first point through the space:";
        b.X.InitFromDialog();

        cout << "Enter the coordinates of the second point through the space: ";
        b.Y.InitFromDialog();
    }

    [[nodiscard]] double mass() const override
    {
        return square();
    }

    [[nodiscard]] Point position() const override
    {
        Vector2D temp{a.X, b.Y};
        return temp.center();
    }

    bool operator==(const InterfacePhysObject &ob) const override
    {
        return this->mass() == ob.mass();
    }

    bool operator<(const InterfacePhysObject &ob) const override
    {
        return this->mass() < ob.mass();
    }
};


int main()
{
    // Keeping multiple shapes
    vector<BaseClass*> geoObjects;

    cout << "Enter the number of objects stored: ";
    int k;
    cin >> k;
    if (k <= 0) return 0;

    // Adding by user through a console
    for (int i = 0; i < k; ++i)
    {
        int type;
        cout << "\nObject types: " << endl;
        cout << "1: EquilateralTriangle" << endl;
        cout << "2: Parallelogram" << endl;
        do
        {
            cout << "Enter the type of object: ";
            cin >> type;
        }

        while (!(type == 1 || type == 2));

        if (type == 1)
            geoObjects.push_back(new EquilateralTriangle);
        else
            geoObjects.push_back(new Parallelogram);

        geoObjects.back()->initFromDialog();
    }

    cout << "\nReflection of all the shapes:" << endl;
    // Reflection of all the shapes
    int count = 1;
    for (auto i : geoObjects)
    {
        cout << count++ << "): " << i->classname() << endl;
        i->draw();
        cout << endl;
    }

    // Sum area of all figures
    cout << "\nSum area of all figures: ";
    double s = 0;
    for (auto i : geoObjects)
    {
        s += i->square();
    }
    cout << s << endl;


    // Sum perimeter of all figures
    cout << "Sum perimeter of all figures: ";
    s = 0;
    for (auto i : geoObjects)
    {
        s += i->perimeter();
    }
    cout << s << endl;

    // Memory occupied by all instances of classes
    cout << "Memory occupied by all instances of classes: ";
    unsigned int r = 0;
    for (auto i : geoObjects)
    {
        r += i->size();
    }
    cout << r << endl;

    // Object centres
    cout << "\nObject centres:" << endl;
    count = 0;
    for (auto i : geoObjects)
    {
        cout << ++count << ":" << endl;
        i->position().print();
    }

    // Removing and releasing memory
    for (auto &geoObject: geoObjects)
    {
        delete geoObject;
    }
    return 0;
}