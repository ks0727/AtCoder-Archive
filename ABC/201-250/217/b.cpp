#include <iostream>
#include<set>
#include<vector>
using namespace std;

int main(){
  vector<string> arr = {"ABC" , "ARC" , "AGC" , "AHC"};
  set<string> st;
  for(string s : arr) st.insert(s);
  string a,b,c;
  cin >> a >> b >> c;
  st.erase(a);
  st.erase(b);
  st.erase(c);
  cout << *st.begin() << endl;
}

  
