#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
#include<cassert>
using namespace std;
int main(){
  int n,k,q;
  cin >> n >> k >> q;
  multiset<long long> topk,downk;
  for(int i=0;i<k;i++) topk.insert(0);
  for(int i=0;i<n-k;i++) downk.insert(0);
  long long now = 0;
  vector<long long> a(n);
  if(n == k){
    while(q--){
      int x; long long y;
      cin >> x >> y;
      x--;
      now -= a[x];
      a[x] = y;
      now += a[x];
      cout << now << endl;
    }
    return 0;
  }
  while(q--){
    int x; long long y;
    cin >> x >> y;
    x--;
    if(topk.find(a[x]) != topk.end()){ //topk個の中に含まれていたら
      auto it = topk.find(a[x]);
      topk.erase(it);
      now -= a[x];
      int mx = *downk.rbegin();
      topk.insert(mx);
      now += mx;
      auto it2 = downk.find(mx);
      assert(it2 != downk.end());
      downk.erase(it2);
    }else{ //小さい方に含まれている時
      auto it = downk.find(a[x]);
      assert(it != downk.end());
      downk.erase(it);
    }
    if(y >= *topk.begin()){
      int mn = *topk.begin();
      downk.insert(mn);
      now -= mn;
      topk.erase(topk.begin());
      topk.insert(y);
      now += y;
    }else{
      downk.insert(y);
    }
    a[x] = y;
    cout << now << endl;
  }
}
  
