#include <iostream>
#include <vector>
using namespace std;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  int a[n];
  for(int i=0;i<(n);i++) a[i] = s[i] - '0';
  int n2 = 1<<(n-1);
  long long ans = 0;
  for(int bit =0;bit<(n2);bit++){
          long long si = 0;
          long long now = a[0];
       for(int i=0;i<(n-1);i++){
          if(bit & 1 << i){
              si += now;
              now = 0;
           }
           now = now*10 + a[i+1];
       }
        si += now;
       ans += now;
    }
    cout << ans << endl;
  return 0;
}

