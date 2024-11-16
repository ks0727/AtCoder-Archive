#include <iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
int main(){
  vector<int> A(9);
  for(int i=0;i<9;i++) cin >> A[i],A[i]--;
  vector<int> idx;
  for(int i=0;i<9;i++) idx.push_back(i);
  vector<vector<int> > arr = {
    {0,1,2},
    {3,4,5},
    {6,7,8},
    {0,3,6},
    {1,4,7},
    {2,5,8},
    {0,4,8},
    {2,4,6}
  };
  double shock = 0;
  do{
      vector<bool> opened(9);
      bool done = false;
      for(int k=0;k<9;k++){
        if(done) break;
        for(int i=0;i<arr.size();i++){
          auto f = [&](vector<int> c){
            int first = c[0],second = c[1],third = c[2];
            if(opened[first] && opened[second] && A[first] == A[second]) return true;
            if(opened[first] && opened[third] && A[first] == A[third]) return true;
            if(opened[second] && opened[third] && A[second] == A[third]) return true;
            return false;
          };
          if(f(arr[i])){
            shock++;
            done = true;
            break;
          }
          if(i == arr.size()-1){
            opened[idx[k]] = true;
          }
        }
      }
  }while(next_permutation(idx.begin(),idx.end()));
  double all = 1;
  for(int i=1;i<=9;i++) all *= i;
  cout << all << ' ' << shock << endl;
  double ans = (all-shock)/all;
  printf("%.10f\n",ans);
}
