#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    char now = '0';
    string t = "";
    for(int i=n-1;i>=0;i--){
        if(s[i] == now) continue;
        else{
            int add = i+1;
            if(now == '0'){
                string nt(add,'A');
                t += nt;
                now = '1';
            }else{
                string nt(add,'B');
                t += nt;
                now = '0';
            }
            //cout << t << endl;
        }
    }
    cout <<t.size() << endl;
    cout << t << endl;
    return 0;
}