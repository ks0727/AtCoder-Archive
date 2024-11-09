#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++) cin >> a[i] >> b[i];
  double tot = 0;
  for(int i=0;i<n;i++){
    tot += double(1.*a[i]/b[i]);
  }
  double t = tot/2;
  double ans = 0;
  for(int i=0;i<n;i++){
    double need = 1.*a[i]/b[i];
    if(need < t){
      t -= need;
      ans += (double)a[i];
    }else{
      ans += 1.*b[i]*t;
      break;
    }
  }
  printf("%.10f\n",ans);
 

  return 0;
}

