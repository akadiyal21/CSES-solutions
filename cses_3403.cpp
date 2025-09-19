#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long 
using namespace std;
ll dp[1001][1001];
int main()
{
	ll n,m; cin>>n>>m;
	ll a1[n], a2[m];
	for(ll i = 0;i<n;i++)
	{
		cin>>a1[i];
	}
	for(ll i = 0;i<m;i++)
	{
		cin>>a2[i];
	}
	// dp[i][j] - longest common subsequence ending (doesn't exactly end but in processing) at i in s1 and j in s2 ;
	//
	//dp[0][0] = a1[0]==a2[0];
	for(ll i = 0;i<m;i++)
	{
		dp[0][i]= a1[0]==a2[i];
	}
	for(ll i = 1;i<n;i++)
	{
		for(ll j = 0;j<m;j++)
		{
			if(a1[i]==a2[j])
			{
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout<<dp[n-1][m-1]<<endl;
	ll count = dp[n-1][m-1]; vector <ll> ans;
	ll i = n-1,j = m-1; 
	while(count)
	{
		if(a1[i]==a2[j])
		{
			//cout<<a1[i]<<" ";
			ans.push_back(a1[i]);
			count--;
			i--; j--;
		}
		else
		{
			if(dp[i][j]==dp[i-1][j])
			{
				i--;
			}
			else
			{
				j--;
			}
		}
	}
	//cout<<endl;
	for(ll k = ans.size()-1;k>=0;k--)
	{
		cout<<ans[k]<<" ";
	}
	cout<<endl;
	return 0;
}
