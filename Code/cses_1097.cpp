#include<iostream>
#include<vector> 
#include<algorithm> 
using namespace std; 
#define ll long long 
ll ready[5000][5000][2];
ll val[5000][5000][2];
ll removal(vector <ll> &a, ll l, ll r, ll choice)
{
	if(ready[l][r][choice]) return val[l][r][choice];
	
	//cout<<l+1<<" *** "<<r<<" ### "<<1-choice<<removal(a,l+1,r,1-choice)<<endl;
	if(choice == 0)
		val[l][r][choice] = max(a[l] + removal(a,l+1,r,1-choice),a[r] + removal(a,l,r-1,1-choice));
	else 
		val[l][r][choice] = (((a[l]+ removal(a,l+1,r,1-choice))<(a[r]+removal(a,l,r-1,1-choice))))? removal(a,l+1,r,1-choice):removal(a,l,r-1,1-choice);
	
	ready[l][r][choice] = 1;
	/*cout<<l<<" l *** r "<<r<<" choice "<<choice<<" *** val "<<val[l][r][choice]<<endl; */
	return val[l][r][choice]; 
}
int main()
{
	ll n; cin>>n; 
	vector <ll> a(n); 
	for(ll i = 0;i<n;i++) cin>>a[i]; 
	for(ll i = 0;i<n;i++)
	{
		val[i][i][0] = a[i]; 
		val[i][i][1] = 0;
		ready[i][i][0] = 1;
		ready[i][i][1] = 1;
	}
	cout<<removal(a,0,n-1,0)<<endl;
/*	for(ll i = 0;i<n;i++)
	{
		for(ll j = 0;j<n;j++)
		{
			cout<<val[i][j][0]<<" "; 
		}
		cout<<endl;
	}
	for(ll i = 0;i<n;i++)
	{
		for(ll j = 0;j<n;j++)
		{
			cout<<val[i][j][1]<<" "; 
		}
		cout<<endl;
	}

	ll l=0,r=n-1; ll sum = 0; ll choice = 0;*/
	return 0; 
}
