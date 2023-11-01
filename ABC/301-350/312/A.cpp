#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    bool ans = false;
    if(S == "ACE"){
        ans = true;
    }
    else if(S == "BDF") ans = true;
    else if(S == "CEG") ans = true;
    else if(S == "DFA") ans = true;
    else if(S == "EGB") ans = true;
    else if(S == "FAC") ans = true;
    else if(S == "GBD") ans = true;
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}