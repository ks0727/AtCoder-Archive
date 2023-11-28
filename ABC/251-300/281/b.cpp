#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    int n = s.size();
    if(n != 8){
        cout << "No" << endl;
        return 0;
    }
    if(s[0] >= 'A' && s[0] <= 'Z' && s[7] >= 'A' && s[7] <= 'Z'){
        string t = s.substr(1,6);
        rep(i,6){
            if(t[i] >= 'A' && t[i] <= 'Z'){
                cout << "No" << endl;
                return 0;
            }
        }
        int num = stoi(t);
        if(num >= 1e5 && num < 1e6){
            cout << "Yes" << endl;
            return 0;
        }else{
            cout << "No" << endl;
            return 0;
        }
    }else{
        cout << "No" << endl;
        return 0;
    }
    return 0;
}