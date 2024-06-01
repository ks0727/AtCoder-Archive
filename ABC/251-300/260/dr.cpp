#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i,n) cin >> p[i],p[i]--;
    const int INF = 1001001001;
    set<int> piles;
    piles.insert(INF);
    vector<int> ans(n,-1),to(n,-1);
    vector<int> nums(n);
    rep(i,n){
        int now = p[i];
        int x = *piles.lower_bound(now);
        if(x == INF){ //そのカード以上の数がなかったら新しい山を作る
            nums[now] = 1;
            piles.insert(now);
        }else{ //xが見えている山に重ねる
            nums[now] = nums[x]+1;
            to[now] = x; //重ねたカードの下にはxがある
            piles.erase(x);
            piles.insert(now);
        }
        if(nums[now] >= k){
            piles.erase(now);
            while (now != -1){
                ans[now] = i+1;
                now = to[now];
            }
        }
    }
    rep(i,n) cout << ans[i] << endl;
    return 0;
}
