#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

vector<int> compress(vector<int> &arr1, vector<int> &arr2){
  vector<int> res;
  for(int i=0;i<arr1.size();i++){
    res.push_back(arr1[i]);
    res.push_back(arr2[i]);
  }
  sort(res.begin(),res.end());
  res.erase(unique(res.begin(),res.end()),res.end());
  for(int i=0;i<arr1.size();i++){
    arr1[i] = lower_bound(res.begin(),res.end(),arr1[i]) - res.begin();
    arr2[i] = lower_bound(res.begin(),res.end(),arr2[i]) - res.begin();
  }
  return res;
}
  
ll g[200][200][200];

int main(){
  int n,k;
  cin >> n>> k;
  vector<int> x1(n),x2(n),y1(n),y2(n),z1(n),z2(n);
  for(int i=0;i<n;i++) cin >> x1[i] >> y1[i] >> z1[i] >> x2[i] >> y2[i] >> z2[i];
  vector<int> x = compress(x1,x2);
  vector<int> y = compress(y1,y2);
  vector<int> z = compress(z1,z2);
  int a = x.size(), b = y.size(),c = z.size();
  for(int i=0;i<n;i++){
    g[x2[i]][y2[i]][z2[i]]--;
    g[x2[i]][y1[i]][z2[i]]++;
    g[x2[i]][y2[i]][z1[i]]++;
    g[x1[i]][y2[i]][z2[i]]++;
    g[x1[i]][y1[i]][z2[i]]--;
    g[x1[i]][y2[i]][z1[i]]--;
    g[x2[i]][y1[i]][z1[i]]--;
    g[x1[i]][y1[i]][z1[i]]++;
  }
  for(int i=0;i<a;i++)for(int j=0;j<b;j++)for(int l=0;l<c;l++) g[i][j][l+1] += g[i][j][l];
  for(int i=0;i<a;i++)for(int j=0;j<b;j++)for(int l=0;l<c;l++) g[i][j+1][l] += g[i][j][l];
  for(int i=0;i<a;i++)for(int j=0;j<b;j++)for(int l=0;l<c;l++) g[i+1][j][l] += g[i][j][l];

  ll ans = 0; 
  for(int i=0;i<a-1;i++)for(int j=0;j<b-1;j++)for(int l=0;l<c-1;l++) if(g[i][j][l] >= k){
    ans += (ll)(x[i+1]-x[i])*(ll)(y[j+1]-y[j])*(ll)(z[l+1]-z[l]);
  }
  cout << ans << endl;
  return 0;
}

