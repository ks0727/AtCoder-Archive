#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
using P = pair<int,int>;
void chmax(int &x,int y){
  x = max(x,y);
}
int main(){
  int h,w,n;
  cin >> h >> w >> n;
  map<int,vector<P> >  mp;
  map<P,int> cell;
  for(int i=0;i<n;i++){
    int r,c,a;
    cin >> r >>c >> a;
    mp[-a].emplace_back(r,c);
    cell[P(r,c)] = i;
  }
  vector<int> ans(n);
  map<int,int> mxr,mxc;
  for(auto [_,ps]:mp){//値が大きい順に取ることができる
    for(auto [r,c]:ps){ //値が同じである全てのマスを順番に見ていく
      int now = max(mxr[r],mxc[c]); //その値が移動できる回数は, その値より1個大きい数が移動できる数+1となる
      ans[cell[P(r,c)]] = now; //ansにそれを入れておく
    }
    for(auto [r,c]:ps){
      int now = ans[cell[P(r,c)]];
      chmax(mxr[r],now+1); //各行, 列の現在の最大値を更新しておく
      chmax(mxc[c],now+1);      
    }
  }
  for(int i=0;i<n;i++) cout << ans[i] << endl;
  return 0;
}

