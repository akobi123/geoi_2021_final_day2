#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[15][105][105],ndp[15][105][105],n,mid=1000000007;
void cnt(ll u,ll l,ll k,ll nsh,ll p)
{
	p%=mid;
	while (nsh<0)
		nsh+=11;
	nsh%=11;
	if (!l && !k)
	{
		dp[nsh][0][0]+=p;
		dp[nsh][0][0]%=mid;
		return;
	}
	if (l>0)
		cnt(u+1,l-1,k,nsh-u,(p*l)%mid);
	if (k>0)
		cnt(u+1,l,k-1,nsh+u,(p*k)%mid);
	return;
}
ll nsh,tnsh,ans;
int main()
{
	cin>>n;
	if (n<=9)
	{
		cnt(1,(n+1)/2,n/2,0,1);
		cout<<dp[0][0][0]<<endl;
		return 0;
	}
	cnt(1,5,4,0,1);
//	cout<<dp[10][0][0]*5*11+dp[1][0][0]*5*11<<endl;
	for (ll i=10; i<=n; i++)
	{
		nsh=i/10-i%10;
		while (nsh<0)
			nsh+=11;
		nsh%=11;
		for (ll nn=0; nn<11; nn++)
			for (ll lw=0; lw<i-9; lw++)
			{
				ll tkn=i-9-1-lw;
				//luw adgilas
				tnsh=nn-nsh;
				while (tnsh<0)
					tnsh+=11;
				tnsh%=11;
				dp[tnsh][lw+1][tkn]+=
					dp[nn][lw][tkn]*(5+lw);
				dp[tnsh][lw+1][tkn]%=mid;
				//kent adgilas
				tnsh=nn+nsh;
				while (tnsh<0)
					tnsh+=11;
				tnsh%=11;
				dp[tnsh][lw][tkn+1]+=
					dp[nn][lw][tkn]*(5+tkn);
				dp[tnsh][lw][tkn+1]%=mid;
			}
	}
	for (ll lw=0; lw<=n-9; lw++)
	{
		ans+=dp[0][lw][n-9-lw];
		ans%=mid;
	}
	cout<<ans<<endl;
	return 0;
}
