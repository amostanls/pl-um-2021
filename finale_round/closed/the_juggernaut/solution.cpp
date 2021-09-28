#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e6+5;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int A,B,N; cin>>A>>B>>N;
	vector<int>a(N); for(auto &x:a)cin>>x;
	int C = __gcd(A,B);
	int ans=0;
	for(int i=0; i<N; i++){
		if(a[i]>A+B){
			ans++;
			continue;
		}
		if(!(abs(A-a[i])%C==0||abs(B-a[i])%C==0)){
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}

