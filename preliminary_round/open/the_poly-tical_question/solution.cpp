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

const int MOD=32000011;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vector<int>c(n);
	for(auto &x:c)cin>>x;
	int x_1,x_2; cin>>x_1>>x_2;
	int64_t curr1=1,curr2=1;
	int64_t res1=0,res2=0;
	for(int i=0; i<n; i++){
		int64_t tmp1=curr1;
		multi(tmp1,c[i],MOD);
		add(res1,tmp1,MOD);
		
		int64_t tmp2=curr2;
		multi(tmp2,c[i],MOD);
		add(res2,tmp2,MOD);
		
		multi(curr1,x_1,MOD);
		multi(curr2,x_2,MOD);
	}
	if(res1<res2)cout<<"Meowhathir la";
	else if(res1>res2)cout<<"Mewyiddin la";
	else cout<<"Nevermind la";
	cout<<endl;
	return 0;
}
