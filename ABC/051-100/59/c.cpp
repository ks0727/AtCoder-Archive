#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  long long ans = 1e18;
  {//正スタート
    long long now = 0;
    long long pos = 0;
    long long neg = 0;
    for(int i=0;i<n;i++){
      if(i%2 == 0){
        long long target = neg-pos+1;
        if(a[i] > 0){
          if(a[i] >= target){
            pos += a[i];
          }else{
            pos += target;
            now += target - a[i];
          }
        }else{
          long long target = neg-pos+1;
          now += target-a[i];
          pos += target;
        }
      }else{ //奇数番目は負の値になる必要がある
        if(a[i] > 0){
          long long target = pos-neg+1; //targetは絶対値
          now += target+a[i];
          neg += target;
        }else{
          long long target = pos-neg+1;
          if(target > -a[i]){
            now += target+a[i];
            neg += target;
          }else{
            neg -= a[i];
          }
        }
      }
    }
    ans = min(ans,now);
  }
  {//負スタート
    long long now = 0;
    long long pos = 0;
    long long neg = 0;
    for(int i=0;i<n;i++){
      if(i%2 == 1){
        long long target = neg-pos+1;
        if(a[i] > 0){
          if(a[i] >= target){
            pos += a[i];
          }else{
            pos += target;
            now += target - a[i];
          }
        }else{
          long long target = neg-pos+1;
          now += target-a[i];
          pos += target;
        }
      }else{ //偶数番目は負の値になる必要がある
        if(a[i] > 0){
          long long target = pos-neg+1; //targetは絶対値
          now += target+a[i];
          neg += target;
        }else{
          long long target = pos-neg+1;
          if(target > -a[i]){
            now += target+a[i];
            neg += target;
          }else{
            neg -= a[i];
          }
        }
      }
    }
    ans = min(ans,now);
  }
  cout << ans << endl;
  return 0;
}

