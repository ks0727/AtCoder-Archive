#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<long long> d(n*2);
  reverse(s.begin(),s.end());
  long long sum = 0;
  for(int i=0;i<n;i++){
    sum += (s[i]-'0')*(n-i);
  }
  for(int i=0;i<n;i++){
    d[i] = sum;
    sum -= (s[i]-'0')*(n-i);
  }
  for(int i=0;i<n*2-1;i++){
    long long now = d[i];
    d[i] = now%10;
    d[i+1] += now/10;
  }
  while(d.back() == 0) d.pop_back();
  reverse(d.begin(),d.end());
  for(int i=0;i<d.size();i++) cout << d[i];
  cout << endl;
  return 0;
}

