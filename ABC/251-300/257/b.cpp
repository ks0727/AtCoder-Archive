#include <iostream>
using namespace std;
int a[200],l[200];
bool put[200];
int main(){
  int n,k,q;
  cin >> n >> k >> q;
  for(int i=0;i<k;++i){
    cin >> a[i];
    a[i]--;
    put[a[i]] = true;
  }
  for(int i=0;i<q;i++){
   int l;
   cin >> l; l--;
   if(a[l] == n-1){
     continue;
   }else{
     if(put[a[l]+1]) continue;
     else{
       put[a[l]] = false;
       put[a[l]+1] = true;
       a[l]++;
     }
   }
 }
   for(int i=0;i<n;++i) if(put[i]) cout << i+1 << ' '; cout << endl;
  return 0;
}

