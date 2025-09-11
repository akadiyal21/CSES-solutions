#include<iostream>
#include<string>
#include<vector>
#define ll long long 
ll dp[1001][1001];
ll mod = (ll) 1000000007;
using namespace std;
int main()
{
	ll n; cin>>n;
	vector <string> arr(n);
	for(ll i = 0;i<n;i++)
	{
		cin>>arr[i];
	}
  // dp init
	dp[0][0] = (arr[0][0]!='*');
	for(ll i = 1;i<n;i++)
	{	
		if(arr[0][i-1]!='*')
			dp[0][i] = dp[0][i-1];
		if(arr[i-1][0]!='*')
			dp[i][0] = dp[i-1][0];
	}
	/*for(ll i = 0;i<n;i++)
	{
		for(ll j = 0;j<n;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	for(ll i=1;i<n;i++)
	{
		for(ll j = 1;j<n;j++)
		{
			if(arr[i][j]!='*')
			{
				//cout<<"updating i -> "<<i<<" and j->"<<j<<endl;
				if(arr[i][j-1]!='*')
					dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
				if(arr[i-1][j]!='*')
					dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
			}
				
		}
	}
	cout<<dp[n-1][n-1]<<endl;
	return 0;
}
