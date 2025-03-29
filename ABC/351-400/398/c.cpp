#include <iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  map<int,int> mp;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    a[i] = x;
    mp[x]++;
  }
  int mx = -1;
  for(auto [val,cnt] : mp){
    if(cnt == 1) mx = max(mx,val);
  }
  if(mx ==-1){
    cout << -1 << endl;
    return 0;
  }else{
    for(int i=0;i<n;i++){
      if(mx == a[i]){
        cout <<i+1 << endl;
        return 0;
      }
    }
  } 
  return 0;
}

