 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200010];
int main()
{
   ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		ll ans=a[1]-1;
		for(ll i=2;i<=n;i++)
		{
			if(a[i]>a[i-1])
			ans+=a[i]-a[i-1];
		}
		cout <<ans<<endl;
	}
} 