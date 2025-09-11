#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define ll long long
typedef struct
{
	ll l;
	ll r;
	ll index;
}range;
ll cmp(range r1, range r2)
{
	if(r1.l<r2.l) return 1;
	else if(r1.l==r2.l) return r1.r>r2.r;
	else return 0;
//	return r1.l<r2.l;
}
using namespace std;
int main()
{
	ll n; cin>>n; vector <range> arr(n);
	for(ll i = 0;i<n;i++)
	{
		ll l,r; cin>>l>>r;
		arr[i].l = l; arr[i].r=r; 
		arr[i].index = i;
	}
	sort(arr.begin(),arr.end(),&cmp);
	ll inside[n]; ll outside[n]; memset(inside,0,sizeof(ll)*n); memset(outside,0,sizeof(ll)*n);
	ll max_right = arr[0].r;
	for(ll i = 1;i<n;i++)
	{
		if(arr[i].r<=max_right)
		{
			inside[arr[i].index] = 1;
		}
		else
	  {
			max_right = arr[i].r;
		}
	}
	ll min_right = arr[n-1].r;
	for(ll i = n-2;i>=0;i--)
	{
		if(arr[i].r>=min_right)
		{
			outside[arr[i].index] = 1;
		}
		else min_right = arr[i].r;
	}
	for(ll i = 0;i<n;i++)
	{
		cout<<outside[i]<<" ";
	}
	cout<<endl;
	for(ll i = 0;i<n;i++)
	{
		cout<<inside[i]<<" ";
	}
	cout<<endl;
	return 0;
}
