#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long 
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
	for(ll i = 0;i<n;i++)
	{
		for(ll j=0;j<=m;j++)
		{
			if(j-c[i]>=0)
				arr[j] = (arr[j]+arr[j-c[i]]%mod)%mod;
		}
	}
			//arr[i]=arr[i]%mod;
	
	ll ans = arr[m]%mod;
	cout<<ans%mod<<endl;
	return 0; 
}
