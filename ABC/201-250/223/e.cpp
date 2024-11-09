#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  long long x,y,a,b,c;
  vector<long long> s(3);
  cin >> x >> y;
  for(int i=0;i<3;i++) cin >> s[i];
  sort(s.begin(),s.end());
  long long biggest = s[2];
  vector<pair<long long,long long> > hw;
  for(long long i=1;i*i<=biggest;i++){
    if(biggest%i == 0){
      hw.emplace_back(i,biggest/i);
    }
  }
  if(x > y) swap(x,y);
  for(auto [h,w] : hw){
    if(w > h) swap(h,w);
    if(w > x || h > y) continue;
    {
      auto [h1,w1] = pair<long long,long long>(h,x-w);
      auto [h2,w2] = pair<long long,long long>(y-h,x);
      if(h1*w1 > h2*w2){
        swap(h1,h2);
        swap(w1,w2);
      }
      cout << h << ' ' << w << endl;
      cout << h1 << ' ' << w1 << endl;
      cout << h2 << ' ' << w2 << endl;
      if(h1*w1 >= s[0] && h2*w2 >= s[1]){
        cout << "Yes" << endl;
        return 0;
      }
    }
    {
      auto [h1,w1] = pair<long long,long long>(y,x-w);
      auto [h2,w2] = pair<long long,long long>(y-h,x-w);
      if(h1*w1 > h2*w2){
        swap(h1,h2);
        swap(w1,w2);
      }
      if(h1*w1 >= s[0] && h2*w2 >= s[1]){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;    
  return 0;
}

