#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int left = -1;
    int right = n;
    int nl=0,nr = 0;
    long long ans = 0;
    while(left != right){
        bool upd_right = true;
        if(nl <= nr){
            left++;
            upd_right = false;
        }else right--;
        if(right == left) break;
        if(!upd_right && s[left] == '1'){
            nl++;
        }else if(!upd_right && s[left] == '0'){
            ans += nl;
        }
        if(upd_right && s[right] == '1'){
            nr++;
        }else if(upd_right && s[right] == '0'){
            ans += nr;
        }
    }
    cout << ans << endl;
    return 0;
}