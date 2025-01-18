#include <iostream>
#include<set>
#include<queue>
using namespace std;

int main(){
  multiset<int> sorted,nxt;
  queue<int> q;
  int Q;
  cin >> Q;
  while(Q--){
    int type;
    cin >> type;
    if(type == 1){
      int x;
      cin >> x;
      q.push(x);
      nxt.insert(x);
    }
    else if(type == 2){
      if(sorted.size() > 0){
        cout << *sorted.begin() << endl;
        sorted.erase(sorted.begin());
      }else{
        cout << q.front() << endl;
        auto it = nxt.find(q.front());
        nxt.erase(it);
        q.pop();
      }
    }
    else if(type == 3){
      if(nxt.size() > sorted.size()) swap(nxt,sorted);
      for(int x : nxt) sorted.insert(x);
      nxt.clear();
      q = queue<int>{};
    }
  }
  return 0;
}

