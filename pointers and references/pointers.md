# Pointers
## What is a pointer?
It's a variable that stores the memory address of another variable. It can be used to access and modify the value of the variable it points to. 

Mastering pointers mean you can write more efficient code, and you can work with data structures like linked lists, trees, and graphs.

By pointing to a variable and referencing it instead of creating a new variable, you can save memory and time.

You can visualise it as an arrow pointing to a memory location and saying "the value is here" and "change this value here". If the value is updated in the memory location, the pointer will reflect that change. So if it's referenced in multiple places, you only need to update it once.

Since they allow us to work with memory directly, they can be dangerous if not used correctly. They can cause memory leaks, segmentation faults, and other bugs. Be sure to free memory when you're done with it, and be careful when you're working with pointers:

``` cpp
int main() {

    int* num1 = new int(11); // Creating an int somewhere in memory that stores value 11

    int* num2 = num1; // here we are not just passing num1 to num2, we are passing the address of num1 to num2

    *num1 = 22; // here we are changing the value of the memory location that num1 is pointing to
 
    delete num1; // free memory
    num2 = nullptr; // here we are setting num2 to point to nothing
    return 0;
}
```

If there's a possbility that num1 could be used again, it's good practice to set it to nullptr after deleting it to avoid having a dangling pointer.

num2 is set to nullptr as it pointed to num1, and we don't want it to point to a memory location that no longer exists.

## References and Smart Pointers
### References
References are similar to pointers but once they are initalised, they cannot be reassigned to point to another memory location. 

``` cpp
int main() {
    int num1 = 11;
    int& num2 = num1; // num2 is a reference to num1 and cannot reference any other variable as it's been initalised with num1

    num2 = 22; // num1 is now 22

    return 0;
}
```

### Smart Pointers
In a nutshell, smart pointers automatically manage memory so they are safer than raw pointers. However, they are not a replacement for raw pointers.

There are three types of smart pointers:
- `std::unique_ptr` - can't be copied, but can be moved
- `std::shared_ptr` - can be copied and shared
- `std::weak_ptr` - can't be copied, but can be shared

``` cpp 
#include <memory>

int main() {
    std::unique_ptr<int> num1(new int(11)); // Creating an int somewhere in memory that stores value 11

    std::unique_ptr<int> num2 = std::move(num1); // Moving num1 to num2

    *num2 = 22; // here we are changing the value of the memory location that num2 is pointing to

    return 0;
}
```
