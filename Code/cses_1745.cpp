#include<iostream>
#include<cstring>
#include<vector> 
#include<algorithm>
#define ll long long 
using namespace std;
int main()
{
	ll n; cin>>n; 
	ll arr[n+1]; ll sum = 0; 
	arr[0] = 0;
	for(ll i = 1;i<=n;i++)
	{
		cin>>arr[i]; sum+=arr[i];
	}
	ll dp[sum+1];
	memset(dp,0, sizeof(ll)*(sum+1));
	vector <ll> sums; 
	sums.push_back(0);
	for(ll i = 1;i<=n;i++)
	{
		/*cout<<i<<" ### "<<endl;
		for(auto &x:sums)
		{
			cout<<x<<" *** ";
		}
		cout<<endl;*/
		vector <ll> tmp; 
		for(ll j = 0;j<sums.size();j++)
		{
			//cout<<sums[j]+arr[i]<<endl;
			if(dp[sums[j]+arr[i]]==0)
			{
				//cout<<"adding **** "<<sums[j]+arr[i]<<endl;
				tmp.push_back(sums[j]+arr[i]);
				//sums.push_back(sums[j]+arr[i]);
				dp[sums[j]+arr[i]]=1;
			}
		}
		for(ll k = 0;k<tmp.size();k++)
		{
			sums.push_back(tmp[k]);
		}
	}
	cout<<sums.size()-1<<endl;
	sort(sums.begin(),sums.end());
	for(auto &x:sums)
	{
		if(x!=0)
		cout<<x<<" ";
	}
	cout<<endl;
	return 0; 
}
