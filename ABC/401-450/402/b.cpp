#include <iostream>
#include<queue>
using namespace std;

int main(){
  int q;
  cin >> q;
  queue<int> qu;
  while(q--){
    int type;
    cin >> type;
    if(type == 1){
      int x;
      cin >> x;
      qu.push(x);
    }else{
      cout << qu.front() << endl;
      qu.pop();
    }
  }
  return 0;
}

