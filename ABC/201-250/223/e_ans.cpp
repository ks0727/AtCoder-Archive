#include <iostream>
#include<vector>
using namespace std;
using ll = long long;
ll div_ceil(ll a, ll b){
  return (a-b+1)/b;
};
bool f2(ll x, ll y, ll a, ll b){
  ll w = div_ceil(a,y) + div_ceil(b,y);
  return w <= x;
}
bool f3(ll x, ll y, ll a, ll b, ll c){
  ll w = div_ceil(a,y);
  if(w >= x) return false;
  x-=w;
  return f2(x,y,b,c) || f2(y,x,b,c);
}
int main(){
  ll x,y;
  cin >> x >> y;
  ll a,b,c;
  cin >> a >> b >> c;
  for(int fi=0;fi<2;fi++){
    for(int ri=0;ri<3;ri++){
      if(f3(x,y,a,b,c)){
        cout << "Yes" << endl;
        return 0;
      }
      swap(a,b); swap(b,c);
    }
    swap(x,y);
  }
  cout << "No" << endl;
  return 0;
}

