#include <iostream>
#include <queue>
using namespace std;
int cnt[1<<25];
int main(){
  long long a,n;
  cin >> a >> n;
  queue<long long> q;
  q.push(1);
  for(int i=0;i<1e7+1;i++) cnt[i] = -1;
  cnt[1] = 0;
  while(!q.empty())
  {
    int v = q.front(); q.pop();
    {
      long long nx = (long long)v*a;
      if(nx <= 1e7 && cnt[nx] == -1){
         q.push(nx);
         cnt[nx] = cnt[v]+1;
       }
    }
    {
      if(v<=10 || v %10 == 0) continue;
      long long nt = v%10;
      int d = 0;
      long long nx = v/10;
      long long sv = v;
      while(v){
        v/=10;
        d++;
      }
      long long add = 1;
      for(int i=0;i<d-1;i++) add *= 10;
      nx += add*nt;
      if(cnt[nx] != -1) continue;
      q.push(nx);
      cnt[nx] = cnt[sv] + 1;
    }
  }
  cout << cnt[n] << endl;

  return 0;
}

