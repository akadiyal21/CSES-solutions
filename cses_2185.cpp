#include<iostream>
#include<stdint.h>
#include<assert.h>
#define ll long long //uint_64_t
using namespace std;
ll calculate_coprime(ll mask,ll *arr, ll n)
{
	//cout<<"mask "<<mask<<endl;
	ll idx = 0; ll ret = 1;
	while(mask!=0)
	{
		if(mask%2) {
			if(ret>(__int128)n/arr[idx])
				return n+1;
			ret*=arr[idx];}
		
		idx++;
		mask/=2;
	}
	return ret;
}
ll cal_num_bits(ll mask)
{
	ll bits = 0;
	while(mask!=0)
	{
		bits += mask%2;
		mask = mask>>1;
	}
	return bits;
}
int main()
{

	ll n,k; cin>>n>>k; ll arr[k];
	for(ll i = 0;i<k;i++) cin>>arr[i];
	
	ll count = 0; 
	for(ll i = 1;i<((1ULL<<(k)));i++)
	{
		//cout<<i<<" <- mask ";
		ll num_bits = cal_num_bits(i);
		//cout<<" num_bits "<<num_bits<<endl;
		//assert(calculate_coprime(i,arr)==1);
		
		if(num_bits%2) count += n/calculate_coprime(i,arr,n);
		//else count -= n/calculate_coprime(i,arr);
	}
	for(ll i = 1;i<((1<<(k)));i++)
	{
		//cout<<i<<" <- mask ";
		ll num_bits = cal_num_bits(i);
		//cout<<" num_bits "<<num_bits<<endl;
		if(num_bits%2==0) count -= n/calculate_coprime(i,arr,n);
	}

	cout<<count<<endl;
	return 0;
}
