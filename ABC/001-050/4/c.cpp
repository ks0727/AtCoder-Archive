#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  n %= 30;
  vector<int> ans;
  for(int i=0;i<6;i++) ans.push_back(i);
  for(int i=0;i<n;i++){
    swap(ans[i%5],ans[i%5+1]);
  }
  for(int i=0;i<6;i++) cout << ans[i]+1;
  cout << endl; 
  return 0;
}

