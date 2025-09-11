#include<iostream>
#include<string>
#define ll long long 
using namespace std;
int main()
{
	string s; cin>>s; ll curr_streak = 1; ll max_streak = 1;
	for(ll i = 1;i<s.size();i++)
	{
		if(s[i]==s[i-1]) curr_streak++;
		else { if(curr_streak>max_streak) max_streak = curr_streak; curr_streak=1;}
	}
	cout<<max(max_streak,curr_streak)<<endl;
	return 0;
}
