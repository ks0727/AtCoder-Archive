#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  vector<bool> called(n);
  for(int i=0;i<n;i++){
    if(!called[i]) called[a[i]-1] = true;
  }
  vector<int> ans;
  for(int i=0;i<n;i++){
    if(!called[i]) ans.push_back(i);
  }
  cout << ans.size() << endl;
  for(int i=0;i<ans.size();i++) cout << ans[i]+1 <<' '; cout << endl;
}

