#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long 
using namespace std;
/*class segment_tree 
{
public: 
	segment_tree(ll a[]; ll n)
	{
		// find the minimum power of 2 greater than the current 
	}
private: 
	vector <ll> &segment_tree;
};*/

ll query(vector <ll> &segtree, ll l, ll r, ll curr_l, ll curr_r, ll curr_idx)
{
	cout<<l<<" "<<r<<" "<<curr_l<<" "<<curr_r<<" "<<curr_idx<<endl;
	
	if((l==curr_l)&&(r==curr_r)) return segtree[curr_idx];
	if(curr_l==curr_r) return segtree[curr_idx];
	ll sum = 0; 
	ll mid = (curr_l+curr_r)/2;
	if(l<=mid)
		sum+=query(segtree,l,r,curr_l,(curr_l+curr_r)/2,2*curr_idx);
	if(mid+1<=r)
		sum+=query(segtree,l,r,(curr_l+curr_r)/2+1,curr_r,2*curr_idx+1);
	return sum;
}
vector <ll> segtree(ll a[], ll n)
{
	if(n==1)
	{
		vector <ll> seg(1,a[0]); 
		return seg; 
	}
	ll log = 0;
	ll tmp = n;
	while(tmp!=0)
	{
		log+=1;
		tmp/=2; 
	}
	ll N = 1<<log; 
	vector <ll> seg(N,0);
	ll new_n = (1<<(log-1));
	cout<<new_n<<endl;
	for(ll i = 0;i<new_n;i++)
	{
		if(i<n)
			seg[N-1-i] = a[n-i-1];
	}
	for(ll i = N-n-1;i>0;i--)
	{
		seg[i] = seg[2*i]+seg[2*i+1];
	}
	return seg; 
}
int main()
{
	ll n; cin>>n; 
	ll a[n]; for(ll i = 0;i<n;i++) cin>>a[i]; 
	auto v = segtree(a,n); 
	for(auto x:v) cout<<x<<" ";
	cout<<endl;
	cout<<query(v,0,n-1,0,n-1,1)<<endl;
	return 0; 
}
