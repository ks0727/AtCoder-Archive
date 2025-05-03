#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
struct WeightedUnionFind{
  int n;
  vector<int> p;
  vector<long long> dif;
  WeightedUnionFind(int n):n(n),p(n,-1),dif(n){}
  int root(int x){
    if(p[a] < 0 ) return a;
    int b = p[a];
    p[a] = root(p[a]);
    dif[a] += dif[b]; //経路圧縮しながら重みの更新
    return p[a];
  }
  bool merge(int a,int b, long long w){
    root(a); root(b); //経路圧縮する
    w = w + dif[a] - dif[b];
    a = root(a); b = root(b);
    if(a == b) return w== 0;
    if(-p[a] < -p[b]) swap(a,b),w = -w;
    p[a] += p[b];
    p[b] = a; dif[b] = w;
  }
};
    
int main(){
  int n,q;
  cin >> n >> q;
  vector<int> ans;
  for(int qi=0;qi<q;qi++){
    int a,b; long long d;
    a--; b--;
    if(uf.merge(a,b,d)) ans.push_back(i+1);
  }
  for(int x: ans) cout << x << ' '; cout << endl;
}

