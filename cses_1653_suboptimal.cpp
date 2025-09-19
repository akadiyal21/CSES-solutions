#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define ll long long 
using namespace std;
int main()
{
	ll n,x; cin>>n>>x; 
	vector <ll> a(n);
	for(ll i = 0;i<n;i++)cin>>a[i];
	//cout<<(1<<n)<<endl;
	ll N = (1<<n); 
	ll dp[1<<n]; 
	memset(dp,0,sizeof(ll)*N);
	// precompute weight sums
	ll w[N]; memset(w,0,sizeof(ll)*N);
	for(ll i = 0;i<N;i++)
	{
		for(ll j = 0;j<n;j++)
		{
			if ((1<<j)&(i))
			{
				w[i] += a[j]; 
			}
		}
	}
	/*for(ll i = 0;i<N;i++)
	{
		cout<<w[i]<<" ";
	}
	cout<<endl;*/
	/*for(ll i = 0;i<n;i++)
	{
		dp[1<<i] = 1;
	}*/
	for(ll i = 1;i<N;i++) dp[i] = n; 
	for(ll i = 1;i<N;i++)
	{
		for(ll j = 0;j<=i;j++)
		{
			if((i&j)==j)
			{
				if(w[j]<=x)
				{
					dp[i] = min(dp[i],dp[i^j]+1);
				}
			}
		}
	}
/*	for(ll i = 0;i<N;i++)
	{
		cout<<dp[i]<<" ";
	}*/
	cout<<endl;
	cout<<dp[N-1]<<endl;
	return 0; 
}
