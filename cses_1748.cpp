#include<iostream>
#include<cstring>
#include<vector> 
#include<algorithm>
#define ll long long 
const ll mod = 1000000007;
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
		return query_p(l,r,0,this->n_pad-1,1,0)%mod;
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
		return sum%mod;//(r-l+1)*h[curr_idx];

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
		seg[ind] = (seg[2*ind]%mod+seg[2*ind+1]%mod)%mod; 
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
	ll n; cin>>n;
	vector <ll> arr(n); 
	for(ll i = 0;i<n;i++) cin>>arr[i]; 

	auto a1 = arr; 
	sort(a1.begin(),a1.end());
	// index compression
	for(ll i = 0;i<n;i++)
	{
		ll pos = lower_bound(a1.begin(),a1.end(),arr[i]) - a1.begin()+1; 
		arr[i] = pos;
	}
	//ll mp[n];
	ll a2[n+1]; memset(a2,0,sizeof(ll)*(n+1));
	a2[0]=1;
	segment_tree seg = segment_tree(a2,n+1);

	/*for(ll i = 0;i<n;i++)
		cout<<arr[i]<<" "; 
	cout<<endl;*/
	//ll dp[n];
	//for(ll i = 0;i<n;i++) dp[i]=1;
	for(ll i=0;i<n;i++)
	{
		ll tmp = seg.query(0,arr[i]-1);
		ll tmp1 = seg.query(arr[i],arr[i]);
		seg.update_element(arr[i],tmp+tmp1); 
		/*for(ll j = 0;j<i;j++)
		{
			if(arr[i]>arr[j])
				dp[i] = (dp[i]%mod + dp[j]%mod)%mod;  
		}*/
	}
	cout<<seg.query(0,n)-1<<endl;
	return 0; 
}
