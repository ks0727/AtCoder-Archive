#include <iostream>
#include <set>
#include <map>
using namespace std;

int main(){
  int ax=101,ay=101;
  map<int,int> xs,ys;
  for(int i=0;i<3;i++){
    int x,y;
    cin >> x >> y;
    xs[x]++; ys[y]++;
  }
  int x=-101,y=-101;
  for(auto [v,c] : xs){
    if(c == 1) x = v;
  }
  for(auto [v,c] : ys){
    if(c == 1) y = v;
  }
  cout << x << ' ' << y << endl;
  return 0;
}

