#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  long long n;
  cin >> n;
  vector<long long> arr;
  for(int i=1;i<1e6;i++){
    string s = to_string(i)+to_string(i);
    arr.push_back(stoll(s));
  }
  int ans = upper_bound(arr.begin(),arr.end(),n) - arr.begin();
  cout << ans << endl;
  return 0;
}

