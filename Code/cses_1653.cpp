#include<iostream>
#include<vector>
#include<algorithm>
#define ll unsigned long long 
using namespace std;
int main()
{
	ll n,x; cin>>n>>x; 
	vector <ll> a(n);
	for(ll i = 0;i<n;i++) cin>>a[i]; 
	ll N = 1<<n; 
	vector <ll> dp(N,0);
	vector <ll> smol_wt(N,0);
	dp[0] = 1;
	smol_wt[0] = 0;
	for(ll i = 1;i<N;i++)
	{
		dp[i] = n; 
		for(ll j = 0;j<n;j++)
		{
			if(((1<<j)&i))
			{
				ll smol_wt_val,dp_val;
				if(a[j]+smol_wt[(1<<j)^i]<=x)
				{
					//if(dp[i]>dp[(1<<j)^i])
					smol_wt_val = smol_wt[(1<<j)^i] + a[j];
					
					dp_val = dp[(1<<j)^i];
				}
				else
				{
					//if(dp[i]> (dp[(1<<j)^i]+1))
					smol_wt_val = a[j];
					dp_val = dp[(1<<j)^i]+1; 
				}
				if((dp_val<dp[i])||((dp_val==dp[i])&&(smol_wt_val<smol_wt[i])))
				{
					dp[i] = dp_val; 
					smol_wt[i] = smol_wt_val;
				}
			}
		}
	}
	/*for(ll i  = 0;i<N;i++)
	{
		cout<<dp[i]<<" ";
	}
	cout<<endl;*/
	cout<<dp[N-1]<<endl;
	return 0; 
}

