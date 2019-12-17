/*
 * Objective:
 * Write a C++ function to swap 2 numbers without
 * using a temporary variable.
 *
 * For e.g.
 * For a=5, b=3, output should be a=3 and b=5.
 *
 */
#include <iostream>

/*
 * Using XOR operator we can swap 2 numbers without
 * using a temporary variable.
 * XOR properties used here are:
 * x ^ x = 0
 * x ^ 0 = x
 * a ^ (b ^ c) = (a ^ b) ^ c
 */
void swap(int a, int b) {
   a = a ^ b;  
   b = a ^ b; // b = (a ^ b) ^ b = a ^ (b ^ b) = a ^ 0 = a
   a = a ^ b; // a = (a ^ b) ^ a = b ^ (a ^ a) = b ^ 0 = b
   std::cout << "a: " << a << std::endl;
   std::cout << "b: " << b << std::endl;
}

int main() {
   std::cout << "Program that swaps two given integers a and b" << std::endl;
   int a, b;
   std::cout << "Enter the value of a: ";
   std::cin >> a;
   std::cout << "Enter the value of b: ";
   std::cin >> b;
   std::cout << "After swapping" << std::endl;
   swap(a, b);
   return 0;
}
