#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

bool istrue(string t, string td){
    if(t.size() == td.size()){
        if(t == td) return true;
        int error = 0;
        rep(i,t.size()){
            if(t[i] != td[i]) error++;
        }
        if(error <= 1) return true;
        else return false;
    }
    if(t.size() == td.size() -1){
        string test_t = "",test_td="";
        rep(i,td.size()){
            if(i == td.size()-1) return true;
            if(t[i] != td[i]) continue;
            test_t += t[i];
            test_td += td[i];
        }
        if(test_t == test_td) return true;
        else return false;
    }
    if(t.size() -1 == td.size()){
        string test_t = "",test_td="";
        rep(i,t.size()){
            if(i == t.size()-1) return true;
            if(t[i] != td[i]) continue;
            test_t += t[i];
            test_td += td[i];
        }
            if(test_t == test_td) return true;
            else return false; 
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
    if(ans.size() == 0) cout << endl;
    else rep(i,ans.size()) cout << ans[i] << ' ';
    return 0;
}