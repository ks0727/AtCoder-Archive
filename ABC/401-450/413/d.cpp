#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool solve(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  vector<long long> pos,neg;
  for(int i=0;i<n;i++){
    if(a[i] > 0) pos.push_back(a[i]);
    else neg.push_back(a[i]);
  }
  if(neg.size() == 0 || pos.size() == 0){
    vector<long long> b;
    if(neg.size() == 0) b = pos;
    else b = neg;
    sort(b.begin(),b.end());
    for(int i=1;i<n-1;i++){
      long long x = (long long)b[i]*b[i];
      long long y = (long long)b[i-1]*b[i+1];
      if(x != y) return false;
    }
    return true;
  }else{
    for(int i=0;i<neg.size();i++) neg[i] *= -1;
    sort(neg.begin(),neg.end());
    sort(pos.begin(),pos.end());
    vector<long long> s,l;
    if(pos[0] < neg[0]) s = pos, l = neg;
    else s = neg,l=pos;
    if(l.size() > s.size() || s.size() >= l.size()+2) return false;
    //この時点で２つの配列は同じ長さ、または小さい方が一つ大きい
    vector<long long> b;
    for(int i=0;i<n;i++){
      if(i%2==0){
        if(i/2 >= s.size()) return false;
        b.push_back(s[i/2]);
      }else{
        if(i/2 >= l.size()) return false;
        b.push_back(l[i/2]);
      }
    }
    //bは絶対値の順番に並んでいる
    //for(int i=0;i<n;i++) cout << b[i] << ' '; cout << endl;
    for(int i=1;i<n-1;i++){
      long long x = (long long)b[i]*b[i];
      long long y = (long long)b[i-1]*b[i+1];
      if(x != y) return false;
    }
    return true;
  }
}

int main(){
  int t;
  cin >> t;
  while(t--){
    if(solve()) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
