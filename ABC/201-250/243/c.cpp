#include <iostream>
#include <map>
#include <set>
using namespace std;
int x[2<<17],y[2<<17];
int main(){
  int n;
  cin >> n;
  map<int,int> left,right;
  for(int i=0;i<n;i++) cin >> x[i] >> y[i];
  string s;
  cin >> s;
  for(int i=0;i<n;i++){
    if(s[i] == 'R'){
      if(left.count(y[i]) && left[y[i]] > x[i]){
          cout << "Yes" << endl;
          return 0;
      }
      if(right.count(y[i])) right[y[i]] = min(right[y[i]],x[i]);
      else right[y[i]] = x[i];
    }else{
      if(right.count(y[i]) && right[y[i]] < x[i]){
        cout << "Yes" << endl;
        return 0;
      }
      if(left.count(y[i])) left[y[i]] = max(left[y[i]],x[i]);
      else left[y[i]] = x[i]; 
    }
  }
  cout << "No" << endl;
  return 0;
}

