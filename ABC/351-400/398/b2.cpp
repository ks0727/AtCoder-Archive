#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  vector<int> a(7);
  for(int i=0;i<7;i++) cin >> a[i];
  vector<int> is;
  for(int i=0;i<7;i++) is.push_back(i);
  bool ok = false;
  do{
    if(a[is[0]] != a[is[1]]) continue;
    if(a[is[1]] == a[is[2]]) continue;
    if(a[is[2]] != a[is[3]]) continue;  
    if(a[is[4]] != a[is[3]]) continue;  
    ok = true;
    break;
  }while(next_permutation(is.begin(),is.end()));
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

