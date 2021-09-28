#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s; cin>>s;
	int ans = 1;
	vector<bool>used(1,false);
	vector<int>curr;
	
	auto segments = [&](int x, vector<int>&y)->void{
		vector<int>res;
		while(x>0){
			res.push_back(x%10);
			x/=10;
		}
		reverse(res.begin(),res.end());
		y = res;
		return;
	};
	
	segments(1,curr);
	int ptr = -1;
	
	for(char ch:s){
		int cur = ch-'0';
		
		bool ok=false;
		
		for(int i=ptr+1; i<(int)curr.size(); i++){
			if(cur==curr[i]&&!used[i]){
				used[i]=true;
				ok=true;
				ptr=i;
				break;
			}
		}
		if(!ok){
			for(int a=1; a<=10; a++){
				int now = ans+a;
				vector<int>tmp;
				segments(now,tmp);
				int ind = -1;
				for(int i=0; i<(int)tmp.size(); i++){
					if(tmp[i]==cur){
						ind=i;
						break;
					}
				}
				if(ind!=-1){
					ans=now;
					curr=tmp;
					ptr=ind;
					used.assign(curr.size(),false);
					used[ind]=true;
					break;
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}

