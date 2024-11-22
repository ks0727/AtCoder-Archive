#include <iostream>
#include<set>
using namespace std;

int main(){
  set<int> st = {1,2,3,4,5,6};
  auto it = st.upper_bound(4);
  while(it != st.begin()){
    cout << *it << endl;
    it = st.erase(it); 
    it--;
  }
  return 0;
}

