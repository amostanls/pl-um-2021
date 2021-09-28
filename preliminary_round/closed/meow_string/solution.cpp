#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,q; cin>>n>>q;
	string s; cin>>s;
	vector<int>left(q),right(q);
	for(int i=0; i<q; i++){
		cin>>left[i]>>right[i];
		left[i]--;
		right[i]--;
	}
	vector<int>dp(n,0);
	for(int i=0; i<n; i++){
		if(i)dp[i]=dp[i-1];
		if(i&&s[i-1]=='M'&&s[i]=='E')dp[i]++;
	}
	for(int i=0; i<q; i++){
		int res=dp[right[i]]-dp[left[i]];
		cout<<res<<"\n";
	}
	return 0;
}

