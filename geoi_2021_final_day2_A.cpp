#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int c=1,n,m,a,b,cnt[100005],fix[100005];
vector<int> v[100005];
map<int,map<int,int> > mp;
int fb(int u,int uu)
{
	if (cnt[u])
		return cnt[u];
	cnt[u]=c++;
	int ans=cnt[u];
	for (int i=0; i<v[u].size(); i++)
	{
		if (v[u][i]==uu)
			continue;
		int x=fb(v[u][i],u);
		if (x>cnt[u])
		{
			mp[u][v[u][i]]=1;
			mp[v[u][i]][u]=1;
		}
		ans=min(ans,x);
	}
	cnt[u]=ans;
	return cnt[u];
}
ll coun(int u)
{
	if (fix[u])
		return 0;
	ll ans=1;
	fix[u]=1;
	for (int i=0; i<v[u].size(); i++)
	{
		if (mp[u][v[u][i]])
			continue;
		ans+=coun(v[u][i]);
	}
	return ans;
}
ll anss;
int main()
{
	cin>>n>>m;
	for (int i=0; i<m; i++)
	{
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	int temp=fb(1,1);
	for (int i=1; i<=n; i++)
	{
		if (fix[i])
			continue;
		ll cc=coun(i);
		anss+=cc*(cc-1ll)/2ll;
	}
	cout<<anss<<endl;
	return 0;
}
