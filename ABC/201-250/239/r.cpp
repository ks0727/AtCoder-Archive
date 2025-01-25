#include <iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main(){
   int n,q;
   cin >> n >> q;
   vector<int> x(n);
   for(int i=0;i<n;i++) cin >> x[i];
   vector<vector<int> > g(n);
   for(int i=0;i<n-1;i++){
     int a,b;
     cin >> a >> b;
     a--; b--;
     g[a].push_back(b);
     g[b].push_back(a);
   }
   const int INF = 1001001001;
   vector<vector<int> > a(n,vector<int>(20,-INF));
   auto dfs = [&](auto dfs, int v, int p=-1)->vector<int>{
     vector<int> res(20,-INF);
      for(int u : g[v]){
        if(u == p) continue;
        vector<int> b = dfs(dfs,u,v);
        for(int i=0;i<20;i++) res.push_back(b[i]);
      }
      vector<int> ans;
      res.push_back(x[v]);
      sort(res.begin(),res.end());
      for(int i=0;i<20;i++){
        ans.push_back(res.back());
        res.pop_back();
      }
      a[v] = ans;
      return ans;
   };
   dfs(dfs,0);
   while(q--){
     int v,k;
     cin >> v >> k;
     v--; k--;
     cout << a[v][k] << endl;
   }
}


        
     
