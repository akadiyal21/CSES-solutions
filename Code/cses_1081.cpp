#include<iostream>
#include<map>
#include<stdio.h>
#include<cstring>
#include<unordered_map>
#define ll long long 
//ll mp[1000005];
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n; cin>>n;
	ll arr[n]; 
	ll maxi = 0;
	unordered_map<ll,ll> mp;
	for(ll i = 0;i<n;i++)
	{
		cin>>arr[i];
		maxi = max(maxi,arr[i]);
		mp[arr[i]]++;
	}
	//potential gcd
	//ll gcd_arr[maxi+1];
	//memset(gcd_arr,0,sizeof(ll)*(maxi+1));	
	for(ll i = maxi;i>=1;i--)
	{
		ll count = 0;
		for(ll j = i;j<=maxi;j+=i)
		{
			count+=mp[j];
		}
		if(count>=2)
		{
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
