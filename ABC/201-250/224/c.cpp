#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
using namespace std;
using ll=long long;
using P=pair<ll,ll>;

struct Vec{
  ll x,y;
  Vec(ll x=0,ll y=0):x(x),y(y){}
  ll norm(){
    return (ll)x*x+y*y;
  }
  ll dot_product(const Vec& other){
    return (ll)x*other.x+y*other.y;
  }
};
int main(){
  int n;
  cin >> n;
  vector<P> ps;
  for(int i=0;i<n;i++){
    ll x,y;
    cin >> x >> y;
    ps.emplace_back(x,y);
  }
  ll ans = 0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      for(int k=j+1;k<n;k++){
        auto [x1,y1] = ps[i];
        auto [x2,y2] = ps[j];
        auto [x3,y3] = ps[k];
        if((x1-x3)*(y2-y3) - (y1-y3)*(x2-x3) != 0) ans++;
      }
    }
  }
  cout << ans << endl;
}

