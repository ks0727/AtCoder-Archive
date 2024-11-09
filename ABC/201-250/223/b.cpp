#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  vector<string> ss;
  for(int i=0;i<n;i++){
    string t = s.substr(i)+s.substr(0,i);
    ss.push_back(t);
  }
  sort(ss.begin(),ss.end());
  cout << ss[0] << endl;
  cout << ss[n-1] << endl;
  return 0;
}

