#include<iostream>
#include<cstring>
#define ll long long 
const ll mod = 1000000007;
ll dp[100001][101];
using namespace std;
int main()
{
	ll n, m; cin>>n>>m;
	ll arr[n+1];
	for(ll i = 1;i<=n;i++)
	{
		cin>>arr[i];
	}
	//ll dp[n+1][m+1];
	//memset(dp, 0, (n+1)*(m+1)*sizeof(ll));
	for(ll j = 1;j<=m;j++)
	{
		if(arr[1]==0)
			dp[1][j] = 1;
		else
		{
			if(j==arr[1])
			{
				dp[1][j] = 1;
			}
		}
	}
	for(ll i = 2;i<=n;i++)
	{
		if(arr[i]==0)
		{
			for(ll j = 1;j<=m;j++)
			{
				for(ll k = j-1;(k<=j+1)&&(k<=m);k++)
					dp[i][j] = (dp[i][j] + dp[i-1][k]%mod)%mod;
			}
		}
		else
		{
			for(ll k = arr[i]-1;(k<=arr[i]+1)&&(k<=m);k++)
					dp[i][arr[i]] = (dp[i][arr[i]] + dp[i-1][k]%mod)%mod;
		}
	}
/*	for(ll i = 1;i<=n;i++)
	{
		for(ll j = 1;j<=m;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/ ll ans = 0;
	for(ll i = 1;i<=m;i++)
	{
		ans += dp[n][i];
		ans %=mod; 
	}
	cout<<ans<<endl;
	return 0;
}
