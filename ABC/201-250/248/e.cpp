#include <iostream>
#include <map>
#include <vector>
using namespace std;
using ll = long long;

struct Vec{
  ll x,y;
  Vec(ll x=0,ll y=0):x(x),y(y){}
  Vec operator+(const Vec &other){
    Vec res;
    res.x = x + other.x;
    res.y = y + other.y;
    return res;
  }
  Vec operator-(const Vec &other){
    Vec res;
    res.x = other.x - x;
    res.y = other.y - y;
    return res;
  }
};

int main(){
  int n,k;
  cin >> n >> k;
  vector<Vec> vs(n);
  for(int i=0;i<n;i++) cin >> vs[i].x >> vs[i].y;
  if(k == 1){
    cout << "Infinity" << endl;
    return 0;
  }
  
  ll ans = 0;
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      for(int l=0;l<n;l++){
        //if(l == i) continue
        //if(l == j) continue;
        int cnt = 0;
        if((vs[l].x-vs[i].x)*(vs[j].y-vs[i].y) == (vs[j].x -vs[i].x)*(vs[l].y-vs[i].y)) cnt++;
        if(cnt >= k) ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

