#include <iostream>
#include <set>
using namespace std;

int main(){
  int n,x;
  cin >> n >> x;
  set<int> st;
  st.insert(0);
  for(int i=0;i<n;i++){
    set<int> ns;
    swap(ns,st);
    int a,b;
    cin >> a >> b;
    for(int s : ns){
      if(s+a <= x) st.insert(s+a);
      if(s+b <= x) st.insert(s+b);
    }
  }
  if(st.count(x)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

