#include <iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> cnt(m);
  for(int i=0;i<n;i++) cin >> a[i],a[i]--;
  for(int i=0;i<n;i++) cnt[a[i]]++;
  for(int i=0;i<m;i++){
    if(cnt[i] < 1){
      cout << 0 << endl;
      return 0;
    }
  }
  for(int i=0;i<n;i++){
      cnt[a.back()]--;
      if(cnt[a.back()] == 0){
        cout << i+1 << endl;
        return 0;
      } 
      a.pop_back();
  }
  return 0;
}

