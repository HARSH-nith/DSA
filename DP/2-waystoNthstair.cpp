// Count ways to reach the n'th stair - There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top.

#include <iostream>
#include <vector>
using namespace std;

// approach 1
int recursiveCount(int n)
{
  if (n <= 1) // base case
    return 1;
  int left = recursiveCount(n - 1);  // possible steps to reach n-1th step
  int right = recursiveCount(n - 2); // possible steps to reach n-1th step
  return left + right;               // total ways => n-1 OR n-2 steps => sum of both
}

// approach 2
int memoizedCount(int n, vector<int> &dp)
{
  if (n <= 1)
  { // base cases
    return 1;
  }
  if (dp[n] != -1) // checking if the func is called before
    return dp[n];
  else
  {
    int left = memoizedCount(n - 1, dp);
    int right = memoizedCount(n - 2, dp);
    return dp[n] = left + right;
  }
}

// approach 3
int tabulatedCount(int n, vector<int> &dp)
{
  dp[0] = 1; // base case
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

  cout << "result after recursive sol: " << recursiveCount(n) << '\n';

  vector<int> dp(n + 1, -1); // dp array
  cout << "result after memoized sol: " << memoizedCount(n, dp) << '\n';

  cout << "result after Tabulated sol: " << tabulatedCount(n, dp) << '\n';

  return 0;
}

/*
approach 1
- it's a simple recursion approach
- we are trying to find total no of ways we can reach nth step
- reach nth stair from either (n-1)th stair or from (n-2)th stair
- steps(n) = steps(n-1) + steps(n-2)
- you might realize this problem is kinda similar to fibonacci seq, so the process to memoization and tabulation will be similar
- and for the base cases:
            we can reach from 1st step by 1 way,
            we can reach from 0th step by 1 way
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
