#include<iostream>
using namespace std;
#define ll long long
ll mod_exp(ll a,ll n,ll m)
{
	if(n==0) return 1;
	if(n==1) return a%m;
	if(n%2==0)
	{
		ll temp = mod_exp(a,n/2,m);
		return (temp*temp)%m;
	}
	else
  {
		ll temp = mod_exp(a,n/2,m);
		return (((temp*temp)%m)*a%m)%m;
	}
}
int main()
{
	ll n; cin>>n; ll m = 1000000007;
	while(n--)
	{
		ll a,b,c; cin>>a>>b>>c;
		cout<<mod_exp(a,mod_exp(b,c,m-1),m)<<endl;
	}
	return 0;
}
