#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<cassert>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i],a[i]--;
  vector<vector<int> > id(n);
  for(int i=0;i<n;i++){
    id[a[i]].push_back(i);
  }
  vector<vector<long long> > sum(n);
  for(int i=0;i<n;i++){
    if(id[i].size() <= 1) continue;
    sum[i].resize(id[i].size()+1);
    for(int j=id[i].size()-1;j>=1;j--){
      sum[i][j-1] = sum[i][j]+id[i][j];
    }
  }
  long long ans = 0;
  for(int i=0;i<n;i++){
    if(id[i].size() <= 1) continue;
    for(int j=0;j<id[i].size()-1;j++){
      ans += sum[i][j]-(long long)id[i][j]*(id[i].size()-j-1) -id[i].size()+j+1;
    }
    long long x = id[i].size();
    ans -= x*(x-1)*(x-2)/6;
  }
  cout << ans << endl;
}
