#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
  int n,m;
  cin >> n >> m;
  vector<int> c(n),p(n);
  vector<vector<int> > s(n);
  for(int i=0;i<n;i++){
    cin >> c[i] >> p[i];
    vector<int> a(p[i]);
    for(int j=0;j<p[i];j++) cin >> a[j];
    sort(a.begin(),a,end());
    s[i] = a;
  }
  const double INF = 1e18;
  vector<double> ans(m+1,INF);
  ans[0] = 0;
  map<int,double> memo;
  
  auto f = [&](auto f,int v)->void{
    if(memo.count(v)) return memo[v];
    for(int i=0;i<n;i++){

  printf("%.10f\n",ans[m]);
}
    
  
