#include<iostream>
#include<cstring>
#define ll unsigned long long
using namespace std;
ll check_digit(ll n, ll digit)
{
	while(n!=0)
	{
		if(digit==n%10)
		{
			return 1;
		}
		n=n/10;
	}
	return 0;
}
ll dp[1000005];
int main()
{
	ll n; cin>>n; 
	//ll arr[n]; 
	/*for(ll i = 0;i<n;i++)
	{
		cin>>arr[i];
	}*/
	memset(dp+1,0xFF,sizeof(ll)*n);
	for(ll i = 0;i<n;i++)
	{
		for(ll j = 1;j<=9;j++)
		{
			if(check_digit(i+j,j))
			{
				dp[i+j]=min(dp[i+j],dp[i]+1);
			}
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}
