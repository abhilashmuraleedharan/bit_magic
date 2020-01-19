/*
 * Objective:
 * Given a number N, write a C++ program to calculate
 * the result of performing XOR of all numbers from 
 * 1 to N 
 *
 * For e.g.
 * if n=5 then output should be 1^2^3^4^5 = 1
 */
#include <iostream>

/*
 * When we do XOR of numbers, we get 0 as XOR value just
 * before a multiple of 4. This keeps repeating before
 * every multiple of 4 as illustrated below.
 *
 * Number   Binary-Repre   XOR-from-1-to-n
 * ----------------------------------------
 *  1                 1      [0001]
 *  2                10      [0011]
 *  3                11      [0000] <-- we get a 0
 *  4               100      [0100] <-- equals n
 *  5               101      [0001]
 *  6               110      [0111]
 *  7               111      [0000] <-- we get 0
 *  8              1000      [1000] <-- equals n
 *  9              1001      [0001]
 *  10             1010      [1011] 
 *  11             1011      [0000] <-- we get 0
 *  12             1100      [1100] <-- equals n
 *
 * Using above pattern we can come up with following algorithm
 * If n%4 is
 * a) Equals to 0, then XOR will be n
 * b) Equals to 1, then XOR will be 1
 * c) Equals to 2, then XOR will n+1
 * d) Equals to 3, then XOR will be 0
 *
 * Time Complexity: O(1)
 */
int XOR(int n) {
   switch (n%4) {
      case 0: return n;
      case 1: return 1;
      case 2: return n+1;
      case 3: return 0;
      default: break;
   }
   return -1;
}

/*
 * Function to validate the result of XOR func
 */
bool validateResult(int n, int res) {
   int XOR = 0;
   for (int i=1; i<=n; i++) { XOR ^= i; }
   return (XOR == res);
}

int main() {
   std::cout << "Program that calculates xor of all numbers from 1 to N" << std::endl;
   int n=0;
   std::cout << "Enter the value of n: ";
   std::cin >> n;
   int res = XOR(n);
   if (res != -1) {
      std::cout << "XOR of all numbers from 1 to " << n << " is = " << res << std::endl;
      std::cout << ((validateResult(n, res)) ? "Test passed!" : "Test failed!") << std::endl;
   } else { std::cout << "Invalid value of n" << std::endl; }
   return 0;
}
