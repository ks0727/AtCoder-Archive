#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  for(int i=0;i<n;i++) cin >> p[i];
  vector<int> rs,bs;
  if(p[0] < p[1]) bs.push_back(0);
  for(int i=1;i<n-1;i++){
    if(p[i-1] < p[i] && p[i] > p[i+1]) rs.push_back(i);
    if(p[i-1] > p[i] && p[i] < p[i+1]) bs.push_back(i);
  }
  if(p[n-1] > p[n-2]) rs.push_back(n-1);
  long long ans = 0;
  int j = 0;
  if(rs.size() == 0 || bs.size() == 0){
    cout << 0 << endl;
    return 0;
  }
  for(int i=0;i<rs.size()-1;i++){
    int ridx = rs[i];
    if(j >= bs.size()) continue;
    int bidx = bs[j];
    if(bidx > ridx){
      j++;
      continue;
    }
    int nridx = rs[i+1];
    if(j+1 >= bs.size()) continue;
    int nbidx = bs[j+1];
    ans += (long long)(nridx-nbidx)*(ridx-bidx);
    j++;
  }
  cout << ans << endl;
  return 0;
}

