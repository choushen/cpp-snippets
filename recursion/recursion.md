# Recursion
## What is recursion?

"Before you understand recursion, you must first understand recursion."

It's useful for sorting and searching algorithms, and for solving problems that can be broken down into smaller, similar problems. It's a way of solving problems by defining a function that calls itself. However, it's not always the best solution, as it can be less efficient than an iterative solution and it tends use more memory because each recursive call adds a new layer to the call stack.

## How does recursion work?

If we have a function for factorial, it might look like this:
```cpp
int factorial(int n) 
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}
```

When we call `factorial(3)`, the function will call itself with `n=2`, then `n=1`, then `n=0`. When `n=0`, the function will return 1, and then the function will return 1 * 1 = 1, then 2 * 1 = 2, then 3 * 2 = 6.

The stack looks like this:
```
factorial(3) // returns 3 * 2
factorial(2) // returns 2 * 1
factorial(1) // returns 1 * 1
factorial(0) // returns 1
```

You can imagine it goes going down the stack, and then back up the stack, returning values and performing operations as it goes until it reaches the top of the stack.