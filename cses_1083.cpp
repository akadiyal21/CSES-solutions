#include<iostream>
#define ll long long 
using namespace std;
ll arr[200005];
int main()
{
	ll n; cin>>n;
	for(ll i = 0;i<n-1;i++)
	{
		ll temp; cin>>temp; arr[temp]=1;
	}
	for(ll i = 1;i<=n;i++)
	{
		if(arr[i]==0) {cout<<i<<endl; break;}
	}
}
