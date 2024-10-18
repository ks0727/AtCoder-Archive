#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;
  map<int,vector<int> > mp;
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    mp[a].push_back(i+1);
  }
  while(q--)
  {
    int x,k;
    cin >> x >> k;
    k--;
    if(k < mp[x].size()) cout << mp[x][k] << endl;
    else cout << -1 << endl;
  }
  return 0;
}

