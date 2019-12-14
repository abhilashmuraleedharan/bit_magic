/*
 * Objective:
 * Given a string, write a C++ program to generate the
 * power set of that string.
 * For e.g.
 * If the input string is "abc"
 * Then the o/p should be:
 * "","a","b","c","ab","bc","ac","abc"
 *
 * Other Assumptions:
 * Subset strings like "ab" and "ba" are treated same,
 * so only one of them needs to be present in the output. 
 */
#include <iostream>
#include <string>
#include <cmath> // For pow(base, exponent) function

/*
 * Power set of a string having n characters can be compared to 
 * the possible values of a binary number represented by n bits.
 * For e.g. I can compare power set of a string "abc" with possible
 * values of a binary number having same number of bits as illustrated
 * below.
 *    Binary Counter        |   Power Set
 *-------------------------------------------
 *    0 0 0                 |   ""
 *    0 0 1                 |   "a"
 *    0 1 0                 |   "b"
 *    0 1 1                 |   "ab"
 *    1 0 0                 |   "c"
 *    1 0 1                 |   "ac"
 *    1 1 0                 |   "bc"
 *    1 1 1                 |   "abc"
 *-------------------------------------------
 * In the above illustration each binary number represents a subset of the
 * power set and each bit represents the presence of corresponding character
 * in that subset.
 *
 * Using this understanding we can write a function to generate the powerset.
 *
 * Time Complexity: N(2^N)
 */
std::string powerSetOf(std::string s) {
   int str_len = s.length(); // Input string length
   std::string power_set; 
   /*
    * Possible binary values using `str_len` number of bits
    * will range from 0 to 2^str_len - 1. 
    */ 
   int limit = pow(2,str_len);

   // Generate subsets and append them to power_set 
   for (int bin_count=0; bin_count<limit; bin_count++) {
      power_set += "\""; //  Marks beginning of subset
      for (int j=0; j<str_len; j++) {
         if ((bin_count & (1<<j)) != 0) {
            power_set += s[j]; //  Subset string creation
         }
      }
      power_set += "\","; //  Marks end of a subset
   }
    
   power_set.back() = '\0'; // Removes the last comma
   return power_set;
}

int main() {
   std::cout << "Program that prints the power set of given string" << std::endl;
   std::string s;
   std::cout << "Enter the input string: ";
   std::cin >> s;
   std::cout << "Power set of " << s << ": " << std::endl; 
   std::cout << powerSetOf(s) << std::endl;
   return 0;
}
