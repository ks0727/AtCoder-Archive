#include<iostream>
#include<vector>
#include<map>
#include<tuple>
using namespace std;
using T = tuple<int,int,int>;
int main(){
  int n,c;
  cin >> n >> c;
  map<T,int> mp;
  int now = c;
  vector<int> t(n),a(n);
  for(int i=0;i<n;i++) cin >> t[i] >> a[i];
  for(int i=0;i<n;i++){
    int cur = 0;
    for(int j=0;j<30;j++){
      auto f = [&](auto f,int i,int j,int k)->int{
        if(mp.count(T(i,j,k))){
          return mp[T(i,j,k)];
        }
        if(i==0) return (a[i]>>j&1);
        //cout << i << ' ' << j << ' ' << k << endl;
        int nk = 0;
        if(t[i] == 1){
          nk = k&(a[i]>>j&1);
          return mp[T(i,j,k)] = f(f,i-1,j,nk);
          //cout << k << ' ' << (a[i]>>j&1) << ' ' << (k&(a[i]>>j&1)) << endl;
        }else if(t[i] == 2){
          //nk = k|f(f,i-1,j);
          return mp[T(i,j,k)] = f(f,i-1,j,nk);
          //cout << k << ' ' << (a[i]>>j&1) << ' ' << (k|(a[i]>>j&1)) << endl;
        }else if(t[i] == 3){
          //cout << k << ' ' << (a[i]>>j&1) << ' ' << (k^(a[i]>>j&1)) << endl;
          //nk = k^f(f,i-1,j);
          return mp[T(i,j,k)] = f(f,i-1,j,nk);
          //cout << (k^(a[i]>>j&1)) << endl;
        }
      };
      //cur |= f(f,i,j,);
    }
    cout << cur << endl;
    now = cur;
  }
}
