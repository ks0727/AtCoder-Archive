#include <iostream>
using namespace std;

int main(){
  int n;
  std::cin >> n;
  int a[n];
  for(int i=0;i<(n);i++) cin >> a[i];
  int k;
  std::cin >> k;
  int n2 = 1<<n;
  for(int i=0;i<(n2);++i)
   {
     long long s = 0;
    for(int j = 0;j<(n);j++){
      if(i & (1<<j)){
          s += a[j];
        }   
     }
    
   if(s == k){
      std::cout << "Yes" << endl;
      return 0;
   }
  }
  std::cout << "No" << endl;
  return 0;
}
