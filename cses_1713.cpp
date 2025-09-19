#include<iostream>
#include<vector>
using namespace std; 
#define ll long long 
const long long siz = 1000005;
ll arr[siz];
int main()
{
	
	ll n; cin>>n;vector<ll> primes;
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	for(ll i = 2;i<siz;i++)
	{
		if(arr[i]==0)
		{
			//primes.push_back(i);
			arr[i]=i;
			for(ll p = 2*i;p<siz;p+=i)
			{
				arr[p] = i; //store largest prime factor;
			}
		}
	}
	//for(auto &x:primes) cout<<x<<endl;
	while(n--)
	{
		ll x; cin>>x;
		ll prod = 1;
		if(arr[x]==x)
		{
			cout<<2<<endl; continue;
		}
		//ll prod = 1;
		while(x!=1)
		{
			ll prim = arr[x];
			ll temp = x; 
			ll count=1;
			while(x%prim==0)
			{
				x/=prim;
				count++;
			}
			prod*=count;
		}
		/*for(ll i = 0;i<primes.size();i++)
		{
			if(primes[i]>x)
			{
				break;
			}
			ll temp = x; ll count = 1;
					prod*=count;
		}*/
		//if(arr[x]==0) cout<<2<<endl;
		cout<<prod<<endl;
	}
	return 0;
}
