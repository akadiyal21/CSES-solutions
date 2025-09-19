#include<iostream>
#include<climits>
#include<algorithm>
#define ll long long 
#define inf LLONG_MAX
ll dp[200005]; // holds the smallest element that ends 
int cmp(ll a, ll b)
{
	return a<=b;
}
using namespace std;
int main()
{
	ll n; cin>>n;
	ll arr[n]; 
	for(ll i = 0;i<n;i++)
	{
		cin>>arr[i];
	}
	dp[0] = -1;
	for(ll i = 1;i<=n;i++)
	{
		dp[i] = inf;
	}
	for(ll i = 0;i<n;i++)
	{
		auto pos = upper_bound(dp,dp+n,arr[i],&cmp) - dp;
		dp[pos] = arr[i];
	}
	for(ll i = n;i>=1;i--)
	{
		if(dp[i]!=inf) {
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
