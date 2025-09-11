#include<iostream>
#define ll long long 
ll m = 1000000007;
using namespace std;
int main()
{
	
	ll n; cin>>n;
	ll arr[n+1]; arr[1] = 0; arr[2]=1;
	for(ll i = 3;i<=n;i++)
	{
		arr[i] = ((i-1)*((arr[i-1]+arr[i-2])%m))%m;
	}
	cout<<arr[n]<<endl;
	return 0;
}
