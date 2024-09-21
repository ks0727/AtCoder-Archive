#include <iostream>
#include <vector>
using namespace std;

int main(){
  int w;
  cin >> w;
  vector<int> ans;
  auto f = [&](int x){
    for(int i=1;i<=99;i++){
      ans.push_back(x*i);
    }
  };
  f(1);
  f(100);
  f(10000);
  ans.push_back(990001);
  cout << ans.size() << endl;
  for(int i=0;i<ans.size();i++) cout << ans[i] << ' '; cout << endl;
  return 0;
}

