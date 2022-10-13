// Factorial of a number

#include <iostream>
#include <vector>
using namespace std;

// approach 1
int recursiveFactorial(int n)
{
  if (n == 0 || n == 1) // base cases
    return 1;
  return n * recursiveFactorial(n - 1);
}

int memoizedFactorial(int n, vector<int> &dp)
{
  if (n == 0 || n == 1) // base cases
    return 1;
  if (dp[n] != -1) // checking if func with same input has been called or not
    return dp[n];
  else
    return dp[n] = n * memoizedFactorial(n - 1, dp);
}

int tabulatedFactorial(int n, vector<int> &dp)
{
  dp[0] = 1;                   // base case
  dp[1] = 1;                   // base case
  for (int i = 2; i <= n; i++) // starting from the base cases
  {
    dp[i] = i * dp[i - 1];
  }
  return dp[n];
}

int main()
{
  int n;
  cout << "Enter the value of n: " << endl;
  cin >> n;

  cout << "result after recursive sol: " << recursiveFactorial(n) << '\n';

  vector<int> dp(n + 1, -1); // dp array
  cout << "result after memoized sol: " << memoizedFactorial(n, dp) << '\n';

  cout << "result after Tabulated sol: " << tabulatedFactorial(n, dp) << '\n';

  return 0;
}

/*
approach 1
- it's a simple recursion approach
- factorial is the product of all integers between n and 1
- the expression will be n!=n*(n-1)!
- the base cases are:
          0! = 1
          1! = 1
- T.C. : O(2^N)
- S.C. : O(N)
*/

/*
- approach 2 => memoiation or Top Down
- recursive approach had a shortcoming that it called same func multiple times
- to reduce that overhead, we store the result in a dp array
- so to use dp array, we create a dp array of n+1 index to store 0-n elements and initialize them with -1
- Start with a recursive function and add a table that maps the function’s input values to the results returned by the function. Then if this function is called twice with the same parameters, we simply look up the answer in the table.
- T.C. : O(N)
- S.C. : O(N)+O(N)
*/

/*
approach 3 => Tabulation or Bottom Up
- With memoization we were still having recursive stack which was increasing the space complexity
- this also uses dp array initialized with -1 but instead of recursion, we use a loop
- pre define the base cases, start with lower values of input and keep building the solutions for higher values
- T.C. : O(N)
- S.C. : O(N)
*/
