#include <bits/stdc++.h>
     
using namespace std;
     
void multi(int64_t &a, int64_t b, const int64_t &MOD){
    	a%=MOD; b%=MOD;
    	a=((a*b)%MOD+MOD)%MOD;
}
     
void add(int64_t &a, int64_t b, const int64_t &MOD){
    	a%=MOD; b%=MOD;
    	a=((a+b)%MOD+MOD)%MOD;
}
     
int64_t modpow(int64_t a, int64_t b, const int64_t &MOD){
    	int64_t res = (int64_t)1;
    	while(b){
    		if(b&1)multi(res,a,MOD);
    		multi(a,a,MOD);
    		b>>=1;
    	}
    	return res;
}
     
int main(){
    	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    	int N,P; cin>>N>>P;
    	vector<int>aa(N),bb(N);
    	for(auto &x:aa)cin>>x;
    	for(auto &x:bb)cin>>x;
    	int64_t sum = 0;
    	for(int i=0; i<N; i++){
    		int64_t res = aa[i];
    		multi(res,bb[i],P);
    		add(sum,res,P);
    	}
    	
    	auto check = [&](int x)->bool{
    		//check for ascii
    		if('0'<=x&&x<='9')return true;
    		if('a'<=x&&x<='z')return true;
    		if('A'<=x&&x<='Z')return true;
    		return false;
    	};
    	
    	int64_t div = modpow(sum,P-2,P);
    	int64_t mx = 2054847098 ;
    	int M=1;
    	for(int i=0; i<M; i++){
    		vector<string>ans;
    		int64_t E; cin>>E;
    		multi(E,div,P);
    		while(true){
    			int64_t curr = E;
    			if(curr>mx)break;
    			int a = curr >> 24;
    			curr -= a << 24;
    			int b = curr >> 16;
    			curr -= b << 16;
    			int c = curr >> 8;
    			curr -= c << 8;
    			int d = curr;
    			if(check(a)&&check(b)&&check(c)&&check(d)){
    				string ss = string(1,a)+string(1,b)+string(1,c)+string(1,d);
    				ans.push_back(ss);
    			}
    			E+=P;
    		}
    		for(auto x:ans)cout<<x<<" ";
    		cout<<"\n";
    	}
	return 0;
}
     
/* a = 16^6 = (2^24)
* b = 16^4 = (2^16)
* c = 16^2 = (2^8)
* d = 16^0 = (2^0)
* E/sum = M, keep adding P until max
* max(M) = 2054847098 
*/ 
