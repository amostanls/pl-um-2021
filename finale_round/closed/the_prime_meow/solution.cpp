#include <bits/stdc++.h>

using namespace std;

//sieve
vector<bool> prime;
vector<int> primes;
vector<int64_t> prefix;
vector<int>smallest;
 
void sieve(int maximum) {
    maximum = max(maximum, 1);
    prime.assign(maximum + 1, true);
    prefix.resize(maximum+1);
    smallest.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};
	smallest[0]=smallest[1]=1;
	prefix[0]=0;
	prefix[1]=1;
	
    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            primes.push_back(p);
			prefix[p]=prefix[p-1];
            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest[i]=p;
                }
        }else{
			prefix[p]=prefix[p-1]+(int64_t)p;
		}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin>>n;
	int64_t sum=0;
	vector<int>a(n); for(auto &x:a)cin>>x;
	vector<int>b(n); for(auto &x:b)cin>>x;
	
	const int mxn = int(1e6)+5;
	sieve(mxn);
	
	auto calc = [&](int x)->int64_t{
		return prefix[x];
	};
	
	for(int i=0; i<n; i++){
		int64_t res=calc(b[i])-calc(a[i]-1);
		sum += res;
	}
	
	cout<<sum<<"\n";
	return 0;
}

