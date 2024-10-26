#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  map<vector<int>,int> mp;
  for(int i=0;i<n;i++){
    int l;
    cin >> l;
    vector<int> a(l);
    for(int j=0;j<l;j++) cin >> a[j];
    mp[a]++;
  }
  cout << mp.size() << endl;
    

  return 0;
}

