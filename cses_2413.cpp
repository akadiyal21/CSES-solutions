#include<iostream>
#include<cstring>
#define ll long long
using namespace std;
const ll mod = 1000000007;
int main()
{
	ll t; cin>>t;
	while(t--)
	{
		ll n; cin>>n;
		ll dp[n+1][2];
		memset(dp,0,sizeof(ll)*(n+1)*2);
		dp[1][0] = 1;
		dp[1][1] = 1;
		for(ll i = 2;i<=n;i++)
		{
			dp[i][1] = 2*dp[i-1][1] + dp[i-1][0];
			dp[i][1]%=mod;
			dp[i][0] = 4*dp[i-1][0] + dp[i-1][1];
			dp[i][0]%=mod;
		}
		cout<<(dp[n][0]+dp[n][1])%mod<<endl;
	}
	return 0;
}
