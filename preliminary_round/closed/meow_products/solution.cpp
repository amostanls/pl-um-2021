#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int A,B,C,D,X,Y,Z; cin>>A>>B>>C>>D>>X>>Y>>Z;
	int res = A*X+B*Y+C*Z;
	{
		int resA = X*3*D;
		if(Y>X)resA+=(Y-X)*B;
		if(Z>X)resA+=(Z-X)*C;
		res=min(res,resA);
	}
	{
		int resB = Y*3*D;
		if(X>Y)resB+=(X-Y)*A;
		if(Z>Y)resB+=(Z-Y)*C;
		res=min(res,resB);
	}
	{
		int resC = Z*3*D;
		if(X>Z)resC+=(X-Z)*A;
		if(Y>Z)resC+=(Y-Z)*B;
		res=min(res,resC);
	}
	cout<<res<<"\n";
	return 0;
}

