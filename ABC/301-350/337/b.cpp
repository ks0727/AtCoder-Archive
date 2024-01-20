#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    int n = s.size();
    string abc = "ABC";
    int target = 0;
    if(s[0] != 'A' && s[0] != ' '){
        cout << "No" << endl;
        return 0;
    }
    char prev = s[0];
    auto isok = [&](string s, int n){
        rep(i,n){
            if(prev == ' ' && s[i] != ' '){
                prev = s[i];
                continue;
            } 
            if(prev == 'A' && s[i] != 'A' && s[i] != 'B' && s[i] != ' ') return false;
            if(prev == 'A' && s[i] == 'B') {
                prev = 'B';
                continue;
            }
            if(prev == 'A' && s[i] == ' ') {
                prev = 'B';
                continue;
            }
            if(prev == 'B' && s[i] != 'B' && s[i] != 'C' && s[i] != ' ') return false;
            if(prev == 'B' && s[i] == 'C'){
                prev = 'C';
                continue;
            }
            if(prev == 'C' && s[i] != 'C' && s[i] != ' ') return false;
        }
        return true;
    };
    if(isok(s,n)) cout << "Yes" << endl;
    else cout << "No" <<endl;
    return 0;
}