#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct UnionFind{
  int n;
  vector<int> par,rank;
  vector<int> left,right;
  UnionFind(int n):n(n),par(n),rank(n),left(n),right(n){
    for(int i=0;i<n;++i){
      par[i] = i;
      left[i] = i;
      right[i] = i;
    }
  }
  int root(int x){
    if(x == par[x]) return par[x];
    else return par[x] = root(par[x]);
  }
  void merge(int a,int b){
    a = root(a); b = root(b);
    if(a == b) return;
    if(rank[a] > rank[b]) swap(a,b);
    left[b] = min(left[a],left[b]);
    right[b] = max(right[a],right[b]);
    rank[b] += rank[a];
    par[a] = par[b];
  }
  bool same(int a,int b){
    return root(a) == root(b);
  }
};

int main(){
  int h,w,q;
  cin >> h >> w >> q;
  vector<UnionFind> rows,cols;
  for(int i=0;i<h;i++) rows.push_back(UnionFind(w));
  for(int i=0;i<w;i++) cols.push_back(UnionFind(h));
  vector<vector<bool> > grid(h,vector<bool>(w));
  while(q--){
    int R,C;
    cin >> R >> C;
    R--; C--;
    if(!grid[R][C]){
      grid[R][C] = true;
    }else{
      int lb = rows[R].left[rows[R].root(C)];
      int rb = rows[R].right[rows[R].root(C)];
      rows[R].merge(lb,max(0,lb-1));
      rows[R].merge(rb,min(rb+1,w-1));
      cols[lb].merge(R,max(R-1,0));
      cols[lb].merge(R,min(R+1,h-1));
      cols[rb].merge(R,max(R-1,0));
      cols[rb].merge(R,min(R+1,h-1));
      grid[R][max(0,lb-1)] = true;
      grid[R][min(rb+1,w-1)] = true;

      int la = cols[C].left[cols[C].root(R)];
      int ra = cols[C].right[cols[C].root(R)];
      cols[C].merge(la,max(0,la-1));
      cols[C].merge(ra,min(ra+1,h-1));
      rows[la].merge(C,max(C-1,0));
      rows[la].merge(C,min(C+1,w-1));
      rows[ra].merge(C,min(C-1,0));
      rows[ra].merge(C,max(C+1,w-1));
      grid[max(0,la-1)][C] = true;
      grid[min(ra+1,h-1)][C] = true;
    }
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if(grid[i][j]) cout << "." << ' ';
        else cout << "#" << ' ';
      }
      cout << endl;
    }
    cout << "-------------------------------" << endl;
  }
  int ans = 0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(!grid[i][j]) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}



    







