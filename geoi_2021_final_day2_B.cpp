#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
int n,a,b,s,f,p[200005],y[200005],ff[200005],ss[100005];
vector<int> v[200005],aa;
pair<int,int> cnt(int u)
{
	pair<int,int> ans=mp(0,0);
	if (u==f)
		ans.S=1;
	if (v[u].size()==1 && v[u][0]==p[u])
	{
		y[u]=1;
		ans.F=1;
		return ans;
	}
	for (int i=0; i<v[u].size(); i++)
	{
		if (v[u][i]==p[u])
			continue;
		p[v[u][i]]=u;
		pair<int,int> temp=cnt(v[u][i]);
		if (temp.S)
		{
			ans.F=max(ans.F,1);
			ans.S=1;
			continue;
		}
		ans.F=max(ans.F,temp.F+1);
	}
	y[u]=ans.F;
	return ans;
}
int u,x,c,ans;
int main()
{
	cin>>n;
	for (int i=0; i<n-1; i++)
	{
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	cin>>s>>f;
	p[s]=s;
	pair<int,int> temp=cnt(s);
	u=f;
	x=0;
	while (p[u]!=u)
	{
		u=p[u];
		x++;
	}
	u=f;
	while (p[u]!=u)
	{
		aa.pb(y[u]);
		u=p[u];
	}
	aa.pb(y[s]);
	for (int i=0; i<aa.size(); i++)
	{
		if (i==0)
		{
			ff[i]=aa[i];
			continue;
		}
		ff[i]=max(ff[i-1],aa[i]+i);
	}
	for (int i=aa.size()-1; i>=0; i--)
	{
		if (i==aa.size()-1)
		{
			ss[i]=aa[i];
			continue;
		}
		ss[i]=max(ss[i+1],(int)(aa[i]+aa.size()-1-i));
	}
	for (int i=0; i<aa.size()-1; i++)
		ans=max( ans, min( ff[i],ss[i+1] ) );
	cout<<ans<<endl;
	return 0;
}
