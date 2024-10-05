#include <iostream>
using namespace std;
int a[4<<17],cnt[4<<17];;
int main(){
  int n;
  cin >> n;
  for(int i=0;i<4*n-1;i++)
  {
    int a;
    cin >> a;
    a--;
    cnt[a]++;
  }
  for(int i=0;i<n;i++)
  {
    if(cnt[i] == 3)
    {
      cout << i+1 << endl;
      return 0;
    }
  }
  return 0;
}

