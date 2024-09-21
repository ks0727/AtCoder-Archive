#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  auto f = [&](auto f, int x)->vector<int>{
    if(x == 1) return {1};
    vector<int> res;
    vector<int> a = f(f,x-1);
    for(int i=0;i<a.size();i++) res.push_back(a[i]);
    res.push_back(x);
    for(int i=0;i<a.size();i++) res.push_back(a[i]);
    return res;
  };
  vector<int> ans = f(f,n);
  for(int x: ans) cout << x << ' '; cout << endl;
  return 0;
}

