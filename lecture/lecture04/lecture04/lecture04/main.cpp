#include <string>
#include <iostream>
using namespace std;

 


// DRY principle: Don't Repeat Yourself

 

// CLASS  - user-defined data type with data members (attributes) and member functions (methods)
// Class = fruit, objects (instances) - apple, banana, orange

 

// OBJECT - identifiable entity, instance of the Class

 

// 2 possibilities for defining a class (important for Final Project!)

 

 

//Second (prefered) in big projects and distributed projects, must be used in Final Projects
// separated definition: HEADERS (.h)+IMPLEMENTATION(.cpp)

 

// OO Concepts:
// 1) Encapsulation: data (properties, attributes) and functions (methods) are included to a single unit (class)
// 2) Data Hiding (Information Hiding)
// 3) Polymorphism and Inheritance

 


// Visibility modifiers:
// public: from "anywhere"
// private: only from the methods of the actual class, NOT from outside
// protected: (used with inheritance) only from the methods of the actual class + from the inherited classes

 

// Class is responsible for itself: the state of the object always remains consistent
class Point
{
    int x;
    int y;
public:
    void init() { x = 0; y = 0; }
    void setX(int nx)
    {
        if (nx < 0 || nx>1024)
        {
            // show error
        }
        else
            x = nx;
    }
    void setY(int ny)
    {
        if (ny < 0 || ny>768)
        {
            // show error
        }
        else
            y = ny;
    }
    void draw()
    {
        // ......
    }
    void moveRight()
    {
        x++;
    }
    // Function overloading helps!
    //Point() { x = 0; y = 0; }  ---> Default
    //Point(int px, int py) { x = px; y = py; }
    //Point(int px) { x = px; y = 0; }   -----> Conversion constructor

 

    // Constructor
    /*Point(int px = 0, int py = 0) { x = px; y = py; }*/

 

    // Initialization list
    Point(int px = 0, int py = 0): x(px), y(py) {}

 

    // Default constructor
    //Point() {}

 

    // Default destructor
    ~Point() {}

 

    // Copy constructor
    Point(const Point& other)
    {
        x = other.x;
        y = other.y;
    }

 

    // Default copy constructor: copies everything bit-by-bit
};

 

 

int main()
{
    // I/O in C++: performed in a sequence of bytes, called streams
    // - input: from KB to MEM  (input stream)
    // - output: from MEM to display, monitor, etc. (output stream)

 
    // input: cin
    // output: cout, cerr, clog

 

    char courseName[] = "BoP";
    int courseNumber = 2;
    cout << "I like " << courseName << courseNumber << endl << endl;
    // New line (CR LF) in C: "\n"                        \n\n
    // C++ << endl;

 

    cerr << "Error happened!"; // (on the screen)

 

    // cout: normal output stream to display  (printf)
    // cerr: error messages
    // clog: Logging messages

 

    clog << "Somebody logged on to the program"; // now: it is the screen

 

    cout << "Enter an int and a double number please" << endl;
    int a; double b;
    //cin >> a;   //scanf: format %d, %lf   --- no more!
    //cin >> b;

 

    cin >> a >> b;

 

    cout << "What you have entered is: " << a << b << endl;

 

 

    //Point A;
    //Point B(30, 70);
    //Point C(50);  // This must result in (50;0) point
    //Point D = 70; // same as Point F(70), same as Point D(70,0)

 

    //Point E = B;  // Need a copy constructor!
    //// B(-10;-100), E(30,70)

 


    //// inconsistent!! (useless)
    //// Solution: constructor!

 

    //int x;  // Declaration
    //x = 2;  // Value assignment (operator=)

 

    //int& rx = x;  // rx is a reference variable (alias) to x

 

 

    //int y = 2;   // Definition: constructor call
    //int z(2);
    //
    //A.draw();

 

    return 0;
}
