#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long 
using namespace std;
ll query(vector <ll> &h, vector <ll> &segtree, ll l, ll r, ll curr_l, ll curr_r, ll curr_idx,ll add)
{

	add+= h[curr_idx];
	if((l<=curr_l)&&(r>=curr_r)) return segtree[curr_idx]+ add*(curr_r-curr_l+1);
	if(curr_l==curr_r) return segtree[curr_idx] + add;
	ll sum = 0; 
	ll mid = (curr_l+curr_r)/2;
	//add += h[curr_idx]; 
	if(l<=mid)
		sum+=query(h,segtree,l,r,curr_l,(curr_l+curr_r)/2,2*curr_idx,add);
	if(mid+1<=r)
		sum+=query(h,segtree,l,r,(curr_l+curr_r)/2+1,curr_r,2*curr_idx+1,add);
	return sum;//(r-l+1)*h[curr_idx];
}
vector <ll> segtree(ll a[], ll n)
{
	if(n==1)
	{
		vector <ll> seg(2,a[0]); 
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
		seg[i] = seg[2*i]+seg[2*i+1];
	}
	return seg; 
}
void internal_upd(vector <ll> &seg,ll ind)
{
	if(ind==0) 
	{
		return ;
	} 
	seg[ind] = seg[2*ind]+seg[2*ind+1]; 
	internal_upd(seg,ind/2);
	return ; 
}
void update(vector <ll> &seg, ll ind, ll val)
{
	seg[seg.size()/2 + ind] = val; 
	internal_upd(seg,(seg.size()/2+ind)/2);
	return ; 
}
void update_range(vector<ll> &h, vector <ll> &seg, ll l, ll r, ll curr_l, ll curr_r, ll curr_idx,ll val)
{
	if((l<=curr_l)&&(r>=curr_r))
	{
		h[curr_idx]+=val;
		return ;
	}
	if(curr_l==curr_r)
	{
		h[curr_idx]+=val;
		return ;
	}
	ll sum = 0; 
	ll mid = (curr_l+curr_r)/2;
	if(l<=mid)
		update_range(h,seg,l,r,curr_l,(curr_l+curr_r)/2,2*curr_idx,val);
	if(mid+1<=r)
		update_range(h,seg,l,r,(curr_l+curr_r)/2+1,curr_r,2*curr_idx+1,val);
	return ;

}
int main()
{
	ll n,q; cin>>n>>q; 
	ll a[n]; for(ll i = 0;i<n;i++) cin>>a[i]; 
	auto v = segtree(a,n); 
	vector <ll> h(v.size(),0);
	ll N = 1;
	while(N<n)
	{
		N*=2; 
	}
	for(ll i = 0;i<q;i++)
	{
		ll k;  cin>>k;
		ll l,r,val; 
		if(k==2)
		{
			cin>>l;
			cout<<query(h,v,l-1,l-1,0,N-1,1,0)<<endl;
		}
		//cin>>k>>l>>r>>val;
		
		if(k==1)
		{
			cin>>l>>r>>val;
			update_range(h,v,l-1,r-1,0,N-1,1,val); 
		}
	}
	return 0; 
}
