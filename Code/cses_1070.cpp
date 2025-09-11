#include<iostream>
#define ll long long 
using namespace std;
int main()
{
	ll n ; cin>>n; 
	if(n==1) {cout<<1<<endl; return 0;}
	if(n<4) cout<<"NO SOLUTION"<<endl;
	else{
		if(n==4){ cout<<"2 4 1 3"<<endl; return 0;}
		for(ll i = 1;i<=n;i++)
		{
			if(i%2==1)
				cout<<i<<" ";
		}
		for(ll i = 1;i<=n;i++)
		{
			if(i%2==0)
				cout<<i<<" ";
		}
		cout<<endl;
	}
	return 0;
}
