#include <iostream>
#include<algorithm>
#include<atcoder/lazysegtree>
using namespace std;
using namespace atcoder;


const int INF = 1001001001;
int op(int a, int b) {return max(a,b);}
int e(){return 0;}
int id(){return -INF;} //更新が行われないときは-INFを返す
int mapping(int f, int x) {return f == -INF ? x : f;} //更新が行われない時はその値をそのまま返す
int composition(int f, int g) {return f == -INF ? g : f;} //compositionとは更新が2つ重なった時の処理を書く

int main(){
  int w,n;
  cin >> w >> n;
  lazy_segtree<int,op,e,int,mapping,composition,id> seg(w);
  for(int i=0;i<n;i++){
    int l, r;
    cin >> l >> r;
    l--;
    int mx = seg.prod(l,r);
    seg.apply(l,r,mx+1);
    cout << mx + 1 << endl;
  }
  return 0;
}

