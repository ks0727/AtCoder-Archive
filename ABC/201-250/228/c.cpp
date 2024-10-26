#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> s(n);
  for(int i=0;i<n;i++){
    int si = 0;
    for(int j=0;j<3;j++){
      int p;
      cin >> p;
      si += p;
    }
    s[i] = si;
  }
  vector<int> t = s;
  sort(t.begin(),t.end());
  for(int i=0;i<n;i++){
    int rank = t.end() - upper_bound(t.begin(),t.end(),s[i]+300);
    if(rank+1 <=k) cout << "Yes\n";
    else cout << "No\n";
  }
  return 0;
}

