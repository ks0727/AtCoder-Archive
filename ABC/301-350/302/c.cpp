#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

bool replaceable(string a,string b){
    int cnt = 0;
    rep(i,a.size()){
        if(a[i] != b[i]) cnt++;
        if(cnt > 1) return false;
    }
    return true;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<int> p;
    rep(i,n) p.push_back(i);
    if(n == 2){
        if(replaceable(s[0],s[1])) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }
    do{
        rep(i,n-1){
            if(!replaceable(s[p[i]],s[p[i+1]])) break;
            if(i == n -2){
                cout << "Yes" << endl;
                return 0;
            } 
        }
    }while(next_permutation(p.begin(),p.end()));
    cout << "No" << endl;
    return 0;
}