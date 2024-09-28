#include <iostream>
#include <stack>
using namespace std;
int main(){
  int n;
  cin >> n;
  stack<pair<int,int> > st;
  st.push(make_pair(-1,0));
  int num = 0;
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    if(st.top().first == a){
      if(st.top().second == a-1){
         st.pop();
         num -= a-1;
      }
      else{
        num++;
        st.top().second++;
      }
    }else{
      st.push(make_pair(a,1));
      num++;
    }
    cout << num << '\n';
 }
  return 0;
}

