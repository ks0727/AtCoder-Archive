#include <iostream>
#include <vector>
using namespace std;
int x[2<<17];
int cnt[2<<17];

vector<bool> sieve(int x){
  vector<bool> isp(x+3,true);
  isp[0] = isp[1] = false;
  for(int i=2;i<=x;i++){
    if(!isp[i]) continue;
    isp[i] = true;
    for(int j=i*2;j<=x;j+=i){
      isp[j] = false;
    }
  }
  return isp;
}

int main()
{
  int n;
  cin >> n;
  const int M = 2e5;
  vector<bool> p = sieve(M);
  vector<int> ps;
  for(int i=0;i<p.size();i++) if(p[i]) ps.push_back(i);
  for(int i=1;i<=n;i++)
  {
    int now = i;
    for(int j=0;ps[j]*ps[j]<=i;j++)
    {
      long long sq = ps[j]*ps[j];
      while(now%sq == 0) now /= sq;
    }
    x[i] = now;
    cnt[now]++;
  }
  long long ans = 0;
  for(int i=1;i<=n;i++){
    ans += cnt[i]*(cnt[i]-1);
  }
  cout << ans+n<< endl;
  return 0;
}
