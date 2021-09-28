#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin>>N;
	set<string>ss;
	int ans=0;
	string tmp;
	getline(cin,tmp);
	for(int i=0; i<N; i++){
		getline(cin,tmp);
		//cerr<<i<<" "<<tmp<<"\n";
		for(int j=0; j<tmp.length(); j++){
			if('A'<=tmp[j]&&tmp[j]<='Z'){
				tmp[j] = tmp[j]-'A'+'a';
			}
		}
		if(ss.find(tmp)==ss.end())ans+=tmp.length();
		ss.insert(tmp);
	}
	cout<<ans<<"\n";
}

