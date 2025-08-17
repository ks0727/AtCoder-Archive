#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n,k,x;
  cin >> n >> k >> x;
  vector<string> s(n);
  for(int i=0;i<n;i++) cin >> s[i];
  //sort(s.begin(),s.end());
  x--;
  int now = 1;
  for(int i=0;i<k-1;i++) now*=n;
  vector<int> arr;
  for(int i=0;i<k-1;i++){
    arr.push_back(x/now);
    x %= now;
    now /= n;
  }
  arr.push_back(x);
  for(int i=0;i<arr.size();i++) cout << arr[i] << ' '; cout << endl;
  string ans = "";
  for(int i=0;i<arr.size();i++) ans += s[arr[i]];
  cout << ans << endl;
  return 0;
}

