#include <bits/stdc++.h>

using namespace std;

const int mxn = 3e3+5;

int a[mxn][mxn*2];
int dp[mxn][mxn*2];
int cnt[mxn][2];


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin>>n;
	for(int i=0; i<n; i++){
		string s; cin>>s;
		int m = (int)s.length();
		for(int j=0; j<m; j++){
			a[i][j]=(s[j]=='1');
		}
	}
	
	memset(dp,0,sizeof(dp));
	for(int i=n-1; i>=0; i--){
		for(int j=0; j<2*i+1; j+=2){
			if(i==n-1){
				dp[i][j]=a[i][j];
			}else if(a[i][j]==1&&a[i+1][j+1]==1){
				dp[i][j]=min(dp[i+1][j],dp[i+1][j+2])+1;
			}else if(a[i][j]==1){
				dp[i][j]=1;
			}
			cnt[dp[i][j]][1]++;
		}
	}
	for(int i=n-1; i>=0; i--){
		cnt[i][1]+=cnt[i+1][1];
	}
	
	memset(dp,0,sizeof(dp));
	for(int i=n-1; i>=0; i--){
		for(int j=0; j<2*i+1; j+=2){
			if(i==n-1){
				dp[i][j]=!a[i][j];
			}else if(a[i][j]==0&&a[i+1][j+1]==0){
				dp[i][j]=min(dp[i+1][j],dp[i+1][j+2])+1;
			}else if(a[i][j]==0){
				dp[i][j]=1;
			}
			cnt[dp[i][j]][0]++;
		}
	}
	for(int i=n-1; i>=0; i--){
		cnt[i][0]+=cnt[i+1][0];
	}
	
	for(int i=1; i<=n; i++)
		cout<<cnt[i][0]<<" \n"[i==n];
	for(int i=1; i<=n; i++)
		cout<<cnt[i][1]<<" \n"[i==n];
	return 0;
}

