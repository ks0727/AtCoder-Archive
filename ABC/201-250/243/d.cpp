#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  long long x;
  cin >> x;
  string s;
  cin >> s;
  string bit="";
  while(x){
    bit += x%2 + '0';
    x/=2;
  }  
  reverse(bit.begin(),bit.end());
  for(int i=0;i<n;i++){
    if(s[i] == 'U') bit.pop_back();
    if(s[i] == 'L') bit+='0';
    if(s[i]=='R') bit += '1';
  }
  long long ans = 0;
  for(int i=0;i<bit.size();i++){
    ans = ans*2 + (bit[i]-'0');
  }
  cout << ans << endl;
}
