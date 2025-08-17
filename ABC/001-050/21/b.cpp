#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a,b;
  cin >> a >> b; a--; b--;
  vector<bool> visited(n);
  visited[a] = visited[b] = true;
  int k;
  cin >> k;
  for(int i=0;i<k;i++){
    int x;
    cin >> x;
    x--;
    if(visited[x]){
      cout << "NO" << endl;
      return 0;
    }
    visited[x] = true;
  }
  cout << "YES" << endl;
  return 0;
}

