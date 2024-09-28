#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    set<int> st;
    rep(i,n-2){
        if(s[i] != 'A') continue;
        if(s[i+1] == 'B' && s[i+2] == 'C') st.insert(i);
    }
    //for(int x :st) cout << x << ' '; cout << endl;
    rep(qi,q){
        int x; char c;
        cin >> x >> c;
        x--;
        if(s[x] == 'A'){
            if(x<=n-3){
                if(s[x+1] == 'B' && s[x+2] == 'C'){
                    if(c != 'A'){
                        st.erase(x);
                        s[x] = c;
                    } 
                }else{
                    s[x] = c;
                }
            }else{
                s[x] = c;
            }
        }else if(s[x] == 'B'){
            if(x>=1 && x <=n-2){
                if(s[x-1] == 'A' && s[x+1] == 'C'){
                    if(c != 'B'){
                        st.erase(x-1);
                        s[x] = c;
                    }
                }else{
                    s[x] = c;
                }
            }else{
                s[x] = c;
            }
        }else if(s[x] == 'C'){
            if(x>=2){
                if(s[x-2] == 'A' && s[x-1] == 'B'){
                    if(c != 'C'){
                        st.erase(x-2);
                        s[x] = c;
                    }
                }else{
                    s[x] = c;
                }
            }else{
                s[x] = c;
            }
        }else{
            s[x] = c;
        }
        if(x<=n-3 && s[x] == 'A' && s[x+1] == 'B' && s[x+2] == 'C') st.insert(x);
        if(1<=x && x<=n-2 && s[x] == 'B' && s[x-1] == 'A' && s[x+1] == 'C') st.insert(x-1);
        if(x>=2 && s[x-2] == 'A' && s[x-1] == 'B' && s[x] == 'C') st.insert(x-2);
        
        cout << st.size() << endl;
    }
    return 0;
}