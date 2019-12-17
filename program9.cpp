/*
 * Objective:
 * Write a C++ function to flip the bits of a given 
 * positive integer. 
 *
 * For e.g.
 * if n=23 which is 10111 output should be
 * 8 which is 01000. 
 */
#include <iostream>
#include <cmath>  // For pow and log2 functions

/*
 * If you subtract the given number from the number 
 * that you get by setting all bits to 1 you will 
 * get the desired number having flipped bits.
 * For e.g.
 * if n=23 (10111), then you need to subtract 23 from the number
 * (11111) 31 which gives you 8 (01000) which is our desired answer.
 */
int flipBits(int n) {

   // When you do log2(N), what we get (ignoring decimal part) is 
   // the position of MSB set in N. 
   int msb_bit_pos = log2(n);
   // Maximum number that can be represented by n bits
   // is pow(2,n) - 1. 
   int max_num = pow(2,msb_bit_pos+1) - 1; // Need to add 1 to msb_bit_pos
                                           // since bit position starts from 0
   // flipped bit number = max_num - n
   return max_num - n;
}

int main() {
   std::cout << "Program that flip the bits of a given number n" << std::endl;
   int n=0;
   std::cout << "Enter the value of n: ";
   std::cin >> n;
   std::cout << "After flipping bits n = " << flipBits(n) << std::endl;
   return 0;
}
