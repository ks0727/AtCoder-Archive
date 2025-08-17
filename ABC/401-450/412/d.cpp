#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int dis(const vector<set<int> > &g, const vector<int> &ord){
  int n = g.size();
  int res = 0;
  auto gc = g;
  vector<set<int> > h(n);
  //ついていない頂点同士をつける
  for(int i=0;i<n;i++){
   int a = ord[i]; int b = ord[(i+1)%n];
   h[a].insert(b);
   h[b].insert(a);
   bool connect = false;
   if(gc[a].count(b)) continue;
   res++;
   gc[a].insert(b);
   gc[b].insert(a);  
 }
 //余分な頂点同士の結合を切る
 for(int i=0;i<n;i++){
   vector<int> to_erase;
   for(int x: gc[i]){
     if(!h[i].count(x)) to_erase.push_back(x);
   }
   res += to_erase.size();
   for(int x:to_erase) gc[x].erase(i);
 }
 return res;
}

int main(){
  int n,m;
  cin >> n >> m;
  vector<set<int> > g(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].insert(b);
    g[b].insert(a);
  }
  const int INF = 1001001001;
  int ans = INF;
  vector<int> ids;
  for(int i=0;i<n;i++) ids.push_back(i);
  do{
    vector<int> now;
    for(int i=0;i<n;i++) now.push_back(ids[i]);
    int cur = dis(g,now);
    ans = min(ans,cur);
  }while(next_permutation(ids.begin(),ids.end()));
  cout << ans << endl;
  return 0;
}

