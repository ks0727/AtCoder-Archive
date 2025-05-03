#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> k(m);
  vector<vector<int> > a(m);
  for(int i=0;i<m;i++){
    cin >> k[i];
    a[i].resize(k[i]);
    for(int j=0;j<k[i];j++) cin >> a[i][j],a[i][j]--;
  }
  vector<int> b(n);
  for(int i=0;i<n;i++) cin >> b[i],b[i]--;
  vector<int> order(n);
  for(int i=0;i<n;i++){
    order[b[i]] = i;
  }
  vector<int> last(m);
  for(int i=0;i<m;i++){
    for(int j=0;j<k[i];j++){
      last[i] = max(last[i],order[a[i][j]]);
    }
  }
  vector<int> ans(n);
  for(int i=0;i<m;i++){
    ans[last[i]]++;
  }
  int now = 0;
  for(int i=0;i<n;i++){
    now += ans[i];
    cout << now << endl;
  }

  return 0;
}

