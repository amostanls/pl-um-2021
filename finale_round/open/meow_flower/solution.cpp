#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define ld long double
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m,k; cin>>n>>m>>k;
	vector<string>s(n+1);
	vector<vector<int>>dp(n+1,vector<int>(m+1,0));
	for(int i=1; i<=n; i++){
		cin>>s[i];
	}
	int total = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			total+=(s[i][j-1]=='1');
			dp[i][j]=s[i][j-1]-'0';
			dp[i][j]+=dp[i][j-1];
		}
		for(int j=1; j<=m; j++){
			dp[i][j]+=dp[i-1][j];
		}
	}
	int lo=0, hi=min(n,m),ans=0;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		int area = mid*mid;
		bool ok = 0;
		for(int i=mid; i<=n && !ok; i++){
			for(int j=mid; j<=m; j++){
				int curr = dp[i][j]-dp[i-mid][j]-dp[i][j-mid]+dp[i-mid][j-mid];
				int outside = min(total-curr,k);
				if(curr+outside>=area){
					ok=1;
					break;
				}
			}
		}
		if(ok){
			lo=mid+1;
			ans=area;
		}else{
			hi=mid-1;
		}
	}
	cout<<ans<<"\n";
	return 0;
}

