#include <iostream>
#include <set>
using namespace std;

string ss[100],ts[100];

int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;i++) cin >> ss[i] >> ts[i];
  for(int i=0;i<n;i++){
    bool sok = true,tok = true;
    for(int j=0;j<n;j++){
      if(i == j) continue;
      if(ss[i] == ss[j] || ss[i] == ts[j]) sok = false;
      if(ts[i] == ts[j] || ts[i] == ss[j]) tok = false;
    }
    if(!sok && !tok){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}

