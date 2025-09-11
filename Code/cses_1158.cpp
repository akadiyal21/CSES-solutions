#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#define  ll long long 
#define pr first  //price
#define pg second //pages
int dp[1000][100005];
using namespace std;
int main()
{
	ll n,x; cin>>n>>x;
  vector <pair<ll,ll> > arr(n);
	
	for(ll i = 0;i<n;i++)
	{
		cin>>arr[i].first; 
	}
	for(ll i = 0;i<n;i++)
	{
		cin>>arr[i].second;
	}
	sort(arr.begin(),arr.end());
	for(ll i = 0;i<n;i++)
	{
		for(ll j = 0;j<=x;j++)
		{
			if(i==0)
			{
				if(j-arr[i].pr>=0)
				{
					dp[i][j]+=arr[i].pg;
				}
			}
			else
		  {
				if(j-arr[i].pr>=0)
					dp[i][j] = max((ll)dp[i-1][j],(ll)(dp[i-1][j-arr[i].pr]+arr[i].pg));
			}
		}
	}
	cout<<dp[n-1][x]<<endl;
	return 0;
}
