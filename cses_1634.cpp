#include<iostream>
#include<cstring>
#include<climits>
#define ll long long
using namespace std;
int main()
{
	ll n,m; cin>>n>>m; ll c[n];ll arr[m+1]; 
	//memset(arr,-1,sizeof(ll)*(m+1));
	for(ll i = 1;i<=m;i++) arr[i] = INT_MAX;
	arr[0]=0;
	for(ll i = 0;i<n;i++)
	{
		cin>>c[i];
	}
	for(ll i = 0;i<=m;i++)
	{
		for(ll j = 0;j<n;j++)
		{
			if(i+c[j]<=m)
			{
				//cout<<i<<"<--i "<<c[j]<<" i+c[j] "<<i+c[j]<<endl;
				arr[i+c[j]] = min(arr[i]+1,arr[i+c[j]]);
			}
		}
	}
	if(arr[m]==INT_MAX) cout<<-1<<endl;
	else
		cout<<arr[m]<<endl;
}
