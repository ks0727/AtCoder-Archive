#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<string> t;
    int j = 0;
    while(true){
        bool isdone = true;
        string now = "";
        for(int i=n-1;i>=0;i--){
            if(s[i].size() > j){
                now += s[i][j];
                isdone = false;
            }else{
                now += '*';
            }
        }
        if(isdone) break;
        while(now.back() == '*' && now.size() > 0){
            now.pop_back();
        }
        t.push_back(now);
        j++;
    }
    for(string x : t){
        cout << x << endl;
    }
    return 0;
}