#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#define ll long long 
using namespace std;
ll query(vector <ll> &segtree, ll l, ll r, ll curr_l, ll curr_r, ll curr_idx)
{
	if((l<=curr_l)&&(r>=curr_r)) return segtree[curr_idx];
	if(curr_l==curr_r) return segtree[curr_idx];
	ll sum = LLONG_MAX; 
	ll mid = (curr_l+curr_r)/2;
	if(l<=mid)
		sum =query(segtree,l,r,curr_l,(curr_l+curr_r)/2,2*curr_idx);
	if(mid+1<=r)
		sum = min(sum,query(segtree,l,r,(curr_l+curr_r)/2+1,curr_r,2*curr_idx+1));
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
	ll tmp = 1;
	while(tmp<n)
	{
		log+=1;
		tmp*=2; 
	}
	ll N = 2*tmp; 
	vector <ll> seg(N,0);
	ll new_n = N/2;
	//cout<<new_n<<endl;
	for(ll i = 0;i<n;i++)
	{
		//if(i<n)
			seg[N/2+i] = a[i];
	}
	for(ll i = tmp-1;i>0;i--)
	{
		seg[i] = min(seg[2*i],seg[2*i+1]);
	}
	return seg; 
}
void internal_upd(vector <ll> &seg,ll ind)
{
	if(ind==0) 
	{
		return ;
	} 
	seg[ind] = min(seg[2*ind],seg[2*ind+1]); 
	internal_upd(seg,ind/2);
	return ; 
}
void update(vector <ll> &seg, ll ind, ll val)
{
	seg[seg.size()/2 + ind] = val; 
	internal_upd(seg,(seg.size()/2+ind)/2);
	return ; 
}
int main()
{
	ll n,q; cin>>n>>q; 
	ll a[n]; for(ll i = 0;i<n;i++) cin>>a[i]; 
	auto v = segtree(a,n); 
	ll N = 1;
	while(N<n)
	{
		N*=2; 
	}
	for(ll i = 0;i<q;i++)
	{
		ll l,r; cin>>l>>r;
		//if(k==2)
			cout<<query(v,l-1,r-1,0,N-1,1)<<endl;
		/*if(k==1)
		{
			update(v,l-1,r); 
		}*/
	}
	return 0; 
}
