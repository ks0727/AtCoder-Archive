#include <iostream>
#include <set>
using namespace std;

int main(){
  int n;
  cin >> n;
  set<int> st;
  st.insert(0);
  for(int i=0;i<n;++i){
    int p;
    cin >> p;
    set<int> old;
    swap(old,st);
    for(int x : old){
      st.insert(x);
      st.insert(p);
      st.insert(x+p);
    }
  }
  cout << st.size() << endl;
  return 0;
}

