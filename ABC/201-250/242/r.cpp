#include <iostream>
#include<algorithm>
#include<atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int main(){
  string s;
  cin >> s;
  int Q;
  cin >>Q;
  while(Q--){
    long long t,k;
    cin >> t >> k;
    k--;
    int sid = 0;
    if(t > 60) sid = 0;
    else sid = k/(1LL<<t);
    long long order = 0;
    if(t > 60) order = k;
    else order = k%(1LL<<t);
    int cnt = 0;
    while(order){
      if(order%2 == 1) cnt++;
      order/=2;
    }
    int now = -1;
    if(s[sid] == 'A') now = 0;
    else if(s[sid] == 'B') now = 1;
    else now = 2;
    long long left = t - cnt;
    left %= 3;
    now += left;
    now %= 3;
    now += cnt*2;
    now %= 3;
    string abc = "ABC";
    cout << abc[now] << endl;
  }
}


