#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > d(m);
    for(int i=1;i<(n);i++){
        int a;
        cin >> a;
        a += i;
        // 0 <= a+ix < n
        int l = (0 <= a) ? 0 : ((-a+i-1)/i);  //0を初めて越えるのはいつか
        int r = (n <= a) ? 0 : ((-(a-n)+i-1)/i); //nを初めて越えるのはいつか
        r = min(r,m);
        for(int j = l;j<r;j++){
            d[j].push_back(a+i*j);
        }
    }
    rep(mi,m){
        auto& b = d[mi];
        int sz = b.size();
        vector<bool> e(sz+1); //ある値が存在しているか？
        for(int i : b) if(i <= sz) e[i] = true;
        int ans = 0;
        while(e[ans]) ans++;
        cout << ans << '\n';
    }
    return 0;
}