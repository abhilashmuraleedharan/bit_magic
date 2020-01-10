/*
 * Objective:
 * Write a C++ program to calculate the number of bits 
 * set in a given number n.
 * For e.g.
 * For n=5, output should be 2
 * For n=15, output should be 4
 *
 * Other Assumptions:
 * n will always be a positive integer.
 *
 */
#include <iostream>

/*
 * Naive method
 * Bitwise & n with 1. 
 * When I get 1 increment count else do n=n/2 
 * to move to next rightmost bit and do the same bitwise operation
 * until we have checked all the bits.
 *
 * Time Complexity: Theta(Number Of Bits Used To Represent the Integer)
 */
int numBitsSet(int n) {
   if (n==0) return 0;
   int count = 0;
   while (n>0) {
      count = count + (n & 1);
      n = n >> 1; // This is equivalent to doing n=n/2
   }
   return count;
}

/*
 * Using Brian Kerningam Algorithm
 * When you subtract 1 from a number, all the zero bits after the
 * first set bit becomes 1 and the first set bit becomes 0.
 * For e.g. 8 binary representation is 1000 whereas 7 binary representation is 0111
 * So when you do n&(n-1) you will unset the rightmost set bit.
 * If it's the last set bit result will be 0 else non-zero.
 * Using this understanding, you can write a function that calculates number of bits
 * set in a given number n in Theta(Number of Bits Set) time.
 */
int totalBitsSet(int n) {
   if (n==0) return 0;
   int count = 0;
   while (n>0) {
      n = n & (n-1);
      count++;
   }
   return count;
}
  
int main() {
   std::cout << "Program to calculate the number of \'set bits\' in a given number n" << std::endl;
   int n=0;
   std::cout << "Enter a positive n value: ";
   std::cin>>n;
   //std::cout << "Number of bits set in " << n << " is equal to " << numBitsSet(n) << std::endl;
   std::cout << "Number of bits set in " << n << " is equal to " << totalBitsSet(n) << std::endl;
   return 0;
}
