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
 * Naive Method
 * Check if n is divisible by 2.
 * If it is then remove the right most bit and again
 * check if the new n is divisible by 2.
 * Repeat this process until n becomes 1. If in between
 * n is found to be not divisible by two then the original n
 * is not a power of two. Else if all the n values until it 
 * becomes 1 are divisible by 2 then the original n is a power
 * of two.
 *
 * Time Complexity: Theta(Number of Bits used to represent Integer)  
 */
bool isPowerOfTwoNaive(unsigned n) {
   while (n!=1) {
      if (n%2 != 0) { return false; }
      n = n >> 1;
   }
   return true;
}

/*
 * Fact: Power of 2 numbers will always have only 1 bit set.
 *
 * Using Brian Kerningam Algorithm
 * When you do n&(n-1) you will unset the rightmost set bit.
 * So if you perform n&(n-1) and you get 0 in the first attempt
 * itself, it means there is only 1 bit set in n and it must be
 * a power of 2.
 *
 * Time Complexity: Theta(Number of Set Bits)
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
