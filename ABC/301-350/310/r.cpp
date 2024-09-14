#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
  int n,t,m;
  cin >> n >> t >> m;
  vector bad(n,vector<bool>(n));
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    bad[a][b] = true;
    bad[b][a] = true;
  }
  long ans = 0;
  auto f = [&](auto f, vector<vector<int> > teams, int cnt)->void{
     if(cnt == n){
       if(teams.size() != t) return;
       for(int i=0;i<teams.size();i++){
         for(int x:teams[i]){
           for(int y:teams[i]){
             if(x == y) continue;
             if(bad[x][y]) return;
           }
         }
       }
      ans++;
      return;
    }
    //すでにtチーム揃っているときは既存のチームに追加   
     if(teams.size() == t){
        for(int i=0;i<t;i++){
          teams[i].push_back(cnt);
          f(f,teams,cnt+1);
          teams[i].pop_back();
        }
     }else{
       for(int i=0;i<teams.size();i++){
         teams[i].push_back(cnt);
         f(f,teams,cnt+1);
         teams[i].pop_back();
       }
       teams.push_back({cnt});
       f(f,teams,cnt+1);
       teams.pop_back();
     }
   };
   vector<vector<int> > visit;
   visit.push_back({0});
  f(f,visit,1);
  cout << ans << endl;
  return 0;
}




