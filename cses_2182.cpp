#include<iostream>
#include<unordered_map>
#define ll long long
using namespace std;
ll m = (ll) 1000000007;
//ll arr[1000005];
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
ll mod_inv(ll x,ll m)
{
	return mod_exp(x,m-2,m);
}
int main()
{
	ll n; cin>>n; ll num_div = 1; ll prod=1; ll sum_div = 1; ll num_div_mod = 1;ll flag = 0;ll half_prod = 1; ll flag1=0,flag2=0;ll num_div_mod_1 = (-1+m);
	ll correction=0;

	while(n--)
	{
		ll x,k; 
		cin>>x>>k;
		ll k_temp=k;		
		if(k%2==1){
			flag=1;
			if(flag1==0){
			k_temp = (k+1)/2; flag1=1;}
			else{
				k_temp = k+1;
			}
		}
		else{
			k_temp = k+1;
			
		}
		num_div = (((1+k)%m)*(num_div%m))%m;
		num_div_mod = ((k_temp)*(num_div_mod))%(m-1);
		prod = ((prod%m)*mod_exp(x,k,m))%m;

		half_prod = ((half_prod%m)*mod_exp(x,k/2,m))%m;
		sum_div = ((((sum_div)*(mod_inv(x-1,m)))%m)*((mod_exp(x,k+1,m)-1+m)%m));
		sum_div%=m;
	//	cout<<"#### "<<mod_inv(x-1,m)<<" #### "<< (mod_exp(x,k+1,m)-1+m)%m<<endl;
	}
	cout<<num_div<<" "<<sum_div<<" ";
	// (n+1)/2 in mod m 
	//ll nplus12 = (mod_inv(2,m)*((num_div_mod+1)%m))%m;
	if(flag==0)
	{
		num_div_mod = (num_div_mod-1 + m-1)%(m-1);
		cout<<((mod_exp(half_prod,num_div_mod,m))*(half_prod))%m<<endl;
	}
	else
  {
		//cout<<nplus12<<"$$$$"<<num_div_mod<<endl;
		num_div_mod = ((correction+1)*num_div_mod)%(m-1);
		cout<<mod_exp(prod,num_div_mod,m)<<endl;
	}
}
