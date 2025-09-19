#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring> 
#define ll long long
using namespace std;
const ll m = 1000000000+7;
int main()
{
	ll n; cin>>n; 
	ll sum = (n*(n+1))/2; 
	ll dp[n][sum+1]; 
	memset(dp,0,sizeof(ll)*(sum+1)*(n));
	ll a[n];
	for(ll i = 0;i<n;i++) a[i] = i+1;
	dp[0][0] = 1; 
	for(ll i = 1;i<=sum;i++)
	{
		dp[0][i] = 0;
	}
	for(ll i = 1;i<n;i++)
	{
		for(ll j = 0;j<=sum;j++)
		{
			dp[i][j] = (dp[i][j]%m + dp[i-1][j]%m)%m  ;
			if(j-a[i]>=0)
				dp[i][j] = (dp[i][j]%m + dp[i-1][j-a[i]]%m)%m; 
		}
	}
	/*for(ll i = 0;i<n;i++)
	{
		for(ll j = 0;j<=sum;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	if(sum%2==1) cout<<0<<endl;
	else
		cout<<dp[n-1][sum/2]<<endl;
	return 0; 
}

