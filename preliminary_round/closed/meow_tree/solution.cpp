#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)x.size()

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin>>n;
	vector<vector<int>>adj(n);
	
	for(int i=0; i<n-1; i++){
		int u,v; cin>>u>>v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int64_t ans=0;
	int cnt=0;
	
	auto dfs=[&](auto &&dfs, int u, int p, int d)->void{
		ans+=d;
		for(int &v:adj[u]){
			if(v==p)continue;
			dfs(dfs,v,u,d+1);
		}
		if(sz(adj[u])==1)cnt++;
	};
	
	dfs(dfs,0,-1,0);
	cout<<ans<<" "<<cnt<<"\n";
	
	return 0;
}

