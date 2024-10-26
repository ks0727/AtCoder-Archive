#include <iostream>
#include <vector>
using namespace std;

long long y1(long long a, long long b, long long x){
  return x+a-b;
}
long long y2(long long a, long long b, long long x){
  return -x+a+b;
}

  

int main(){
  long long n,a,b;
  cin >> n >> a >> b;
  long long p,q,r,s;
  cin >> p >> q >> r >> s;
  long long h = q-p+1;
  long long w = s-r+1;
  vector<string> ans(h,string(w,'.'));
  for(long long k=p-a;k<=q-a;k++){
    if(r <= b+k && b+k <= s){
      ans[a+k-p][b+k-r] = '#';
    }
  }
  for(long long k=p-a;k<=q-a;k++){
    if(r <= b-k && b-k <= s){
      ans[a+k-p][b-k-r] = '#';
    }
  }
  for(int i=0;i<h;i++) cout << ans[i] << endl; 
  return 0;
}

