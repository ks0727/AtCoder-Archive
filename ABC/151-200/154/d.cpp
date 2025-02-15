#include <iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  map<int,long long> mp;
  for(int i=0;i<n;i++) mp[a[i]]++;
  long long sum = 0;
  for(auto [val,cnt] : mp) sum += cnt*(cnt-1)/2;
  for(int i=0;i<n;i++){
    long long now = sum;
    long long cnt = mp[a[i]];
    now -= cnt*(cnt-1)/2;
    cnt--;
    now += cnt*(cnt-1)/2;
    cout << now << '\n';
  }
  return 0;
}

