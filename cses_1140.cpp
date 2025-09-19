#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#define ll long long 
using namespace std;
ll cmp(pair <pair<ll,ll>, ll> a,pair <pair<ll,ll>, ll> b)
{
	if(a.first.second==b.first.second) return 0; 
	return a.first.second < b.first.second; 
}
using Job = pair<pair<ll,ll>, ll>; // {{start, end}, value}

// For sort: compare two elements (must return bool)
bool sortByEndThenStart(const Job& a, const Job& b) {
    if (a.first.second != b.first.second) return a.first.second < b.first.second; // end time
    return a.first.first < b.first.first;                                        // tie-break by start
}
bool endLessThanStart(const Job& job, const ll& startTime) {
    return job.first.second < startTime;
}
int main()
{	
	ll n; cin>>n; 

	vector <pair<pair <ll,ll>,ll > > a(n); 
	for(ll i = 0;i<n;i++)
	{
		cin>>a[i].first.first>>a[i].first.second>>a[i].second; 
	}
	sort(a.begin(),a.end(),cmp); 
	ll dp[n+1];
	ll prefix_dp[n+1]; 
	dp[0] = 0; 
	prefix_dp[0] = 0; 
	//cout<<"hola"<<endl;
	for(ll i = 1;i<=n;i++)
	{
		dp[i] = a[i-1].second; 
		//for(ll j = 0;j<i-1;j++)
		//{
			
		auto it = lower_bound(a.begin(),a.begin()+i,a[i-1].first.first,endLessThanStart);
		ll pos = it-a.begin(); 
		if(pos-1>=0)
		{
			dp[i] = max(dp[i],prefix_dp[pos]+a[i-1].second); 
		}
			/*if(a[j].first.second<a[i-1].first.first)
			{
				//cout<<i<<" i *** j "<<j<<" dp "<<dp[j]<<endl;
				dp[i] = max(dp[i],dp[j+1]+a[i-1].second); 
			}*/
		//}
		prefix_dp[i] = max(prefix_dp[i-1],dp[i]);
	}
	cout<<*max_element(dp,dp+n+1)<<endl;
	/*for(ll i = 0;i<=n;i++)
		cout<<dp[i]<<" ";
	cout<<endl;*/
	return 0;

}
