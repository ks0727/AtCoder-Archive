#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
using ll = long long;
int main(){
  ll h,w,si,sj;
  cin >> h >> w >> si >> sj;
  si--; sj--;
  int n;
  cin >> n;
  map<ll,set<ll> > rows,cols;
  for(int i=0;i<n;i++){
    ll r,c;
    cin >> r >> c;
    r--; c--;
    rows[r].insert(c);
    cols[c].insert(r);
  }
  int q;
  cin >> q;
  ll ci = si, cj = sj;
  while(q--){
    char d; ll l;
    cin >> d >> l;
    if(d == 'L'){
      if(!rows.count(ci)){
        cj = max(0LL,cj-l);
      }
      else{
        ll nxt = max(0LL,cj-l);
        auto it = rows[ci].lower_bound(cj);
        if(it == rows[ci].begin()) cj = nxt;
        else{
          it--;
          if(*it >= nxt){
            cj = *it+1;
          }else{
            cj = nxt;
          }
        }
      }
    }
    else if(d == 'R'){
      if(!rows.count(ci)){
         cj = min(w-1,cj+l);
       }
      else{
        ll nxt = min(w-1,cj+l);
        auto it = rows[ci].lower_bound(cj);
        if(it == rows[ci].end()) cj = nxt;
        else{
          if(*it < nxt){
            cj = *it-1;
          }else{
            cj = nxt;
          }
        }
      }
    }
    else if(d == 'U'){
      if(!cols.count(cj)){
          ci = max(0LL,ci-l);
       }
      else{
        ll nxt = max(0LL,ci-l);
        auto it = cols[cj].lower_bound(ci);
        if(it == cols[cj].begin()) ci = nxt;
        else{
          it--;
          if(*it >= nxt){
            ci = *it+1;
          }
        }
      }
    }
    else if(d == 'D'){
      if(!cols.count(cj)){
        ci = min(ci+l,h-1);
      }
      else{
        ll nxt = min(h-1,ci+l);
        auto it = cols[cj].lower_bound(ci);
        if(it == cols[cj].end()) ci = nxt;
        else{
          if(*it <= nxt){
            ci = *it-1;
          }else{
            ci = nxt;
          }
        }
      }
    }
    cout << ci+1 << ' ' << cj+1 << endl;
  }
}

