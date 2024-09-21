#include <iostream>
#include <set>
using namespace std;

int main(){
  int n;
  cin >> n;
  set<int> st;
  for(int i=1;i<=2*n+1;i++) st.insert(i);
  int t = 0;
  while(st.size() > 0){
    if(t%2 == 0){
      int x = *st.begin();
      cout << x << endl;
      st.erase(x);
    }else{
      int x;
      cin >> x;
      st.erase(x);
    }
    t++;
  }
  return 0;
}

