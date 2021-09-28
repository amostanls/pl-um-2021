#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin>>N;
	vector<int>H(N),V(N,1); for(auto &x:H)cin>>x;
	vector<int>stack_h;
	for(int i=0; i<N; i++){
		V[i]+=stack_h.size();
		while(!stack_h.empty()&&stack_h.back()<=H[i]){
			stack_h.pop_back();
		}
		stack_h.push_back(H[i]);
	}
	stack_h.clear();
	for(int i=N-1; i>=0; i--){
		V[i]+=stack_h.size();
		while(!stack_h.empty()&&stack_h.back()<=H[i]){
			stack_h.pop_back();
		}
		stack_h.push_back(H[i]);
	}
	for(int i=0; i<N; i++){
		if(i)cout<<" ";
		cout<<V[i];
	}
	cout<<"\n";
	return 0;
}

