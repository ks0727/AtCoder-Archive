#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  string s;
  cin >> s;
  int q;
  cin >> q;
  while(q--){
    long long t,k;
    cin >> t >> k; k--;
    string ns = "";
    while(k){
      if(k%2 == 0) ns+='L';
      else ns+='R';
      k/=2;
      t--;
      if(t==0) break;
    }
    reverse(ns.begin(),ns.end());
    if(t==0){
      char now = s[k];
      for(int i=0;i<ns.size();i++){
        if(ns[i]=='L') now++;
        if(ns[i]=='R') now+=2;
        if(now=='C'+1) now = 'A';
        else if(now=='C'+2) now = 'B';
      }
      cout << now << endl;
    }else{
      t %= 3;
      char now = s[0];
      if(t==1) now++;
      if(t==2) now+=2;
      if(now=='C'+1) now='A';
      if(now=='C'+2) now='B';
      for(int i=0;i<ns.size();i++){
        if(ns[i]=='L') now++;
        if(ns[i]=='R') now+=2;
        if(now=='C'+1) now = 'A';
        else if(now=='C'+2) now = 'B';
      }
      cout << now << endl;
    }

  }
}
    


