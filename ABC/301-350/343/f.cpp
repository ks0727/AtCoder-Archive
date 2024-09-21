#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct Node{
  int sx,mx, cnt_sx,cnt_mx;
  Node(int sx=-1, int mx=-1,int cnt_sx=0,int cnt_mx=0):sx(sx),mx(mx),cnt_sx(cnt_sx),cnt_mx(cnt_mx){}
};
template<class S,auto op,auto e>struct segtree{
  int n,size;
  vector<S> nodes;
  segtree(int n):n(n){
    size = 1;
    while(size < n) size <<= 1;
    nodes.resize(2*size,e());
  }
  void update(int k){
    nodes[k] = op(nodes[2*k],nodes[2*k+1]);
  }
  void set(int p, S x){
    p += size;
    nodes[p] = x;
    while(p){
      update(p>>1);
      p>>=1;
    }
  }
  S get(int p){
    p += size;
    return nodes[p];
  }
  S prod(int l, int r){
    S lb =e(), rb = e();
    l += size; r+= size;
    while(l < r){
      if(l&1) lb = op(lb,nodes[l--]);
      if(r&1) rb = op(rb,nodes[--r]);
      l >>= 1;
      r >>= 1;
    }
    return op(lb,rb);
  }
};
Node op(Node a, Node b){
  set<int> st;
  st.insert(a.sx);
  st.insert(a.mx);
  st.insert(b.sx);
  st.insert(b.mx);
  Node res = Node(-2,-1,0,0);
  int mx = *st.rbegin();
  if(mx == a.mx){
    res.mx = a.mx;
    res.cnt_mx += a.cnt_mx;
  }
  if(mx == b.mx){
    res.mx = b.mx;
    res.cnt_mx += b.cnt_mx;
  }
  st.erase(mx);
  if(st.size() == 0) return res;
  int sx = *st.rbegin();
  if(sx == a.mx){
    res.sx = a.mx;
    res.cnt_sx += a.mx;
  }
  if(sx == b.mx){
    res.sx = b.mx;
    res.cnt_sx += b.cnt_mx;
  }
  if(sx == a.sx){
    res.sx = a.sx;
    res.cnt_sx += a.cnt_sx;
  }
  if(sx == b.sx){
    res.sx = b.sx;
    res.cnt_sx += b.cnt_sx;
  }
  return res;
}
Node e(){
  Node res = Node(-2,-1,0,0);
  return res;
}
int main(){
  int n,q;
  cin >> n >> q;
  segtree<Node,op,e> seg(n);
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    Node b = Node(-2,a,0,1);
    seg.set(i,b);
  }
  while(q--){
    int type;
    cin >> type;
    if(type == 1){
      int p,x;
      cin >> p >> x;
      seg.set(p,Node(-2,x,0,1));
    }else{
      int l,r;
      cin >> l >> r;
      auto x = seg.prod(l,r);
      cout  << x.cnt_sx << endl;
    }
  }
  return 0;
}

