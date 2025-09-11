#include<iostream>
#include<cstring>
#include<algorithm>
#define ll unsigned long long 
long long arr[1000005];
using namespace std;
const ll mod = (ll)1000000007;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,m; cin>>n>>m;
	 ll c[n]; //memset(arr,0,sizeof(ll)*(m+1));
	for(ll i = 0;i<n;i++)
		cin>>c[i];
	sort(c,c+n);
	arr[0] = 1;
	for(ll i = 0;i<=m;i++)
	{
		for(ll j = 0;j<n;j++)
		{
			if(i+c[j]<=m)
			{
				arr[i+c[j]] = (arr[i+c[j]] + (arr[i]))%mod;	
				//cout<<i<<"<--i "<<i<<" i+c[j] "<<i+c[j]<<" arr->"<<arr[i+c[j]]<<endl;
			}
			if(i+c[j]>m)
		  {
				break;
			}
		}
		//arr[i]=arr[i]%mod;
	}
	ll ans = arr[m]%mod;
	cout<<ans%mod<<endl;
	return 0; 
}
