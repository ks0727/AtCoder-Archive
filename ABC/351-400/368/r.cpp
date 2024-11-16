#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;

int main(){
  const int M = 100005;
  vector<int> g(M);
  vector<vector<int> > divs(M);
  for(int i=1;i<M;i++){
    for(int j=i*2;j<M;j+=i) divs[j].push_back(i);
  }
  for(int i=1;i<M;i++){
    set<int> st;
    for(int d : divs[i]) st.insert(g[d]);
    while(st.count(g[i])) g[i]++; //いま,数iのgrundy数は,iの約数のgrundy数のmexになる
  }
  int n; 
  cin >> n;
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    x ^= g[a];
  }
  if(x == 0) cout << "Bruno" << endl;
  else cout << "Anna" << endl;
}
  
