#include<iostream>
#define ll long long
ll m = 1000000007;
ll dp[1000005];
using namespace std;
int main()
{
	ll n; cin>>n;dp[1] = 1;dp[0]=1;
	for(ll i = 2;i<=n;i++)
	{
		for(ll j = 1;j<=6;j++)
		{
			if(i-j>=0)
				dp[i] = (dp[i] + dp[i-j])%m;
		}
	}
	cout<<dp[n]%m<<endl;
	return 0;
}
