#include <bits/stdc++.h>
using namespace std;

map<vector<int>,int> memo;

int ways(int n ,int m ,int x)
{
	int ans = 0;
	if (memo[{n,m,x}] == 0)
	{
		// base cases
		if(x <= 0) return 0;
		if(n == 1)
		{
			if(x<=m) return 1;
			else     return 0;
		}
		// recursive call
		for(int i = 1 ; i<= m ; i ++)
		{
			ans += ways(n-1,m,x-i);
		}
		memo[{n,m,x}] = ans;
	}
	return memo[{n,m,x}];
}


void solve(){

	int n , m;
	cin >> n >> m;
	/*
		n dices
		m faces from 1 to m
	*/
	int x;
	cin >> x;

	int ans = ways(n , m , x);
	cout << ans << endl;

}
int main(){


	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r" , stdin);
		freopen("output.txt", "w" , stdout);
	#endif

	int t;cin>>t; 
	while(t--)
    {
    	solve();
	}
	return 0;
}
