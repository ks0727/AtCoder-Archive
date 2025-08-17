#include <iostream>
#include<set>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<string> ss;
  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    ss.push_back(s);
  }
  set<string> st;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i == j) continue;
      string a = ss[i];
      for(int k=0;k<ss[j].size();k++) a += ss[j][k];
      st.insert(a);
    }
  }
  cout << st.size() << endl;
  return 0;
}

