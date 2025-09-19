#include<string>
#include<iostream>
#include<cstring>
#define ll long long 
ll arr[1000005];
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
	ll max = 1000001;
	factorial_build(max,m);
	string s; cin>>s;
	ll alph[27]; memset(alph,0,27*sizeof(ll));
	for(ll i=0;i<s.size();i++) alph[s[i]-'a']++;
	ll ans = arr[s.size()];//cout<<" n fact "<<arr[s.size()]<<endl;
	for(ll i = 0;i<27;i++)
	{
		if(alph[i]==0) continue;
		//cout<<"  loop "<<alph[i];
		ans = (ans*mod_inv(arr[alph[i]],m))%m;
		//cout<<" ans "<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
