/*
 * Objective:
 * Write a C++ program to check whether a given number n
 * is power of 2 or not.
 * For e.g.
 * For n=6, output should be false
 * For n=16, output should be true
 *
 * Other Assumptions:
 * n will always be a positive integer.
 *
 */
#include <iostream>

/*
 * Fact: Power of 2 numbers will always have only 1 bit set.
 *
 * Using Brian Kerningam Algorithm
 * When you do n&(n-1) you will unset the rightmost set bit.
 * If it's the last set bit result will be 0 else non-zero.
 */
bool isPowerOfTwo(unsigned n) {
   return ((n != 0) && ((n&(n-1)) == 0));
}
  
int main() {
   std::cout << "Program that checks whether given number n is a power of 2 or not" << std::endl;
   unsigned n=0;
   std::cout << "Enter a positive n value: ";
   std::cin>>n;
   if (isPowerOfTwo(n)) {
      std::cout << n << " is a power of 2" << std::endl;
   } else {
      std::cout << n << " is not a power of 2" << std::endl;
   }
   return 0;
}
