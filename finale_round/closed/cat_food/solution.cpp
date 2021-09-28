#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,x; cin>>n>>x;
	int prev = 0;
	int sum = 0;
	vector<pair<int,int>>segments;
	for(int i=0; i<n; i++){
		int le,ri; cin>>le>>ri;
		segments.emplace_back(le,ri);
	}
	sort(segments.begin(),segments.end());
	for(int i=0; i<n; i++){
		int le=segments[i].first-1;
		int ri=segments[i].second;
		int dif = le-prev;
		sum += (dif%x)+(ri-le);
		prev = ri;
	}
	cout<<sum<<"\n";
	return 0;
}

