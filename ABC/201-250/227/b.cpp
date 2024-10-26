#include <iostream>
#include <set>
using namespace std;

int main(){
  int n;
  cin >> n;
  set<int> st;
  for(int a=1;a<1000;a++){
    for(int b=1;b<1000;b++){
      int x = 4*a*b+3*a+3*b;
      if(x > 1000) break;
      st.insert(x);
    }
  }
  int ans = 0;
  for(int i=0;i<n;i++){
    int s;
    cin >> s;
    if(!st.count(s)) ans++;
  }
  cout << ans << endl;
  return 0;
}

