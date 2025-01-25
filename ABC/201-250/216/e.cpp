#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<long long> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  a.push_back(0);
  sort(a.rbegin(),a.rend());
  long long now = a[0];
  long long num = 0;
  while(num < n && now == a[num]) num++;
  //numは今の最大値の数
  //これを抜けた時点のnumは最大値よりも小さい
  long long ans = 0;
  long long sum = 0;
  for(int i=0;i<n;i++) sum += a[i];
  if(sum <= k){
    for(int i=0;i<n;i++) ans += a[i]*(a[i]+1)/2;
    cout << ans << endl;
    return 0;
  }
  while(true){
     long long next = a[num];
     if(num == n) num--;
     if(k >= (now-next)*num){
       k -= (now-next)*num;
       ans += now*(now+1)/2 - next*(next+1)/2;
       while(num < n && a[num] == next) num++;
       now = next;
     }else{
       while(k){
         if(k > num){
           k -= num;
           ans += now*num;
           now--;
         }else{
           for(int i=0;i<num;i++){
             k--;
             ans += now;
             if(k == 0) break;
           }
         }
       }
     }
     if(k <= 0) break;
  }
  cout << ans << endl;
}

