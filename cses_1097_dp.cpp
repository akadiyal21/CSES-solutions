#include<iostream>
#include<vector> 
#include<algorithm>
#define ll long long 
using namespace std;
ll dp[5001][5001][2][2]; 
int main()
{
//	cout<<sizeof(dp)<<endl;
	ll n; cin>>n;
	vector <ll> a(n); 
	//ll size = 5001*5001*4*8/2 + n 
	for(ll i = 0;i<n;i++)
	{
		cin>>a[i];
	}
	for(ll i = 0;i<n;i++)
	{
		for(ll state1 = 0;state1<=1;state1++)
		{
			for(ll state2 = 0;state2<=1;state2++)
			{
				if(state1==state2) dp[i][i][state1][state2]=a[i]; 
			 else dp[i][i][state1][state2] = 0;
			}
		}
	}
	for(ll row = n-2;row>=0;row--)
	{
		for(ll col = row+1;col<n;col++)
		{
			for(ll s1 = 0;s1<=1;s1++)
			{
				for(ll s2 = 0;s2<=1;s2++)
				{
					if(s1==s2) 
					{
						dp[row][col][s1][s2] = max(a[row]+dp[row+1][col][s1][1-s2],a[col]+dp[row][col-1][s1][1-s2]);
					}
					else 
					{
						if(a[row]+dp[row+1][col][1-s1][1-s2]>a[col]+dp[row][col-1][1-s1][1-s2])
						{
							dp[row][col][s1][s2] = dp[row+1][col][1-s1][s2];
						}
						else
						{
							dp[row][col][s1][s2] = dp[row][col-1][1-s1][s2];
						}
					}
				}
			}
		}
	}
		cout<<dp[0][n-1][0][0]<<endl;
	return 0; 
}
