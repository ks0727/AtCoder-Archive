#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> mids;
  for(int i=0;i<n;i++) if(s[i] == '/') mids.push_back(i);
  vector<int> o(n), t(n);
  for(int i=0;i<n;i++){
    if(s[i] == '1') o[i] = 1;
    else if(s[i] == '2') t[i] = 1;
  }
  vector<int> ocnt(n+1),tcnt(n+1);
  for(int i=0;i<n;i++){
    ocnt[i+1] = ocnt[i] + o[i];
    tcnt[i+1] = tcnt[i] + t[i];
  }
  while(q--){
    int L,R;
    cin >> L >> R;
    L--;
    int l = -1, r = n;
    while(r-l > 1){
      int m = (r+l)/2;
      int x = (m-1)/2;
      int lb = lower_bound(ocnt.begin(),ocnt.end(),ocnt[L+1]+x) - ocnt.begin();
      int rb = lower_bound(tcnt.begin(),tcnt.end(),tcnt[R]-x) - tcnt.begin();
      lb--;
      rb++;
      if(lb < L || rb > R  || lb > R || rb < L || lb >= rb) r = m;
      else{
        auto it = upper_bound(mids.begin(),mids.end(),lb);
        if(it == mids.end()) r = m;
        else{
          if(*it > lb && *it < rb) l = m;
          else r = m;
        }
      }
    }
    cout << l << endl;
  }
}

  
  
