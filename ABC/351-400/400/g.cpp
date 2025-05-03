#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main(){
  const int M = 1000000;
  vector<int> p(M+1);
  for(int i=0;i<=M;i++) p[i] = i;
  for(int i=2;i*i <= M;i++){
    if(p[i] == i){
      for(int j =i*i; j<=M;j+=i){
        if(p[i] == j) p[j] = i;
      }
    }
  }

  vector<int> dp(M+1);
  for(int k=2;k<=M;k++){
    int x = k;
    int prev = 0;
    int cnt = 0;
    while(x > 1){
      int fac = p[x];
      if(fac != prev){
        cnt++;
        prev = fac;
      }
      x /= fac;
    }
    dp[k] = cnt;
  }
  vector<ll> numbers;
  for(int i=2;i<=M;i++){
    if(dp[i] == 2){
      numbers.push_back((ll)i*i);
    }
  }
  sort(numbers.begin(),numbers.end());
  int q;
  cin >> q;
  for(;q--;){
    ll a;
    cin >> a;
    auto it = upper_bound(numbers.begin(),numbers.end(),a);
    if(it != numbers.begin()) it--;
    cout << *it << endl;
  }
  return 0;
}
