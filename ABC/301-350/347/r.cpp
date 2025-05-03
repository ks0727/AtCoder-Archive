#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;
  vector<vector<int> > id(n);
  vector<int> cnt(q);
  set<int> st;
  for(int i=0;i<q;i++){
    int x;
    cin >> x;
    x--;
    id[x].push_back(i);
    if(st.count(x)) st.erase(x);
    else st.insert(x);
    cnt[i] = st.size();
  }
  vector<long long> s(q+1);
  for(int i=0;i<q;i++) s[i+1] = s[i] + cnt[i];
  vector<long long> ans(n);
  for(int i=0;i<n;i++){
    id[i].push_back(q);
    for(int j=0;j<id[i].size();j+=2){
      if(j+1 < id[i].size() && id[i][j+1] < q+1) ans[i] += s[id[i][j+1]] - s[id[i][j]];
    }
    cout << ans[i] << ' ';
  }
  cout << endl;
}


