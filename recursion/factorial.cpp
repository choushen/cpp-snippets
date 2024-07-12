#include <iostream>

using namespace std;

int factorial(int n) 
{
    if (n == 0) 
    {
        // Print the current level of recursion
        std::cout << "Entering level: " << n << std::endl;
        return 1;
    } else {
        int result = n * factorial(n - 1);
        // Print when exiting the level of recursion
        std::cout << "Exiting level: " << n << " with result: " << result << std::endl;
        return n * factorial(n - 1);
    }
}

int main() 
{
    factorial(5); // 5! = 5 * 4 * 3 * 2 * 1 = 120
    return 0;
}
