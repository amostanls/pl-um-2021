#include <bits/stdc++.h>

using namespace std;

const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin>>N>>M;
	vector<string>s(N); for(auto &x:s)cin>>x;
	
	int sx=-1, sy=-1, ex=-1, ey=-1;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(s[i][j]=='S'){
				sx=i,sy=j;
			}
			if(s[i][j]=='E'){
				ex=i,ey=j;
			}
		}
	}
	
	int ans = (int)2e9;
	int SO = (int)1e9, EO = (int)1e9;
	vector<vector<int>>dist(N,vector<int>(M,(int)1e9));
	
	auto valid = [&](int x, int y)->bool{
		return (0<=x&&x<N&&0<=y&&y<M);
	};
	
	auto visit_start = [&]()->void{
		dist[sx][sy]=0;
		queue<pair<int,int>>q;
		q.emplace(sx,sy);
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if(s[x][y]=='O'){
				SO = min(SO,dist[x][y]);
			}
			if(s[x][y]=='E'){
				ans = dist[x][y];
				return;
			}
			for(int k=0; k<4; k++){
				int X = x+dx[k];
				int Y = y+dy[k];
				if(valid(X,Y)&&s[X][Y]!='#'&&dist[X][Y]>dist[x][y]+1){
					dist[X][Y]=dist[x][y]+1;
					q.emplace(X,Y);
				}
			}
		}
		return;
	};
	
	auto visit_end = [&]()->void{
		for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
				dist[i][j]=(int)1e9;
		dist[ex][ey]=0;
		queue<pair<int,int>>q;
		q.emplace(ex,ey);
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if(s[x][y]=='O'){
				EO = min(EO,dist[x][y]);
			}
			for(int k=0; k<4; k++){
				int X = x+dx[k];
				int Y = y+dy[k];
				if(valid(X,Y)&&s[X][Y]!='#'&&dist[X][Y]>dist[x][y]+1){
					dist[X][Y]=dist[x][y]+1;
					q.emplace(X,Y);
				}
			}
		}
		return;
	};
	
	visit_start();
	visit_end();
	
	//cerr<<SO<<" "<<EO<<" "<<ans<<"\n";
	
	if(SO+EO<ans&&SO!=(int)1e9&&EO!=(int)1e9){
		ans = SO+EO;
	}
	if(ans==(int)2e9){
		ans = -1;
	}
	cout<<ans<<"\n";
	
	return 0;
}

/* S -> O -> E
 * S -> E
 */  

