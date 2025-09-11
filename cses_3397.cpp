#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
ll arr[21]; 
ll find_digit(ll *n,ll *k, vector<ll> &digits)
{
	if((*n)==1) { *k = 0; return digits[0]; }
	ll ind = (*k-1)/arr[*n-1];
	ll ret = digits[ind];
	digits.erase(digits.begin()+ind);
	*k = *k - ind*arr[*n-1];
	*n = *n - 1;
	return ret ; 
}
int main()
{
	arr[0] = 1;
	for(ll i = 1;i<21;i++) arr[i]=arr[i-1]*i;
	ll t; cin>>t;
	while(t--)
	{
		ll c;cin>>c;
		if(c==1)
		{
			vector<ll> ans; vector <ll> digits;
			ll n,k;cin>>n>>k;
			for(ll i = 1;i<=n;i++)  digits.push_back(i);
			while(k)
			{
				//cout<<k<<" ### "<<endl;
				ans.push_back(find_digit(&n,&k,digits));
			}
			for(ll i = 0;i<ans.size();i++)
			{
				cout<<ans[i]<<" ";
			}
			cout<<endl;
		}
		else
	  {
			//cout<<"hola"<<endl;
			ll n; cin>>n; ll counter = n-1; ll ans = 1; vector<ll> digits; 
			for(ll i = 1;i<=n;i++) digits.push_back(i);
			for(ll i = 0;i<n;i++)
			{ 
				ll a; cin>>a; 
				ll pos =(ll) (find(digits.begin(),digits.end(),a)-digits.begin());
				ans += (pos)*arr[counter]; counter--; digits.erase(digits.begin()+pos);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
