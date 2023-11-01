#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

bool istrue(string t, string td){
    if(t.size() == td.size()){
        if(t == td) return true;
        int error = 0;
        rep(i,t.size()) if(t[i] != td[i]) error++;
        if(error <= 1) return true;
        else return false;
    }
    if(t.size() + 1 == td.size()){
        bool miss = false;
        rep(i,td.size()){
            if(!miss){
                if(t[i] != td[i]){
                    miss = true;
                    continue;
                }
            }else{
                if(t[i-1] != td[i]) return false;
            }
        }
        return true;
    }
    if(t.size() == td.size() + 1){
        bool miss = false;
        rep(i,t.size()){
            if(!miss) {
                if(t[i] != td[i]){
                    miss = true;
                    continue;
                }
            }else{
                if(t[i] != td[i-1]) return false;
            }
            
        }
        return true;
    }
    return false;
}

int main(){
    int n;
    string td;
    cin >> n >> td;
    vector<int> ans;
    rep(i,n){
        string t;
        cin >> t;
        if(istrue(td,t)) ans.push_back(i+1);
    }
    cout << ans.size() << endl;
    rep(i,ans.size()) cout << ans[i] << ' ';
    return 0;
}