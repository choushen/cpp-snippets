#include <iostream>

using namespace std;


int main() {

    int* num1 = new int(11); // Creating an int somewhere in memory that stores value 11
    int* num2 = num1; // here we are not just passing num1 to num2, we are passing the address of num1 to num2

    *num1 = 22; // here we are changing the value of the memory location that num1 is pointing to

    cout << "===Printing Pointer Integers===" << endl;
    cout << "num1 = " << *num1 << endl;
    cout << "num2 = " << *num2 << endl;

    int num3 = 11;
    int num4 = num3;

    num3 = 22;

    cout << "===Printing Integers===" << endl;
    cout << "num1 = " << num3 << endl;
    cout << "num2 = " << num4 << endl;

    /* 
    * if I delete num1, then num2 will be pointing 
    * to a memory location that has been deleted
    */
    delete num1;
    
    num1 = nullptr; // Optional if num1 is not used afterwards
    num2 = nullptr;
    
    //

    string name = "John";
    string* namePtr = &name;

    cout << "===Printing Pointer Strings===" << endl;
    cout << "name = " << *namePtr << " address = " << &namePtr << endl;
    cout << "name = " << name << " address = " << &name << endl;


    delete namePtr;
    namePtr = nullptr;
    return 0;
}

