#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> w(n);
  for(int i=0;i<n;++i) cin >> w[i];
  vector<int> piles;
  for(int i=0;i<n;++i){
    auto it = lower_bound(piles.begin(),piles.end(),w[i]);
    if(it == piles.end()){
      piles.push_back(w[i]);
    }else{
      int idx = lower_bound(piles.begin(),piles.end(),w[i]) - piles.begin();
      piles[idx] = w[i];
    }
    sort(piles.begin(),piles.end());
  }
  cout << piles.size() << endl;
  return 0; 
}

