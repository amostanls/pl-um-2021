#include <bits/stdc++.h>

using namespace std;

const int dx[2][6]={{-1,-1,0,0,1,1},{-1,-1,0,0,1,1}};
const int dy[2][6]={{0,1,-1,1,0,1},{-1,0,-1,1,-1,0}};

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int r,c; cin>>r>>c;
	vector<string>s(r);
	vector<pair<int,int>>bunny,meow;
	for(int i=0; i<r; i++){
		cin>>s[i];
		for(int j=0; j<c; j++){
			if(s[i][j]=='b')bunny.emplace_back(i,j);
			else if(s[i][j]=='m')meow.emplace_back(i,j);
		}
	}
	vector<vector<bool>>vis(r,vector<bool>(c,false));
	
	auto check = [&](int x, int y)->bool{
		return (0<=x&&x<r&&0<=y&&y<c);
	};
	
	auto visit = [&](int x, int y)->void{
		if(vis[x][y])return;
		queue<pair<int,int>>q;
		q.emplace(x,y);
		while(!q.empty()){
			x = q.front().first;
			y = q.front().second;
			q.pop();
			if(vis[x][y])continue;
			vis[x][y]=true;
			for(int i=0; i<6; i++){
				int X=x+dx[x%2][i];
				int Y=y+dy[x%2][i];
				if(check(X,Y)&&!vis[X][Y]&&s[X][Y]!='m'){
					q.emplace(X,Y);
				}
			}
		}
	};
	
	for(auto &[x,y]:bunny){
		visit(x,y);
	}
	
	int ans=0;
	for(auto &[x,y]:meow){
		bool bongo=false;
		for(int i=0; i<6; i++){
			int X=x+dx[x%2][i];
			int Y=y+dy[x%2][i];
			if(check(X,Y)&&vis[X][Y]){
				bongo=true;
				break;
			}
		}
		ans+=bongo;
	}
	cout<<ans<<'\n';
	return 0;
}

