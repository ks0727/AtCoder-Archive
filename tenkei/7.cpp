#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  sort(a.begin(),a.end());
  int q;
  cin >> q;
  for(;q--;){
    int b;
    cin >> b;
    int now = 1001001001;
    auto it = upper_bound(a.begin(),a.end(),b);
    if(it != a.end()){
      int bg = *it;
      now = min(now,abs(bg-b));
    }
    if(it == a.begin()){
      cout << now << endl;
      continue;
    }
    it--;
    int ls = *it;
    now = min(now,abs(ls-b));
    cout << now << endl;
  }
  return 0;
}

