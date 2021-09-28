#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long 
#define ii pair<int,int>
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define vi vector<int>
template<class T> using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin>>n;
	vector<int>a(n); for(auto &x:a)cin>>x;
	bool ok = true;
	bool par = true;
	for(int i=n-1; i>=0; i--){
		if((a[i]&1)!=par)ok=false;
		par = !par;
	}
	if(!ok){
		cout<<-1<<"\n";
		return 0;
	}
	int64_t ans=0;
	oset<int>odd, even;
	for(int i=0; i<n; i++){
		if(a[i]%2==0){
			//even
			ans += even.order_of_key(a[i]);
			even.insert(a[i]);
		}else{
			//odd
			ans += odd.order_of_key(a[i]);
			odd.insert(a[i]);
		}
	}
	cout<<ans<<"\n";
	return 0;
}

