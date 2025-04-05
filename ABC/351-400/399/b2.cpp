#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<pair<int,int> > p(n);
  for(int i=0;i<n;i++) cin >> p[i].first;
  for(int i=0;i<n;i++) p[i].second = i;
  sort(p.rbegin(),p.rend());
  int r = 0;
  int now = -1;
  int k = 1;
  vector<int> arr(n);
  for(int i=0;i<n;i++){
    if(p[i].first == now){
        arr[p[i].second] = r;
        k++;
    }else{
      r += k;
      arr[p[i].second] = r;
      k = 1;
      now = p[i].first;
    }
  }
  for(int i=0;i<n;i++){
    cout << arr[i] << endl;
  }
}


