#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int ans = 0;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin >> A.at(i);
    while(true){
        bool isBreak = false;
        for(int i=0;i<N;i++){
        if(A.at(i) % 2 == 0){
            A.at(i) /= 2;
            if(i == N-1) ans++;
        }
        else{
            isBreak = true;
            break;
        }
        }
        if(isBreak) break; 
    }
    
    cout << ans << endl;
}