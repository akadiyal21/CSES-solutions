#include<iostream>
#include<vector>
#include<algorithm>
#include<string> 
#include<cstring>
#define ll long long 
using namespace std;
ll dp[1001][1001];
int main()
{
	ll n,m; 
	string a,b; cin>>a>>b; n=a.size(); m=b.size();
	ll dp[n+1][m+1]; 
	memset(dp,0,sizeof(ll)*(m+1)*(n+1)); 
	//dp[0][0] = ; 
	/*for(ll i = 1;i<m;i++)
	{
		if(a[0]==b[i])
		{
			dp[0][i] = min(i,(ll)(dp[i-1]+1));
		}
		else
		{
			dp[0][i] = dp[0][i-1] + 1;
		}
	}*/
	for(ll i = 0;i<=max(n,m);i++)
	{
		if(i<=n)
			dp[i][0] = i;
		if(i<=m)
			dp[0][i] = i;
	}
	for(ll i = 1;i<=n;i++)
	{
		for(ll j = 1;j<=m;j++)
		{
			//if(i==0) dp[i][j] = min(dp[i][j-1]+1,j)
		 	//if(j==0) dp[i][j] = min(dp[i-1][j]+1,i);
		 	//else
				dp[i][j] = min(min(dp[i-1][j]+(ll)1,dp[i][j-1]+(ll)1),dp[i-1][j-1]+(ll)(a[i-1]!=b[j-1]));
				dp[i][j] = min(dp[i][j],dp[i-1][j-1]+1); 
		}
	}
	/*for(ll i = 0;i<=n;i++)
	{
		for(ll j = 0;j<=m;j++)
		{
			cout<<dp[i][j]<<" ";//<<i<<"###"<<j;
		}
		cout<<endl;
	}*/
	cout<<dp[n][m]<<endl;
	return 0;
}
