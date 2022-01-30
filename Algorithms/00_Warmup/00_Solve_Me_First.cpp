/*
Complete the function solveMeFirst to compute the sum of two integers.

- Example
 a=7
 b=3
Return 10

- Function Description
Complete the solveMeFirst function in the editor below.
solveMeFirst has the following parameters:

  int a: the first value
  int b: the second value
 Returns
  int: the sum of  and 

- Constraints
 1 < a,b < 1000

- Sample Input

  a = 2
  b = 3

- Sample Output

  5

Explanation
  2 + 3 = 5
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solveMeFirst(int a, int b) {
 // Hint: Type return a+b; below:
  return a+b;
}

int main() {
  int num1, num2;
  int sum;
  cin>>num1>>num2;
  sum = solveMeFirst(num1,num2);
  cout<<sum;
  return 0;
}