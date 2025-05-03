#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> cnt(n);
  for(int i=0;i<n;i++){
    int a;
    cin >> a; a--;
    cnt[a]++;
  }
  bool ok = true;
  for(int i=0;i<n;i++){
    if(cnt[i] != 1) ok = false;
  }
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

