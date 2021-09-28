#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int A,B,N; cin>>A>>B>>N;
	int C,D,E,F; cin>>C>>D>>E>>F;
	vector<int>c(N); for(auto &x:c)cin>>x;
	cout<<abs(A-C-E)<<"\n";
	return 0;
}

