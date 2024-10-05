#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool match(vector<vector<int> > &a, vector<vector<int> > &b)
{
  for(int i=0;i<a.size();i++)
  {
    for(int j=0;j<a[0].size();j++)
    {
      if(a[i][j] != b[i][j]) return false;
    }
  }
  return true;
}

int main(){
  int h,w;
  cin >> h >> w;
  vector a(h,vector<int>(w)),b(h,vector<int>(w));
  for(int i=0;i<h;i++)for(int j=0;j<w;j++) cin >> a[i][j];
  for(int i=0;i<h;i++)for(int j=0;j<w;j++) cin >> b[i][j];
  if(match(a,b)){
    cout << 0 << endl;
    return 0;
  }
  map<vector<vector<int> >, int> mp;
  mp[a] = 0;
  queue<vector<vector<int> > > q;
  q.emplace(a);
  while(!q.empty())
   {
     auto now = q.front(); q.pop();
     for(int i=0;i<h-1;i++){
       auto c= now;
       swap(c[i],c[i+1]);
       if(match(c,b)){
         cout << mp[now]+1 << endl;
         return 0;
       }
       if(!mp.count(c)){
          mp[c] = mp[now]+1;
          q.emplace(c);
        }
     }
     for(int i=0;i<w-1;i++)
     {
       auto d = now;
       vector<int> c;
       for(int j=0;j<h;j++) c.push_back(d[j][i]);
       for(int j=0;j<h;j++) d[j][i] = d[j][i+1];
       for(int j=0;j<h;j++) d[j][i+1] = c[j];
       if(match(d,b))
       {
         cout << mp[now] + 1 << endl;
         return 0;
       }
       if(!mp.count(d)){
          mp[d] = mp[now]+1;
          q.emplace(d);
        }
     }
   }
   cout << -1 << endl;
   return 0;
 }
       

