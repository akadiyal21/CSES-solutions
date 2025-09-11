#include<iostream>
#include<algorithm>
#define ll long long 
using namespace std;
int main()
{
	ll n; cin>>n; ll arr[n]; ll ans = 0;
	for(ll i = 0;i<n;i++) { 
		cin>>arr[i];
		if(i>=1){
			ans+= max(-arr[i]+arr[i-1],(ll)0);
			arr[i]+=max(-arr[i]+arr[i-1],(ll)0);
		}
	}
	cout<<ans<<endl;
	
}
