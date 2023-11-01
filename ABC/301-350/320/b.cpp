#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

bool isPali(string s, int size){
    if(size == 1) return true;
    if(size % 2 == 0){
        rep(i,size){
            if(s[i] != s[size-(i+1)]) return false;
            if(size - (i+1) == size / 2) return true;
        }
    }
    if(size % 2 == 1){
        rep(i,size){
            if(s[i] != s[size-(i+1)]) return false;
            if(i == size / 2) return true;
        }
    }
    return false;
}

int main(){
    string s;
    cin >> s;
    int size = s.size();
    int ans = 1;
    int current = 0;
    rep(i,size){
        rep(j,size){
            if(i != j){
                if(s[i] == s[j]){
                    string candidate;
                    if(i == 0) candidate = s.substr(i,j+1);
                    else candidate = s.substr(i,j-i+1);
                    int can_size = candidate.size();
                    if(isPali(candidate,can_size)) {
                        current = can_size;
                    }
                    else current = 0;
                    ans = max(ans,current);
                }
            }
            else current = 0;
        }
    }
    cout << ans << endl;
    return 0;
}