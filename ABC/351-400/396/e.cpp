#include <iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> x(m),y(m);
  vector<long long>z(m);
  for(int i=0;i<m;i++) cin >> x[i] >> y[i] >> z[i], x[i]--,y[i]--;
  vector<vector<long long> > ans(n,vector<long long>(60));
  for(int i=0;i<60;i++){
    set<int> sa,sb;
    for(int j=0;j<m;j++){
      if(z[j]>>i&1){ //x[j]とy[j]は異なるグループ
        if(sa.count(x[j]) && sb.count(y[j])) continue;
        if(sa.count(y[j]) && sb.count(x[j])) continue;
        if(sa.count(x[j]) && sa.count(y[j])){
          cout << -1 << endl;
          return 0;
        }
        if(sb.count(x[j]) && sb.count(y[j])){
          cout << -1 << endl;
          return 0;
        }
        if(sa.count(x[j])) sb.insert(y[j]);
        else if(sa.count(y[j])) sb.insert(x[j]);
        else if(sb.count(x[j])) sa.insert(y[j]);
        else if(sb.count(y[j])) sa.insert(x[j]);
        else{
          sa.insert(x[j]);
          sb.insert(y[j]);
        }
      }else{ //x[j]とy[j]は同じグループ
        if(sa.count(x[j]) && sa.count(y[j])) continue;
        if(sb.count(x[j]) && sb.count(y[j])) continue;
        if(sa.count(x[j]) && sb.count(y[j])){
          cout << -1 << endl;
          return 0;
        }
        if(sa.count(y[j]) && sb.count(x[j])){
          cout << -1 << endl;
          return 0;
        }
        if(sa.count(x[j])) sa.insert(y[j]);
        else if(sa.count(y[j])) sa.insert(x[j]);
        else if(sb.count(y[j])) sb.insert(y[j]);
        else if(sb.count(x[j])) sb.insert(y[j]);
        else{
          sa.insert(x[j]);
          sa.insert(y[j]);
        }
      }
   }
   if(sa.size() > sb.size()) swap(sa,sb);
   for(int x : sa) ans[x][i] = 1;
 }
  for(int i=0;i<n;i++){
    long long now = 0;
    for(int j=0;j<60;j++){
      if(ans[i][j] == 1){
        now += 1LL<<j;
      }
    }
    cout << now << ' ';
  }
  cout << endl;
  return 0;
}

