#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<char,int>;
int main(){
    string s,t;
    cin >> s >> t;
    vector<P> ns,nt;
    rep(i,s.size()){
        int j = i;
        while(s[j] == s[j+1] && j < s.size()-1) j++;
        ns.push_back(P(s[i],j-i+1));
        i = j;
    }
    rep(i,t.size()){
        int j = i;
        while(t[j] == t[j+1] && j < t.size()-1) j++;
        nt.push_back(P(t[i],j-i+1));
        i = j;
    }
    if(ns.size() != nt.size()){
        cout << "No" << endl;
        return 0;
    }
    rep(i,ns.size()){
        //cout << ns[i].first << ' ' << ns[i].second << endl;
        //cout << nt[i].first << ' ' << nt[i].second << endl;
        if(ns[i].first != nt[i].first){
            cout << "No" << endl;
            return 0;
        }
        if(ns[i].second == 1 && nt[i].second >= 2){
            cout <<"No" << endl;
            return 0;
        }
        if(ns[i].second > nt[i].second){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}