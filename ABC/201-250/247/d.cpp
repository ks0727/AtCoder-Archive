#include <iostream>
#include <set>
#include <queue>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int Q;
  cin>> Q;
  queue<P> q;
  while(Q--){
    int type;
    cin >> type;
    if(type == 1){
      int x,c;
      cin >> x >> c;
      q.emplace(x,c);
    }
    if(type == 2){
      int c;
      cin >> c;
      ll now = 0;
      while(1){
        if(q.size() == 0) break;
        if(q.front().second <= c){
          c -= q.front().second;
          now += (ll)q.front().first*q.front().second;
          q.pop();
        }else{
          break;
        }
      }
      if(c > 0){
         q.front().second -= c;
         now += (ll)q.front().first*c;
       }
       cout << now << endl;
    }
  }
      
  return 0;
}

