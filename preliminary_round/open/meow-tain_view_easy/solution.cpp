#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin>>N;
	vector<int>H(N),V(N,1); for(auto &x:H)cin>>x;
	for(int i=0; i<N; i++){
		//left
		int j=i-1;
		int mx=0,cnt=0;
		while(j>=0){
			if(H[j]>mx){
				mx=H[j];
				cnt++;
			}
			j--;
		}
		V[i]+=cnt;
		//right
		mx=0,cnt=0;
		j=i+1;
		while(j<N){
			if(H[j]>mx){
				mx=H[j];
				cnt++;
			}
			j++;
		}
		V[i]+=cnt;
	}
	for(int i=0; i<N; i++){
		if(i)cout<<" ";
		cout<<V[i];
	}
	cout<<"\n";
	return 0;
}


