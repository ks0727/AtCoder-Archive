#include <iostream>
#include<vector>
#include<atcoder/dsu>
using namespace atcoder;
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> dim(n);
  dsu uf(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    dim[a]++;
    dim[b]++;
    uf.merge(a,b);
  }
  if(n != m){
    cout << "No" << endl;
    return 0;
  }
  for(int i=0;i<n;i++){
    if(dim[i] != 2){
      cout << "No" << endl;
      return 0;
    }
  }
  vector<vector<int> > d = uf.groups();
  if(d.size() != 1){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}

