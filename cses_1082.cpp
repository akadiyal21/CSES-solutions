#include <climits>
#include<iostream>
#include<math.h>
using namespace std;
#define ll unsigned long long
ll mod = (ll)(1000000007);
ll mod_mult(ll a, ll b);
ll mod_sum(ll a, ll b);
ll brute_force(ll n,ll mod)
{
	ll sume = 0;
	for(ll i = 1;i<=n;i++)
	{
		sume+= ((i%mod) * ((n/i)%mod))%mod;
		sume %=mod;
	}
	return sume;
}
ll mod_mult(ll a, ll b)
{
	return ((a%mod)*(b%mod))%mod;
}
ll mod_sum(ll a, ll b)
{
	return (a%mod + b%mod)%mod;
}
ll opt_solution(ll n, ll mod)
{
	ll sume = 0;
	ll stop_val = -1;
	for(ll i = 1;i*i<=n;i++)
	{
		sume = mod_sum(sume,mod_mult(i,n/i));
		stop_val = i;
	}
	ll l = stop_val+1;
	while(l<=n)
	{
		ll r = n/(n/l); 
		ll num_elements_sum = (r-l);
		//sume += (((((num_elements_sum+1)%mod)*l)%mod + ((((num_elements_sum%mod)*((num_elements_sum+1)%mod))/2)%mod)*((n/l)%mod)))%mod ;
		//
		
		ll a = mod_mult((num_elements_sum+1),l);
		ll b;
		if (num_elements_sum%2==0)
			b = mod_mult((num_elements_sum/2),(num_elements_sum+1));
		else
			b = mod_mult((num_elements_sum),((num_elements_sum+1)/2));

		//ll b =(((num_elements_sum*(num_elements_sum+1)))/2)%mod;
		ll c = mod_sum(a,b);
		 
		sume +=  mod_mult(c,(n/l)) ;
		sume %= mod;

			l = r+1; 
	}
	return sume%mod;
}
int main()
{
		ll n; cin>>n; ll sume = 0; ll stop_val = -1;
		
	// run testcases
  //cout<<brute_force(n,mod)<<endl;		
	cout<<opt_solution(n,mod)<<endl;
	//cout<<brute_force(n,mod)<<endl;
	/*for(ll i = 2;i<=200;i++)
	 {
		if(opt_solution(i,mod)==brute_force(i,mod))
		{
			continue;
		}
		else
	  {
			cout<<"NOT OK "<<i<<endl;
		}
	}*/
	return 0;
}
