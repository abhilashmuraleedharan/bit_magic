/*
 * Objective:
 * Write a C++ program to find the missing number in a 
 * given range of numbers from 1 to N+1 from an array of size N.
 * For e.g.
 * If the input array is of size 7, populated with elements that
 * are in range [1,8]
 * [4, 3, 5, 2, 1, 7, 8]
 * then the output should be 7, since 7 is the missing element here.
 *
 * Other Assumptions:
 * Input array will only have 1 missing element.
 * Input array will have no duplicates
 * Input array only have positive integer values.
 */
#include <iostream>

/*
 * Using the property of xor where x^x = 0,
 * if you xor all the numbers in the range 1 to N+1 and
 * xor that result with result of xor'ing all the elements in
 * the array, then the number that's missing will be the final result
 * as all other numbers will get cancelled out.
 *
 * Time Complexity: Theta(N)
 */
int findMissingNumber(int *arr, int size) {
   int res1 = 0, res2 = 0;
   // Store the result of xor'ng all elements of input
   // array in res1
   for (int i=0; i<size; i++) {
      res1 = res1 ^ arr[i];
   }
   // Store the result of xor'ing all the numbers in range from
   // 1 to size+1 in res2
   for (int i=1; i<=size+1; i++) {
      res2 = res2 ^ i;
   }

   return res1 ^ res2;
}

int findMissingNumber2(int *arr, int size) {
   int sum1 = 0, sum2 = 0;
   // Find sum of all the elements in the array
   for (int i=0; i<size; i++) { sum1 = sum1 + arr[i]; }
   // Find the sum of all numbers in the range 1 to size+1
   for (int i=1; i<=size+1; i++) { sum2 = sum2 + i; }
   return sum2 - sum1;
}

int main() {
   std::cout << "Program that finds the missing element in an array of size N when it's populated with" << std::endl;
   std::cout << "values in the range 1 to N+1. No duplicates allowed." << std::endl; 
   std::cout << "Enter the size of the input array: ";
   int size = 0;
   std::cin>>size;
   int *arr = new int[size]; 
   std::cout << "Enter element values in the range from 1 to " << size+1 << " with one missing value in the range" << std::endl;
   for (int i=0; i<size; i++)
      std::cin>>arr[i];
   std::cout << "Input array is : " << std::endl;
   std::cout << "[ ";
   for (int i=0; i<size; i++)
      std::cout << arr[i] << " ";
   std::cout << "]" << std::endl;
   std::cout << "The missing number is " <<  findMissingNumber(arr, size) << std::endl;
   // std::cout << "The missing number is " <<  findMissingNumber2(arr, size) << std::endl;
   delete []arr;
   return 0;
}
