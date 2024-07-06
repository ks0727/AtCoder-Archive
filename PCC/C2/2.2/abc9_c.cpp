#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<set<int> > cnt(26);
  for(int i=0;i<n;++i){
    cnt[s[i]-'a'].insert(i);
  }
  int sw = 0;
  for(int i=0;i<n;++i){
    for(int j=0;j<26;++j){
      if(cnt[j].size() != 0){
        int c = s[i] - 'a';
        if(c <= j){
          cnt[c].erase(i);
          break;
        }
        s[i] = j+'a';
        int p = *cnt[j].rbegin();
        s[p] = c+'a';
        cnt[j].erase(p);
        sw+=2;
        if(sw >= k-1){
          cout << s << endl;
          return 0;
        }
        break;
      }
    }
  }
  cout << s << endl;
  return 0;
}

