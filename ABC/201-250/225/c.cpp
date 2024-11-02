#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector b(n,vector<long long>(m));
  for(int i=0;i<n;i++)for(int j=0;j<m;j++) cin >> b[i][j],b[i][j]--;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(b[i][j] != (b[0][0]/7+i)*7+j+b[0][0]%7){
        cout << "No" << endl;
        return 0;
      }
      if(j != 0 && b[i][j]%7 == 0){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}

