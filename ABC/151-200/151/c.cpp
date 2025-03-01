#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<bool> isAc(n);
  vector<int> nwa(n);
  for(int i=0;i<m;i++){
    int p; string s;
    cin >> p >> s;
    p--;
    if(s == "AC") isAc[p] = true;
    else{
      if(!isAc[p]) nwa[p]++;
    }
  }
  int ac = 0, wa = 0;
  for(int i=0;i<n;i++){
    if(!isAc[i]) continue;
    wa += nwa[i];
    ac++;
  }
  cout << ac << ' ' << wa << endl;
  return 0;
}

