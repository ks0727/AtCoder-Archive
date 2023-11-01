#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,A;
    cin >> N >> A;
    char operater;
    int value,ans;
    ans = A;
    for(int i=0;i<N;i++){
        cin >> operater >> value;
        if(operater == '+'){
            ans += value;
        }
        else if(operater == '-'){
            ans -= value;
        }
        else if(operater == '*'){
            ans *= value;
        }
        else if(operater == '/'){
            if(value == 0){
                cout << "error" << endl;
                break;
            }
            else{
                ans /= value;
                ans = int(ans);
            }
        }
        cout << i + 1 << ':' << ans << endl;
    }
}