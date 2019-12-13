/*
 * Objective:
 * Given an array of integers, write a C++ program 
 * to find the number that's occurring odd number of times.
 * For e.g.
 * If the input array is 
 * [4, 3, 4, 3, 5, 4, 3, 5, 4]
 * then the output should be 3, since it's the element 
 * that's occurring odd number of times.
 *
 * Other Assumptions:
 * Input array will only have 1 odd occurring number.
 * Input array only has positive integer values.
 */
#include <iostream>

/*
 * Naive method
 * Time Complexity: Theta(N Squared)
 */
int oddOccurringNumber1(int *arr, int size) {
   int count;
   for (int i=0; i<size; i++) {
      count = 0;
      for (int j=0; j<size; j++) {
         if (arr[i] == arr[j]) {
            count++;
         }
      }
      // Since there can be only 1 odd occurring number,
      // return the element value as soon as you find one.
      if (count%2 != 0)
         return arr[i];
   }
   return -1;
}

/*
 * Using below properties of xor operation 
 * x ^ 0 = x
 * x ^ x = 0
 * x ^ y = y ^ x
 * x ^ (y ^ z) = (x ^ y) ^ z
 * if we xor all the elements of the given array, then the
 * value that's returned will be the odd occurring element.
 * For e.g., let's say the input array is [4, 3, 4, 6, 4, 6, 4]
 * XORing the elements will result in 3 as shown below,
 * 4 ^ 3 ^ 4 ^ 6 ^ 4 ^ 6 ^ 4 = (4 ^ 4 ^ 3) ^ (6 ^ 6 ^ 4 ^ 4) =
 * (0 ^ 3) ^ (0 ^ 0) = 3 ^ 0 = 3
 * Here 3 is the odd occurring element as all evenly occuring numbers
 * will xor to 0.
 *
 * Time Complexity: Theta(N)
 */
int oddOccurringNumber(int *arr, int size) {
   int res = 0;
   for (int i=0; i<size; i++) {
      res = res ^ arr[i];
   }
   if (res == 0) {
      return -1;
   } else {
      return res;
   }
}

int main() {
   std::cout << "Program that determines the only odd occurring number in a given array" << std::endl;
   std::cout << "Enter the size of the input array: ";
   int size = 0;
   std::cin>>size;
   int *arr = new int[size]; 
   std::cout << "Enter positive integer values as array elements such that one integer occur odd number of times" << std::endl;
   for (int i=0; i<size; i++)
      std::cin>>arr[i];
   std::cout << "Input array is : " << std::endl;
   std::cout << "[ ";
   for (int i=0; i<size; i++)
      std::cout << arr[i] << " ";
   std::cout << "]" << std::endl;
   //int res = oddOccurringNumber1(arr, size);
   int res = oddOccurringNumber(arr, size);
   if (res != -1)
      std::cout << "The odd occuring array element is " << res << std::endl;
   else
      std::cout << "There are no odd occurring elements in the array" << std::endl;
   delete []arr;
   return 0;
}
