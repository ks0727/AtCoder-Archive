#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> p(n),q(n);
  for(int i=0;i<n;i++) cin >> p[i],p[i]--;
  for(int i=0;i<n;i++) cin >> q[i],q[i]--;
  vector<int> is;
  for(int i=0;i<n;i++) is.push_back(i);
  int a = -1, b = -1;
  int cnt = 0;
  do{
    cnt++;
    for(int i=0;i<n;i++){
      if(p[i] != is[i]) break;
      if(i == n-1) a = cnt;
    }
    for(int i=0;i<n;i++){
      if(q[i] != is[i]) break;
      if(i == n-1) b = cnt;
    } 
  }while(next_permutation(is.begin(),is.end()));
  int ans = abs(a-b);
  cout << ans << endl;
  return 0;
}

