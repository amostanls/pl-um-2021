#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	int a[n]; 
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n%2)cout<<a[1]<<" "<<a[n/2]<<" "<<a[n-2]<<"\n";
	else{
		cout<<a[1]<<" ";
		if((a[n/2-1]+a[n/2])%2)cout<<fixed<<setprecision(1)<<double(a[n/2-1]+a[n/2])/2;
		else cout<<(a[n/2-1]+a[n/2])/2;
		cout<<" "<<a[n-2]<<"\n";
	}
}

