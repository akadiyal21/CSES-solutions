#include<iostream>
#include<vector> 
#define ll long long
using namespace std;
int main()
{
	ll n,q; cin>>n>>q; 
	ll a[n]; 
	for(ll i = 0;i<n;i++) cin>>a[i];
	ll prefix[n+1]; prefix[0] = 0;
	for(ll i = 1;i<=n;i++) prefix[i] = prefix[i-1]+a[i-1];
	for(ll i = 0;i<q;i++)
	{
		ll a,b; cin>>a>>b;  
		cout<<prefix[b]-prefix[a-1]<<endl;
	} 
	/*for(ll i = 0;i<n+1;i++)
	{
		cout<<prefix[i]<<" ";
	}
	cout<<endl;*/
	return 0; 
}
