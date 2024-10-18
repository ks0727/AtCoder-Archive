#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++) cin >> a[i] >> b[i];
  int sa=0,sb=0,sc=0;
  for(int i=0;i<n;i++){
    if(a[i] == 1) sa += b[i];
    else if(a[i] == 2) sb += b[i];
    else sc += b[i];
  }
  int sum = sa+sb+sc;
  if(sum %3 != 0){
    cout << -1 << endl;
    return 0;
  }
  map<pair<int,int>,int> mp;
  mp[make_pair(sa,sb)] = 0;
  queue<pair<int,int> > q;
  q.emplace(sa,sb);
  while(!q.empty())
  {
    auto [ca,cb] = q.front(); q.pop();
    int cc = sum - ca - cb;
    for(int i=0;i<n;i++){
      if(a[i] == 1 && ca <= sum/3) continue;
      if(a[i] == 2 && cb <= sum/3) continue;
      if(a[i] == 3 && cc <= sum/3) continue;
      if(a[i] == 1){
        if(ca > sum/3 && cb < sum/3 && b[i]+cb <= sum/3){
          if(mp.count(make_pair(ca-b[i],cb+b[i]))) mp[make_pair(ca-b[i],cb+b[i])] = min(mp[make_pair(ca-b[i],cb+b[i])],mp[make_pair(ca,cb)] + 1);
          else mp[make_pair(ca-b[i],cb+b[i])] = mp[make_pair(ca,cb)] + 1;
          q.emplace(ca-b[i],cb+b[i]);
          a[i] = 2;
        }else if(ca > sum/3 && cc < sum/3 && b[i]+cc <= sum/3 ){
          if(mp.count(make_pair(ca-b[i],cb))) mp[make_pair(ca-b[i],cb)] = min(mp[make_pair(ca-b[i],cb)],mp[make_pair(ca-b[i],cb)] + 1);
          else mp[make_pair(ca-b[i],cb)] = mp[make_pair(ca-b[i],cb)] + 1;
          q.emplace(ca-b[i],cb);
          a[i] = 3;
        }
      }else if(a[i] == 2){
        if(cb > sum/3 && ca < sum/3 && b[i]+ca <= sum/3 ){
          if(mp.count(make_pair(ca+b[i],cb-b[i]))) mp[make_pair(ca+b[i],cb-b[i])] = min(mp[make_pair(ca+b[i],cb-b[i])],mp[make_pair(ca,cb)] + 1);
          else mp[make_pair(ca+b[i],cb-b[i])] = mp[make_pair(ca,cb)] + 1;
          q.emplace(ca+b[i],ca-b[i]);
          a[i] = 1;
        }else if(cb > sum/3 && cc < sum/3 && b[i]+cc <= sum/3 ){
          if(mp.count(make_pair(ca,cb-b[i]))) mp[make_pair(ca,cb-b[i])] = min( mp[make_pair(ca,cb-b[i])], mp[make_pair(ca,cb)] + 1);
          else mp[make_pair(ca,cb-b[i])] = mp[make_pair(ca,cb)] + 1;
          q.emplace(ca,cb-b[i]);
          a[i] = 3;
        }
      }else{
        if(cc > sum/3 && ca < sum/3 && b[i]+ca <= sum/3 ){
          if(mp.count(make_pair(ca+b[i],cb))) mp[make_pair(ca+b[i],cb)] = min(mp[make_pair(ca+b[i],cb)], mp[make_pair(ca,cb)] + 1);
          else mp[make_pair(ca+b[i],cb)] =  mp[make_pair(ca,cb)] + 1;
          q.emplace(ca+b[i],cb);
          a[i] = 1;
        }else if(cc > sum/3 && cb < sum/3 && b[i]+cb <= sum/3 ){
          if(mp.count(make_pair(ca,cb+b[i]))) mp[make_pair(ca,cb+b[i])] = min(mp[make_pair(ca,cb+b[i])], mp[make_pair(ca,cb)] + 1);
          else mp[make_pair(ca,cb+b[i])] = mp[make_pair(ca,cb)] + 1;
          q.emplace(ca,cb+b[i]);
          a[i] = 2;
        }
      }
    }
  }
  if(mp.count(make_pair(sum/3,sum/3))) cout << mp[make_pair(sum/3,sum/3)] << endl;
  else cout << -1 << endl;
  return 0;
}

