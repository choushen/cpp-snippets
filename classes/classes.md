# CPP

## this keyword
- used to refer to variables and methods of the current class
- used to refer to the current object
- used to refer to the current instance of the class


## Initalization list
- It is more efficient than assigning values in the constructor body
- It is the only way to initialize const variables
- It is the only way to initialize reference variables
- It is the only way to initialize variables that do not have a default constructor
- It is the only way to initialize base class constructor

### Constants & References
#### Constants
- Can be passed directly to the constructor

#### References
- Can't initialise it via the constructor directly (the reference), must first create a variable that it will point to

#### Deconstructors
- Must be defined in the same order as the constructors
- The base class deconstructor must be virtual if it's intended to be used polymorphically
- Overriding a base class deconstructor is necessary when freeing dynamically allocated memory that is a member of the derived class

```cpp
#include <iostream>

class A {
    int a;
    int b;
    const int c;
    int &d;
public:
    A(int x, int y, int z, int &w) : a(x), b(y), c(z), d(w) {}
    virtual ~A() {}
};

class B : public A {
    int e;
    int* f;
public: 
    B(int x, int y, int z, int w, int v, int valueOfF) : A(x, y, z, w), e(v) {
        f = new int(valueOfF);
    }
    ~B() {
        delete f; // Free the dynamically allocated memory
    }
};

int main() {
    int x = 4;
    int y = 7;
    A* letterA = new A(1, 2, 3, x);
    B* letterB = new B(4, 5, 6, y, 8, 9);

    delete letterA;
    delete letterB;

    return 0;
}
```


