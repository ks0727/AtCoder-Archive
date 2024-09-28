#include <iostream>
#include <map>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  map<int,int> mp;
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    mp[a]++;
  }
  for(int i=0;i<m;i++){
    int b;
    cin >> b;
    if(mp[b] == 0){
      cout << "No" << endl;
      return 0;
    }else mp[b]--;
  }
  cout << "Yes" << endl;
  return 0;
}

