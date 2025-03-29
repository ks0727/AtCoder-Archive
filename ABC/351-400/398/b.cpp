#include <iostream>
#include<vector>
using namespace std;

int main(){
  vector<int> cnt(14);
  for(int i=0;i<7;i++){
    int a;
    cin >> a;
    cnt[a]++;
  }
  int three=0;
  int two = 0;
  for(int i=0;i<14;i++){
    if(cnt[i] == 2) two++;
    else if(cnt[i] >= 3) three++;
  }
  if(three>=2) cout << "Yes" << endl;
  else if(three==1&&two>=1) cout << "Yes" << endl;
  else cout << "No" << endl; 
  return 0;
}

