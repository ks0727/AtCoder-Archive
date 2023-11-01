#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int cnt = 0;
    int n;
    vector<int> s;
    s.push_back(1);
    while(true){
        if(cnt > 20) break;
        if(cnt == 0){
            cin >> n;
            cout << "? " + to_string(n-1) << endl;
        }
        else{
            int value;
            cin >> value;
            s.push_back(value);
            if(cnt >= 1){
                if(value != s[cnt-1]){
                    cout << "! " + to_string(n-cnt-1) << endl;
                    return 0;
                }
                cout << "? " +  to_string(n-1-cnt);
                cout << endl;
            }
        }
        cnt++;
    }
    return 0;
}