#include <iostream>
#include<deque>
using namespace std;

int main(){
  int Q;
  cin >> Q;
  deque<pair<int,int> > q;
  while(Q--){
    int type;
    cin >> type;
    if(type == 1){
      int c,x;
      cin >> c >> x;
      q.emplace_back(x,c);
    }else{
      int k;
      cin >> k;
      long long ans = 0;
      while(true){
        auto [x,c] = q.front(); q.pop_front();
        if(c > k){
          int rest = c-k;
          ans += (long long)x*k;
          q.emplace_front(x,rest);
          break;
        }else{
          ans += (long long)x*c;
          k -= c;
          if(k == 0) break;
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}

