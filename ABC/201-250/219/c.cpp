#include <iostream>
#include<vector>
#include<set>
using namespace std;

vector<string> f(vector<string> t, string &ns,int d=0){
  if(t.size() == 1) return t;
  if(t.size() == 0) return {""};
  vector<string> res;
  for(string s : t){
    if(s.size() == d) res.push_back(s);
  }
  for(int i=0;i<26;i++){
    vector<string> now;
    for(string s : t){
      if(s.size() == d) continue;
      if(s[d] != ns[i]) continue;
      now.push_back(s);
    }
    if(now.size()==0) continue;
    vector<string> sorted_now = f(now,ns,d+1);
    for(string s : sorted_now){
      res.push_back(s);
    }
  }
  return res;
}

int main(){
  string x;
  cin >> x;
  int n;
  cin >> n;
  vector<string> s(n);
  for(int i=0;i<n;i++) cin >> s[i];
  vector<string> ans = f(s,x,0);
  for(string ss : ans) cout << ss << endl;
  return 0;
}

