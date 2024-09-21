#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;
  vector<set<int> > bs(n);
  for(int i=0;i<n;i++){
    int c;
    cin >> c;
    bs[i].insert(c);
  }
  while(q--){
    int a,b;
    cin >> a >> b;
    a--;b--;
    bool swapped = false;
    if(bs[a].size() > bs[b].size()){
      for(int x : bs[b]) bs[a].insert(x);
      cout << bs[a].size() << endl;
      bs[b].clear();
      swap(bs[a],bs[b]);
      swap(a,b);
    }else{
      for(int x : bs[a]) bs[b].insert(x);
      bs[a].clear();
      cout << bs[b].size() << endl;
    }
  }


  return 0;
}

