#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  string s;
  cin >> s;
  int n=s.size();
  vector<int> a;
  for(int i=0;i<n;i++){
    a.push_back(s[i]-'0');
  }
  long long ans = 0;
  for(int i=0;i<1<<a.size();i++){
    vector<int> b,c;
    for(int j=0;j<a.size();j++){
      if(i>>j&1) b.push_back(a[j]);
      else c.push_back(a[j]);
    }
    sort(b.rbegin(),b.rend());
    sort(c.rbegin(),c.rend());
    long long bx = 0;
    long long cx = 0;
    for(int j=0;j<b.size();j++){
      bx = bx*10+b[j];
    }
    for(int j=0;j<c.size();j++) cx = cx*10+c[j];
    ans = max(ans,bx*cx);
  }
  cout << ans << endl;
  return 0;
}

