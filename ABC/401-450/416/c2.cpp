#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n,k,x;
  cin >> n >> k >> x;
  vector<string> s(n);
  for(int i=0;i<n;i++) cin >> s[i];
  int mx = 1;
  for(int i=0;i<k;i++) mx*=n;
  vector<string> all;
  for(int i=0;i<mx;i++){
    int j = i;
    vector<int> ids;
    string now = "";
    while(j){
      ids.push_back(j%n);
      j/=n;
    }
    //for(int u=0;u<ids.size();u++) cout << ids[u] << ' '; cout << endl;
    while(ids.size()<k) ids.push_back(0);
    for(int l=ids.size()-1;l>=0;l--) now += s[ids[l]];
    all.push_back(now);
  }
  sort(all.begin(),all.end());
  cout << all[x-1] << endl;
  return 0;
}

