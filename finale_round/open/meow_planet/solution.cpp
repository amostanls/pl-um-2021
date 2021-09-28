#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin>>n;
	vector<int>a(n); for(auto &x:a)cin>>x;
	sort(a.begin(),a.end());
	int ans1=0,ans2=1e9;
	for(int i=0; i<n; i++){
		{
			int res = min((i==0?1e9:a[i]-a[i-1]),(i==n-1?1e9:a[i+1]-a[i]));
			ans1=max(ans1,res);
		}
		{
			int res = max((i==0?0:a[i]-a[0]),(i==n-1?0:a[n-1]-a[i]));
			ans2=min(ans2,res);
		}
	}
	cout<<ans1<<" "<<ans2<<"\n";
	return 0;
}

