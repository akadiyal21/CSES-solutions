#include<iostream>
#include<algorithm>
//#include<unordered_map>
#define ll long long
using namespace std;
ll sieve[1000001];
ll mp[1000001];
ll mobius(ll k)
{
	if(k==1) return 1; 
	ll num_p = 0;
	while(k!=1)
	{
		num_p++;
		ll count = 0;
		ll t = sieve[k]==0? k:sieve[k] ;
		while(k%t==0)
		{
			count++;
			k/=t;
		}
		if(count>=2) return 0;
	}
	if(num_p%2==0) 
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int main()
{
	ll n; cin>>n;ll arr[n]; //unordered_map <ll,ll> mp;
	for(ll i = 0;i<n;i++) { cin>>arr[i]; mp[arr[i]]++;}
	for(ll i = 2;i<=1000000;i++)
	{
	  if(sieve[i]==0)
		{
			for(ll j = 2*i;j<=1000000;j+=i)
			{
				sieve[j] = i;
			}
		}
	}
	/*for(ll i = 1;i<=20;i++)
	{
		cout<<sieve[i]<<" ";
	}
	cout<<endl;*/
	sort(arr,arr+n);
	//ll p = 100000
	ll maxi = arr[n-1]; ll ans = 0;
	for(ll i = 1;i<=maxi;i++)
	{
		ll num_d = 0;
		for(ll j=i;j<=maxi;j+=i)
		{
			num_d += mp[j];
		}
		ans += mobius(i)*(num_d*(num_d-1))/2;
	}
	cout<<ans<<endl;
	/*for(ll i = 1;i<=20;i++)
	{
		cout<<mobius(i)<<" **** <- "<<i<<endl;
	}*/
	//cout<<endl;
	return 0;
}
