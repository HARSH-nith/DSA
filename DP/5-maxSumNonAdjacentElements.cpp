// Maximum sum such that no two elements are adjacent

#include <iostream>
#include <vector>
using namespace std;

int maxSumRecursive(int index, int n, int arr[]);
int maxSumMemoization(int index, int n, int arr[], vector<int> dp);
int maxSumTabulated(int index, int n, int arr[], vector<int> dp);

int findmaxSum(int arr[], int n)
{
  vector<int> dp(n, -1);
  cout << "Recursive answer is: " << maxSumRecursive(0, n, arr) << endl;
  cout << "Memoized answer is: " << maxSumMemoization(0, n, arr, dp) << endl;
  cout << "Tabulated answer is: " << maxSumTabulated(0, n, arr, dp) << endl;
  return 0;
}

int main()
{
  int arr[] = {5, 5, 10, 100, 10, 5};
  int N = sizeof(arr) / sizeof(arr[0]);
  findmaxSum(arr, N);
  return 0;
}

// approach 1
int maxSumRecursive(int index, int n, int arr[])
{
  if (index >= n) // base case
    return 0;
  if (index == n - 1) // base case // if the control reaches the n-1th value, there's only option to pick it
    return arr[n - 1];

  int pick = arr[index] + maxSumRecursive(index + 2, n, arr);
  int notPick = 0 + maxSumRecursive(index + 1, n, arr);

  return max(pick, notPick);
}

// approach 2
int maxSumMemoization(int index, int n, int arr[], vector<int> dp)
{
  if (index >= n) // base case
    return 0;
  if (index == n - 1) // base case
    return arr[n - 1];
  if (dp[index] != -1) // checking if the func is called before
  {
    return dp[index];
  }

  int pick = arr[index] + maxSumMemoization(index + 2, n, arr, dp);
  int notPick = 0 + maxSumMemoization(index + 1, n, arr, dp);

  return dp[index] = max(pick, notPick);
}

// approach 3
int maxSumTabulated(int index, int n, int arr[], vector<int> dp)
{
  int prev = arr[0]; // base case
  int prev2 = 0;

  for (int i = 1; i < n; i++)
  {
    int pick = arr[i];
    if (i >= 2)
      pick += prev2;

    int notPick = 0 + prev;

    int curr = max(pick, notPick);
    prev2 = prev;
    prev = curr;
  }
  return prev;
}

/*
approach 1
- it's a simple recursion approach
- there are only 2 options, pick or not pick
- if we pick we add the current index to the sum and call the function with next to next index
- else we dont pick current element and call the function with next index
- and then return the maximum of those 2
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
