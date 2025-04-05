#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

const long long INF = 1e18;
template<class S,auto op,auto e> struct segtree{
    int n;
    vector<S> d;
    segtree(int n):n(n){
        d.resize(2*n,e());
    }
    void update(int k){
        d[k] = op(d[2*k],d[2*k+1]);
    }
    void set(int p,S x){
        p += n;
        d[p] = x;
        while(p){
            update(p>>1);
            p>>=1;
        }
    }
    S get(int p){
        return d[p+n];
    }
    S prod(int l,int r){
        l += n; r+=n;
        S lb = e(),rb=e();
        while(r>l){
            if(l&1) lb = op(lb,d[l++]);
            if(r&1) rb = op(rb,d[--r]);
            l>>=1;
            r>>=1;
        }
        return op(rb,lb);
    }
    void show(){
        for(int i=0;i<n;i++){
            cout << d[i+n] << ' ';
        }
        cout << endl;
    }
};

long long op(long long a, long long b){return max(a,b);}
long long e(){return -INF;}
int main(){
  int w,n;
  cin >> w >> n;
  vector<segtree<long long,op,e> > dp(n+1,segtree<long long,op,e>(w+1));
  dp[0].set(0,0);
  for(int i=0;i<n;i++){
    int l,r; long long v;
    cin >> l >> r >> v;
    for(int j=0;j<=w;j++){
      int lb = max(0,j-r);
      int rb = max(0,j-l);
      if(lb !
      long long val = max(dp[i].get(j),dp[i+1].get(j));
      dp[i+1].set(j,val);
      long long mx = dp[i].prod(lb,rb);
      if(mx == -INF) continue;
      dp[i+1].set(j,max(mx+v,dp[i+1].get(j)));
    }
  }
  dp[1].show();
  if(dp[n].get(w) == -INF) cout << -1 << endl;
  else  cout << dp[n].get(w) << endl;
  return 0;
}

