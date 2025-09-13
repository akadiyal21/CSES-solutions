#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long 
using namespace std;
class segment_tree{
public:
	//vector <ll> tree; 
	segment_tree(ll a[], ll n)
	{
		this->n = n; 
		if(n==1)
		{
			vector <ll> seg(2,a[0]); 
			vector <ll> h1(2,0);
			this->h = h1; 
			this->tree = seg; 
			this->N = 2;
			this->n_pad = 1;
			//return seg; 
		}
		else 
	{
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
			vector <ll> h1(seg.size(),0);
			this->tree = seg;  
			this->h = h1;
			this->N = N; 
			this->n_pad = N/2; 
		}
		//return seg; 
	}
	ll query(ll l, ll r)
	{
		return query_p(l,r,0,this->n_pad-1,1,0);
	};
	void update_range(ll l, ll r, ll val)
	{
		update_range_p(l,r,0,this->n_pad-1,1,val);
	};
	void update_element(ll ind,ll val)
	{
		update_p(ind, val); 
	}
private: 
	ll n; 
	ll N;
	ll n_pad;
	vector <ll> tree; 
	vector <ll> h; 
	ll query_p(ll l, ll r, ll curr_l, ll curr_r, ll curr_idx, ll add)
	{
		add+= this->h[curr_idx];
		vector <ll> &segtree = this->tree;
		if((l<=curr_l)&&(r>=curr_r)) return segtree[curr_idx]+ add*(curr_r-curr_l+1);
		if(curr_l==curr_r) return segtree[curr_idx] + add;
		ll sum = 0; 
		ll mid = (curr_l+curr_r)/2;
		//add += h[curr_idx]; 
		if(l<=mid)
			sum+=query_p(l,r,curr_l,(curr_l+curr_r)/2,2*curr_idx,add);
		if(mid+1<=r)
			sum+=query_p(l,r,(curr_l+curr_r)/2+1,curr_r,2*curr_idx+1,add);
		return sum;//(r-l+1)*h[curr_idx];

	};
	void update_range_p(ll l, ll r, ll curr_l, ll curr_r, ll curr_idx,ll val)
	{
		vector <ll> &seg = this->tree; 
		vector <ll> &h = this->h; 
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
			update_range_p(l,r,curr_l,(curr_l+curr_r)/2,2*curr_idx,val);
		if(mid+1<=r)
			update_range_p(l,r,(curr_l+curr_r)/2+1,curr_r,2*curr_idx+1,val);
		return ;
	};
	void internal_upd(ll ind)
	{
		vector <ll> &seg = this->tree;
		if(ind==0) 
		{
			return ;
		} 
		seg[ind] = seg[2*ind]+seg[2*ind+1]; 
		this->internal_upd(ind/2);
		return ; 
	}
	void update_p(ll ind, ll val)
	{
		vector <ll> &seg = this->tree;
		seg[this->N/2 + ind] = val; 
		this->internal_upd((this->N/2+ind)/2);
		return ; 
	}

};


int main()
{
	ll n,q; cin>>n>>q; 
	ll a[n]; for(ll i = 0;i<n;i++) cin>>a[i]; 

	segment_tree v(a,n);
	for(ll i = 0;i<q;i++)
	{
		/*ll k,l,r;cin>>k>>l>>r;
		if(k==2)
		{
			cout<<v.query(l-1,r-1)<<endl;
		}
		else
		{
			v.update_element(l-1,r);
		}*/
		ll k;  cin>>k;
		ll l,r,val; 
		if(k==2)
		{
			cin>>l;
			cout<<v.query(l-1,l-1)<<endl;
		}
		//cin>>k>>l>>r>>val;
		
		if(k==1)
		{
			cin>>l>>r>>val;
			v.update_range(l-1,r-1,val); 
		}
	}
	//cout<<v.query(0,2)<<endl;
	//v.update_element(0,2);
	//vector.update_element(n-1,3);
	//cout<<v.query(0,0)<<endl;
	/*auto v = segtree(a,n); 
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
	}*/
	return 0; 
}
