// Nth Fibonacci Number - Given a number n, print n-th Fibonacci Number.

#include <iostream>
#include <vector>
using namespace std;

// approach 1
int recursiveFib(int n)
{
  if (n <= 1) // base case
    return n;
  return recursiveFib(n - 1) + recursiveFib(n - 2);
}

// approach 2
int memoizedFib(int n, vector<int> &dp)
{
  if (n <= 1)
  { // base cases
    return n;
  }
  if (dp[n] != -1) // checking if the func is called before
    return dp[n];
  else
    return dp[n] = memoizedFib(n - 1, dp) + memoizedFib(n - 2, dp);
}

// approach 3
int tabulatedFib(int n, vector<int> &dp)
{
  dp[0] = 0; // base case
  dp[1] = 1; // base case
  for (int i = 2; i <= n; i++)
  {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[n];
}

int main()
{
  int n;
  cout << "Enter the value of n: " << endl;
  cin >> n;

  cout << "result after recursive sol: " << recursiveFib(n) << '\n';

  vector<int> dp(n + 1, -1); // dp array
  cout << "result after memoized sol: " << memoizedFib(n, dp) << '\n';

  cout << "result after Tabulated sol: " << tabulatedFib(n, dp) << '\n';

  return 0;
}

/*
approach 1
- it's a simple recursion approach
- using the mathematical relation for fibonacci seq: Fn = Fn-1 + Fn-2
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
