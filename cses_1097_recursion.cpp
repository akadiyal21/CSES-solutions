#include<iostream>
#include<vector> 
#define ll long long  
using namespace std;
// val (a,l,r,state) --> optimal score of the player with label state when we start at (l,r)
// val (a,l,r,state1) --> optimal score of player state2 given that it's the turn of player with label state1; 
ll val_table[5001][5001][2][2]; 
ll ready[5001][5001][2][2]; 
ll val(vector <ll> &a, ll l, ll r, ll state1,ll state2)
{
	if(ready[l][r][state1][state2]) return val_table[l][r][state1][state2]; 
	if(l==r)
	{
		if(state1==state2)
		{
			ready[l][r][state1][state2]=1;
			val_table[l][r][state1][state2] = a[l] ;
			return a[l];
		}//player zero gets the remaining element
		else
		{
			ready[l][r][state1][state2]=1;
			val_table[l][r][state1][state2]=0;
			return 0; 
		}// player 1 takes the remaining stuff; 
		//return a[l];
	}
	if(state1==state2)
	{
		ll left = a[l] + val(a,l+1,r,state1,1-state1);
		ll right = a[r] + val(a,l,r-1,state1,1-state1);
		if(left>right) 
		{
			val_table[l][r][state1][state2] = left;
			ready[l][r][state1][state2] = 1;
			return left; 
		}
		else 
		{
			val_table[l][r][state1][state2] = right; 
			ready[l][r][state1][state2] = 1;
			return right; 
		}
	}
	else
	{
		// we now have to choose the strategy for player two; 
		ll left = a[l] + val(a,l+1,r,1-state1,1-state2);
		ll right = a[r] + val(a,l,r-1,1-state1,1-state2); 
		if(left>right)
		{
			val_table[l][r][state1][state2] = val(a,l+1,r,1-state1,state2); 
			ready[l][r][state1][state2] = 1; 
			return val_table[l][r][state1][state2] ;
		}
		else 
		{
			val_table[l][r][state1][state2] = val(a,l,r-1,1-state1,state2); 
			ready[l][r][state1][state2] = 1;
			return val_table[l][r][state1][state2]; 
		}
	}
}
int main()
{
	ll n;cin>>n;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector <ll> a(n); 
	for(ll i = 0;i<n;i++) cin>>a[i];
	cout<<val(a,0,n-1,0,0)<<endl;
	return 0; 
}
