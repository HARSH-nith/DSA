#include <bits/stdc++.h>
using namespace std;

#define lli long long int

// technique used - recursion with memoization

lli memo[50][50][5000];
lli mod = 1e9 + 7;

lli ways(int n ,int m ,int x)
{

	/*
		n : the number of dices left out
		m : the face values of dice = 1 to m
		x : the target sum
	*/
	
	lli ans = 0;

	if (memo[n][m][x] != -1)
	{
		// if my current state is already precomputed ,
		//   just return the stored value from the memo-table.

		return memo[n][m][x];
	}
	else
	{
		// base cases
		if(x <= 0) return 0;		// if my target sum < 0 , not possible
		if(n == 1)
		{
			if(x<=m) return 1;		// if my number of dices  = 1 , and 1<=x<=m , then 
							// I can choose the last dice to have x on its face
							// There is only 1 way to do so , so return 1
			else     return 0;
							// If my target sum > m , and I have only 1 dice left
							// Its impossible to achieve the target sum
							// return 0
		}

		// recursive call
		for(int i = 1 ; i<= m ; i ++)
		{
			/*
				
			on current state ,
			Let	the Nth dice have (i th) face 
				then my new target sum would be (x - i)
			
			So , 
				ways(n,m,x) = ways(n-1,m,x-1) + ways(n-1,m,x-2) + ... ways(n-1,m,x-m)

			*/

			ans += ways(n-1,m,x-i);
			if(ans > mod) ans -= mod;
		}

		// store my result in memo-table
		memo[n][m][x] = ans;
	
	}
	return memo[n][m][x];

}


void solve(){

	int n , m , x;
	cin >> n >> m >> x;
	/*
		n :number of dices
		m :dice-faces from 1 to m
		x :target sum
	*/

	lli ans = ways(n , m , x);

	cout << ans << endl;

}
int main(){

	// input and output files access
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r" , stdin);
		freopen("output.txt", "w" , stdout);
	#endif


	// clear the memo tabe
	for(int i = 0 ; i < 50 ; i ++)
	{
		for(int j = 0 ; j < 50 ; j ++)
		{
			for(int k = 0 ; k < 5000 ;k++)
			{
				memo[i][j][k] = -1;
			}
		}
	}

	int t;
	cin>>t; // The number of testcases
	
	while(t--)
    	{
    		solve();
	}
	return 0;
}
