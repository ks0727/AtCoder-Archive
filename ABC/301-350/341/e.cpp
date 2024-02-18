#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)

int op(int a,int b){
    return a+b;
}
int e(){
    return 0;
}
int main(){
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    segtree<int,op,e> seg(n);
    rep(i,n){
        if(s[i] == '1') seg.set(i,1);
        else seg.set(i,0);
    }
    rep(qi,q){
        int type,l,r;
        cin >> type >> l >> r;
        l--;
        if(type == 1){
            for(int i=l;i<r;i++){
                int now = seg.get(i);
                now ^= 1;
                seg.set(i,now);
            }
        }
        if(type == 2){
            int sum = seg.prod(l,r);
            if((r-l+1)%2 == 0){
                if(sum == (r-l+1)/2) cout << "Yes" << endl;
                else cout << "No" << endl;
            }else{
                if(seg.get(l) == 0){
                    if(sum == (r-l+1)/2) cout << "Yes" << endl;
                    else cout << "No" << endl;
                }else{
                    if(sum == (r-l+2)/2) cout << "Yes" << endl;
                    else cout << "No" << endl;
                }
            }
            cout << sum << endl;
        }
    }
    return 0;
}