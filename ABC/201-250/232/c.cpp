#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool g1[8][8],g2[8][8];
int main(){
  int n,m;
  cin >> n >> m;
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    g1[a][b] = true;
    g1[b][a] = true;
  }
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    g2[a][b] = true;
    g2[b][a] = true;
  }
  vector<int> is;
  for(int i=0;i<n;i++) is.push_back(i);
  do{
    bool ok = true;
    for(int i=0;i<n-1;i++){
      for(int j=i+1;j<n;j++){
        if(g1[i][j] != g2[is[i]][is[j]]) ok = false;
      }
    }
    if(ok){
      cout << "Yes" << endl;
      return 0;
    }
  }while(next_permutation(is.begin(),is.end()));
  cout << "No" << endl;
  return 0;
}

