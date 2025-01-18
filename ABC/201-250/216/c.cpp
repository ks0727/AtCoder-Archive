#include <iostream>
using namespace std;

int main(){
  long long n;
  cin >> n;
  string ans;
  while(n){
    if(n%2 == 0){
      ans += 'B';
      n/=2;
    }else{
      ans+='A';
      n-=1;
    }
  }
  for(int i=ans.size()-1;i>=0;i--) cout << ans[i]; cout << endl;
  return 0;
}

