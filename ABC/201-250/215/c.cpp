#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  string s; int k;
  cin >> s >> k;
  vector<char> a;
  for(int i=0;i<s.size();i++) a.push_back(s[i]);
  sort(a.begin(),a.end());
  int cnt = 0;
  do{
    if(cnt+1 == k){
      for(int i=0;i<s.size();i++) cout << a[i];
      cout << endl;
      return 0;
    }
    cnt++;
  }while(next_permutation(a.begin(),a.end()));
  return 0;
}

