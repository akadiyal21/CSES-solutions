#include<iostream>
#define ll long long 
ll arr[2000010];
ll m = 1000000007;
ll factorial_build(ll max, ll m)
{
	arr[0]=1;
	for(ll i = 1;i<=max;i++)
	{
		arr[i] = (arr[i-1]*i)%m;
	}
	return 0;
}
ll mod_exp(ll x, ll n)
{
	if(n==1) return x%m;
	if(n==0) return 1;
	ll a = mod_exp(x,n/2);
	if(n%2) return (((a*a)%m)*x)%m;
	return (a*a)%m;
}
ll mod_inv(ll x, ll m)
{
	return mod_exp(x,m-2);
}
using namespace std;
int main()
{
	ll max = 2000002;
	factorial_build(max,m);
	ll t=1; while(t--){
		ll n,r ; cin>>n>>r;
		//cout<<arr[n+r-1]<<" "<<arr[n]<<" "<<arr[r-1]<<endl;
		cout<<(((arr[n+r-1]*mod_inv(arr[n-1],m))%m)*mod_inv(arr[r],m))%m<<endl;
	}
	return 0;
}
