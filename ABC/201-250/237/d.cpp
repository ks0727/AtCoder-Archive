#include <iostream>
#include <cassert>
using namespace std;
struct ds{
  int l,r;
  ds(int l=-1,int r=-1):l(l),r(r){}
};
ds a[5<<17];
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  for(int i=0;i<n;i++)
  {
    if(s[i] == 'L')
    {
      if(a[i].l != -1) a[a[i].l].r = i+1;
      a[i+1].l = a[i].l;
      a[i].l = i+1;
      a[i+1].r = i;
    }else
    {
      if(a[i].r != -1) a[a[i].r].l = i+1;
      a[i+1].r = a[i].r;
      a[i].r = i+1;
      a[i+1].l = i;
    }
  }
  int si = -1;
  //for(int i=0;i<n+1;i++) cout << a[i].l << ' ' << i << ' ' << a[i].r << endl;
  for(int i=0;i<n+1;i++) if(a[i].l == -1) si = i;
  assert(si !=-1); 
  while(a[si].r != -1)
  {
    cout << si << ' ';
    si = a[si].r;
  }
  cout << si << ' ';
  cout << endl;
  return 0;
}

