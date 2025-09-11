#include<iostream>
#include<climits>
#define ll long long
ll dp[600][600];
using namespace std;
int main()
{
	ll a,b; cin>>a>>b; 
	ll n = max(a,b);
	for(ll i = 0;i<=n;i++)
	{
		dp[i][i] = 0;
	}
	for(ll i = 1;i<=n;i++)
	{
		for(ll j = 1;j<=n;j++)
		{
			//cout<<i<<" "<<j<<endl;
			if(i!=j)
			{
					ll mini = INT_MAX; 
					for(ll k = 1;k<j;k++)
					{
						mini = min(mini, dp[i][k]+dp[i][j-k]+1); 
					}
					for(ll k = 1;k<i;k++)
					{
						mini = min(mini, dp[i-k][j]+dp[k][j]+1);
					}
					dp[i][j]=mini
				; 
			}
		}
	}
	cout<<dp[a][b]<<endl;
	return 0; 
}

