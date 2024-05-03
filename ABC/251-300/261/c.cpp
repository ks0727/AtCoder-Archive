#include <iostream>
#include <map>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
    int n; cin >> n;
    map<string,int> mp;
    rep(i,n){
        string s; cin >> s;
        if(!mp.count(s)){
            cout << s << endl;
            mp[s]++;
        }else{
            int d = mp[s];
            string t = to_string(d);
            string ns = s+'('+t+')';
            cout << ns << endl;
            mp[s]++;
        }
    }
    return 0;
}   