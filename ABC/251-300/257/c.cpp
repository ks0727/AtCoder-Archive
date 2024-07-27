#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> w(n);
  for(int i=0;i<n;++i) cin >> w[i];
  vector<int> adult,child;
  for(int i=0;i<n;++i){
    if(s[i] == '0') child.push_back(w[i]);
    else adult.push_back(w[i]);
  }
  sort(adult.begin(),adult.end());
  sort(child.begin(),child.end());
  int ans = 0;
  for(int i=0;i<child.size();i++){
    int now = child[i]+1;
    int x = lower_bound(adult.begin(),adult.end(),now) - adult.begin();
    int cur = adult.size()-x+i+1;
    ans = max(ans,cur);
  }
  ans= max(ans,(int)adult.size());
  ans = max(ans,(int)child.size());
  cout << ans << endl;

  return 0;
}

