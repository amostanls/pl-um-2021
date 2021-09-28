#include <bits/stdc++.h>

using namespace std;

#define ii pair<int,int>
#define fi first
#define se second
#define ld long double
#define vi vector<int>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define eb emplace_back

const int mxn = (int)3e5+5;

int meowness[mxn];

struct DSU{
	vector<int>par;
	vector<int>low, high;
	int cc;
	void init(int n){
		par.resize(n+1);
		low.resize(n+1);
		high.resize(n+1);
		for(int i=0; i<=n; i++)par[i]=i,low[i]=i,high[i]=i;
		cc=n;
	}
	int rt(int u){
		if(par[u]!=u)par[u]=rt(par[u]);
		return par[u];
	}
	bool merge(int u, int v){
		u=rt(u); v=rt(v);
		if(u==v)return 0;
		if(meowness[low[v]]<meowness[low[u]])low[u]=low[v];
		if(meowness[high[v]]>meowness[high[u]])high[u]=high[v];
		par[v]=u;
		cc--;
		return 1;
	}
	bool sameset(int u, int v){
		u=rt(u); v=rt(v);
		return u==v;
	}
	void answer(int u){
		u=rt(u);
		cout<<low[u]<<" "<<high[u]<<"\n";
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N,Q;
	cin>>N>>Q;
	for(int i=1; i<=N; i++){
		cin>>meowness[i];
	}
	DSU dsu; dsu.init(N);
	while(Q--){
		int t; cin>>t;
		if(t==1){
			int u,v; cin>>u>>v;
			dsu.merge(u,v);
		}else{
			int u; cin>>u;
			dsu.answer(u);
		}
	}
	return 0;
}

