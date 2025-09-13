#include<iostream>
#include<map>
#define ll long long 
using namespace std;
int main()
{
	ll n; cin>>n;
	map <ll,ll> mp; 
	for(ll i = 0;i<n;i++)
	{
		ll tmp; cin>>tmp; 
		mp[tmp]++;
	}
	cout<<mp.size()<<endl;
	return 0; 
}
