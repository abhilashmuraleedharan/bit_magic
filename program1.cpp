/*
 * Objective:
 * Write a C++ program to check if the kth bit is set or not 
 * in a given number n.
 * For e.g.
 * For n=5, k=3, output should be true
 * For n=8, k=3, output should be false
 *
 * Other Assumptions:
 * n and k will always be a postive integer
 *
 */
#include <iostream>
#include <stdexcept>

bool isBitSet(int n, int k) {
   if (n<0 || k<=0)
      throw std::runtime_error("Invalid Arguments");

   if (n==0)
      return false; 
   else
      return (n & (1<<(k-1)));  
}

int main() {
   std::cout << "Program to check if the kth bit is set in a given number n" << std::endl;
   int n=0, k=0;
   std::cout << "Enter value of n: ";
   std::cin>>n;
   std::cout << "Enter value of k: ";
   std::cin>>k;
   try {
      if (isBitSet(n, k)) {
         std::cout << "kth bit is set" << std::endl;
      } else {
         std::cout << "kth bit is not set" << std::endl;
      }
   } catch (std::runtime_error & e) {
      std::cout << "Exception: " << e.what() << std::endl;
   }
   return 0;
}
