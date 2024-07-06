#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  int k;
  cin >> k;
  vector<string> cards(n);
  for(int i=0;i<n;++i) cin >> cards[i];
  vector<int> is;
  for(int i=0;i<n;++i) is.push_back(i);
  set<string> st;
  do{
    string ns = "";
    for(int ki=0;ki<k;++ki){
      ns += cards[is[ki]];
    }
    if(st.count(ns)) continue;
    st.insert(ns);
  }while(next_permutation(is.begin(),is.end()));
  cout << st.size() << endl;
  return 0;
}

