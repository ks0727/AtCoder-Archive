#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  string s="";
  vector<char> cs(n);vector<long long>ls(n);
  for(int i=0;i<n;i++) cin >> cs[i] >> ls[i];
  for(int i=0;i<n;i++){
    if(ls[i] > 100){
      cout << "Too Long" << endl;
      return 0;
    }
    for(int j=0;j<ls[i];j++) s+=cs[i];
    if(s.size() > 100){
      cout << "Too Long" << endl;
      return 0;
    }
  }
  cout << s << endl;
  return 0;
}

