#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n,m;
  cin >> n>> m;
  vector<string> a(2*n);
  for(int i=0;i<2*n;i++) cin >> a[i];
  vector<pair<int,int> > wins;
  for(int i=0;i<2*n;i++){
    wins.emplace_back(0,i);
  };
  for(int i=0;i<m;i++){
    for(int k=0;k<n;k++){
        int u = wins[2*k].second;
        int v = wins[2*k+1].second;
        if(a[u][i] == a[v][i]) continue;
        if(a[u][i] == 'G'){
          if(a[v][i] == 'C'){
            wins[2*k].first--;
          }else if(a[v][i] == 'P'){
            wins[2*k+1].first--;
          }
        }else if(a[u][i] == 'C'){
          if(a[v][i] == 'G'){
            wins[2*k+1].first--;
          }else if(a[v][i] == 'P'){
            wins[2*k].first--;
          }
        }else{
          if(a[v][i] == 'G'){
            wins[2*k].first--;
          }else if(a[v][i] == 'C'){
            wins[2*k+1].first--;
          }
        }
    }
    sort(wins.begin(),wins.end());
  }
  for(int i=0;i<2*n;i++) cout << wins[i].second+1 << endl;
  return 0;
}

