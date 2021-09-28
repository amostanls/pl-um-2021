#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin>>N;
	vector<string>s(N+1);
	vector<vector<char>>var(N+1);
	for(int i=0; i<N+1; i++){
		cin>>s[i];
		reverse(s[i].begin(),s[i].end());
	}
	
	bool OK = true;
	for(int mask = 0; mask<(1<<5) && OK; mask++){
		vector<bool>val(5,false);
		for(int i=0; i<5; i++)val[i]=(mask>>i&1);
		for(int i=0; i<N+1; i++){
			vector<bool>stack;
			
			for(int j=0; j<(int)s[i].length(); j++){
				if('p'<=s[i][j]&&s[i][j]<='t'){
					stack.push_back(val[s[i][j]-'p']);
				}else if(s[i][j]=='!'){
					stack.back()=!stack.back();
				}else if(s[i][j]=='&'){
					bool fi = stack.back(); stack.pop_back();
					stack.back()=(stack.back()&&fi);
				}else if(s[i][j]=='|'){
					bool fi = stack.back(); stack.pop_back();
					stack.back()=(stack.back()||fi);
				}else if(s[i][j]=='='){
					bool fi = stack.back(); stack.pop_back();
					stack.back()=(stack.back()==fi);
				}else{
					//implies ->
					//not p or q for p->q
					//I reverse previously, it makes no diff, lmao
					bool fi = stack.back(); stack.pop_back();
					stack.back()=(stack.back()||!fi);
				}
			}
			if(stack.back()==0){
				//if i<N, straight break, dont use this
				//if all true, but conclusion false, too bad
				if(i==N)OK=0;
				break;
			}
		}
	}
	cout<<(OK?"Yes":"No")<<"\n";
	return 0;
}

