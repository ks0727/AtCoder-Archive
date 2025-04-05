#include <iostream>
#include<set>
using namespace std;

int main(){
  int n;
  cin >> n;
  set<string> st;
  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    if(st.count(s)) continue;
    st.insert(s);
    cout << i+1 << endl;
  }
  return 0;
}

