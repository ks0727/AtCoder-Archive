#include <iostream>
using namespace std;

int main(){
  long long n,m;
  cin >> n >> m;
  if(n > m/2){
    cout << m/2 << endl;
    return 0;
  }else{//cを使ってsを作成
    long long ans = n;
    m /= 2;
    m -= n;
    m *= 2;
    ans += m/4;
    cout << ans << endl;
  }
  return 0;
}

