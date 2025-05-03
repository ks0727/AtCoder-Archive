#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  map<int,int> mp;
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    mp[(a+b)%n]++;
  }
  long long ans = (long long)m*(m-1)/2;
  for(auto [val,cnt] : mp) ans -= (long long)cnt*(cnt-1)/2;
  cout << ans << endl;
  return 0;
}

