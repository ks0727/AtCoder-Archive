#include <iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
  int Q;
  cin >> Q;
  long long now = 0;
  priority_queue<long long,vector<long long>,greater<long long> > q;
  while(Q--){
    int type;
    cin >> type;
    if(type == 1){
      q.push(now);
    }
    else if(type == 2){
      long long t;
      cin >> t;
      now += t;
    }
    else if(type == 3){
      long long h;
      cin >> h;
      int ans = 0;
      while(!q.empty() && now - q.top() >= h){
        ans++;
        q.pop();
      }
      cout << ans << '\n';
    }
  }   
  return 0;
}
