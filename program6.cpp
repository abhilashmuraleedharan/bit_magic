/*
 * Objective:
 * Given an array of integers, that has 2 elements that're occurring
 * odd number of times while rest of the elements are occurring even number 
 * of times, write a C++ program that displays the two odd occurring
 * numbers.
 * For e.g.
 * If the input array is 
 * [4, 3, 4, 3, 5, 4, 3, 5, 4, 7]
 * then the output should be 3 and 7, since they are the elements
 * that are occurring odd number of times.
 *
 * Other Assumptions:
 * Input array will only have 2 odd occurring numbers.
 * Input array will only have positive integer values.
 */
#include <iostream>

/*
 * Naive method
 * Time Complexity: Theta(N Squared)
 */
void printOddOccurringNumbers1(int *arr, int size) {
   int count;
   for (int i=0; i<size; i++) {
      count = 0;
      for (int j=0; j<size; j++) {
         if (arr[i] == arr[j]) {
            count++;
         }
      }
      // Print the odd occurring number.
      if (count%2 != 0)
         std::cout << arr[i] << " ";
   }
   std::cout << std::endl;
}

/*
 * As demonstrated in program4.cpp you can determine the odd occurring element
 * in an array simply by xor'ing all the array elements. However, when there 
 * are two odd occurring elements then the result `res` we got will be x^y 
 * where x and y are the two odd occurring elements.
 * So for e.g. if the input array is
 * [2, 3, 4, 2, 3, 4, 3, 5]
 * then xor of all the elements in this array, xor = 3^5
 *   000...0011 ^
 *   000...0101
 * = 000...0110 = 6
 * So we need to find from the result of xor i.e. 6, the odd occurring 
 * numbers 3 and 5
 * Since xor operation yields 1 only if the operand bits are different,
 * we can take any set bit of xor result and say the same bit will be set 
 * only for 1 operand while for the other it will be off. So lets take the right 
 * most set bit of the xor result 6. That's bit 2. If you see for 3 2nd bit is set
 * while for 5 2nd bit is off. Using this understanding, if kth bit is the rightmost 
 * bit that's set in the xor result, then we can divide the input array elements into
 * two groups: One containing elements where the kth bit is set, while the other 
 * contains elements where the kth bit is off.
 * So in our e.g. k value is 2 since that's the righmost bit set in our xor result 6. 
 * group1 will be [2, 3, 2, 3, 3] since these elements 2nd bit is set
 * group2 will be [4, 4, 5] since these elements 2nd bit is off.
 * What we have done here is we split the odd occuring element into two separate groups
 * Now xor'ng the elements of group1 will give you one odd occurring element and
 * xor'ing the elements of group2 will give you the second odd occurring element.
 *
 * Time Complexity: Theta(N)
 * Space Complexity: Theta(N) Auxilliary Space Complexity: Theta(1)
 */
void printOddOccurringNumbers(int *arr, int size) {
   int res1 = 0, res2 = 0, XOR=0;
   // Find xor of all the array elements
   for (int i=0; i<size; i++) { XOR = XOR ^ arr[i]; }
   /*
    * To divide the array elements into 2 groups - one with elements 
    * having the kth bit set and one with elements having the kth bit as off,
    * you need to generate a number(mask) that has only the kth bit set. Then you can
    * bitwise & this number with each element of the array to find which elements 
    * have that same bit set and which elements have that bit as off. 
    * By kth bit I mean the rightmost set bit of the result obtained in above xor 
    * operation stored in XOR.
    */
   int mask = XOR & ~(XOR-1); 
   for (int i=0; i<size; i++) {
      if (arr[i] & mask) { res1 = res1 ^ arr[i]; } // xor'ing elements having kth bit set
      else { res2 = res2 ^ arr[i]; }  // xor'ing elements having the kth bit turned off
   }
   std::cout << res1 << " " << res2 << std::endl;
}

int main() {
   std::cout << "Program that prints the two odd occurring numbers in a given array" << std::endl;
   std::cout << "Enter the size of the input array: ";
   int size = 0;
   std::cin>>size;
   int *arr = new int[size]; 
   std::cout << "Enter positive integer values as array elements such that only two integers occur odd number of times" << std::endl;
   for (int i=0; i<size; i++)
      std::cin>>arr[i];
   std::cout << "Input array is : " << std::endl;
   std::cout << "[ ";
   for (int i=0; i<size; i++)
      std::cout << arr[i] << " ";
   std::cout << "]" << std::endl;
   std::cout << "The odd occurring elements are: ";
   //printOddOccurringNumbers1(arr, size);
   printOddOccurringNumbers(arr, size);
   delete []arr;
   return 0;
}
