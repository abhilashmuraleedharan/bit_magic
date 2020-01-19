/*
 * Objective:
 * Given a number N, write a C++ program to
 * find the length of the longest consecutive 1s
 * in its binary representation.
 *
 * For e.g.
 * For N=627, output should be 3
 * since the length of the longest consecutive
 * 1s in the binary representation of 627 is 3
 * binary(627) = 1001110011
 *
 * Assumptions:
 * n will always be a positive integer.
 *
 */
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int longestConsecutiveOnes(int n) {
   int count = 0;
   while(n != 0) {
      n = n & (n << 1);
      count++;
   }
   return count;
}

int main() {
   cout << "Program that determines the length of the longest consecutive 1s\n";
   cout << "in the binary representation of given number N" << endl;
   int n=0;
   cout << "Enter a positive N value: ";
   cin >> n;
   cout << "Length of longest consecutive 1s = " << longestConsecutiveOnes(n) << endl;
   return 0;
}
