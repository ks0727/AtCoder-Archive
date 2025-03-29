#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> one(n), two(n);
  for(int i=0;i<n;i++){
    int c; long long p;
    cin >> c >> p;
    c--;
    if(c == 0) one[i] = p;
    else two[i] = p;
  }
  vector<long long> so(n+1), st(n+1);
  for(int i=0;i<n;i++) so[i+1] = so[i] + one[i];
  for(int i=0;i<n;i++) st[i+1] = st[i] + two[i];
  int q;
  cin >> q;
  while(q--){
    int l,r;
    cin >> l >> r;
    l--;
    cout << so[r]-so[l] << ' ' << st[r] - st[l] << endl;
  }
  return 0;
}

