#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> hato(n),cnt(n,1);
    set<int> st;
    rep(i,n) hato[i] = i;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int p,h;
            cin >> p >> h;
            p--; h--;
            if(cnt[hato[p]] == 2){
                st.erase(hato[p]);
            }
            cnt[hato[p]]--;
            hato[p] = h;
            cnt[h]++;
            if(cnt[h] >= 2){
                st.insert(h);
            }
        }else{
            cout << st.size() << endl;
        }
    }
    return 0;
}