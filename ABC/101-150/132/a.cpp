#include <iostream>
#include<map>
using namespace std;

int main(){
  string s;
  cin >> s;
  map<char,int> mp;
  for(int i=0;i<4;i++){
    mp[s[i]]++;
  }
  if(mp.size() != 2){
    cout << "No" << endl;
    return 0;
  }
  for(auto [v,c] : mp){
    if(c != 2){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}

