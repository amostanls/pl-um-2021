#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define debug(x) cout << #x << " is " << x << endl
#define endl '\n'
 
int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int n; cin >> n;
  ll total = 0;
  for (int i = 0; i < n; i++)
  {
    int num; cin >> num;
    total += 4*i*num;
  }
  cout << total << endl;
  return 0;
}
