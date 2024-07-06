#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> t(n);
  for(int i=0;i<(n);++i) cin >> t[i];
  int n2 = 1<<n;
  int ans = 1e9;
  for(int i=0;i<n2;++i){
      vector<int> left,right;
       for(int j=0;j<n;++j){
          if(i & 1<<j){
               left.push_back(j);
            }else{
               right.push_back(j);
              }
         }
      int sl=0,sr=0;
       for(int x :left) sl += t[x];
       for(int x : right) sr += t[x];
       int now = max(sl,sr);
      ans = min(ans,now);
    }
    cout << ans << endl;
  return 0;
}

