#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> b(n),w(m);
  for(int i=0;i<n;i++) cin >> b[i];
  for(int i=0;i<m;i++) cin >> w[i];
  sort(b.rbegin(),b.rend());
  sort(w.rbegin(),w.rend());
  int wi = 0;
  long long ans = 0;
  long long bsum = 0;
  long long wsum = 0;
  for(int i=0;i<n;i++){
    bsum += b[i];
    ans = max(ans,bsum+wsum);
    if(wi < m && wi <= i && w[wi] >= 0){
      wsum += w[wi];
      wi++;
      ans = max(ans,bsum+wsum);
    }
  }
  cout << ans << endl;
}
 

    
