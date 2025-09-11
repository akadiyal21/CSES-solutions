#include<iostream>
#define ll long long 
using namespace std;

int main()
{
	ll n; cin>>n;
	while(n!=1)
	{
		cout<<n<<" ";
		if(n%2==0)
		{
			n/=2;
		}
		else
	  {
			n*=3; n++;
		}
	}
	cout<<1<<endl;
}
