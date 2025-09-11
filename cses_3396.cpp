#include<iostream>
#include<vector>
#define ll long long 
using namespace std;

ll arr[1000005];
ll lim = 1000005;
int main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL); vector<ll> prime;
	//build sieve
	for(ll i = 2;i<=lim;i++)
	{
		if(arr[i]!=0) continue;
		prime.push_back(i);
		for(ll j = i*i;j<=lim;j+=i)
			arr[j] = 1;
	}
	//for(auto &x:prime) cout<<x<<endl;
	ll t; cin>>t;

	while(t--)
	{
		ll n; cin>>n;
		if(n==1){ cout<<2<<endl; continue;}
		ll next = (n%2==0)?n+1:n+2;
		for(ll j = next;;j+=2)
		{
			//if(j%2==0) continue;
			ll flag = 0;
			for(ll k = 0;(prime[k]*prime[k]<=j)&&(k<=prime.size());k++)
			{
				if(j%prime[k]==0)
				{
					flag = 1;
					break;
				}
			}
			if(flag==0) {cout<<j<<"\n"; break;}
		}
	}
}
