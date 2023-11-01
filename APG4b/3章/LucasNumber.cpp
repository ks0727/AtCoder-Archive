#include<bits/stdc++.h>
using namespace std;

long long Lucas(int N){
    if(N == 0) return 2;
    else if(N == 1) return 1;
    long long lucas = Lucas(N-1) + Lucas(N-2);
    return lucas;
}

int main(){
    int N;
    cin >> N;
    long long L[87];
    L[0] = 2, L[1] = 1;
    for(int i=2;i<N;i++){
        L[i] = L[i-1] + L[i-2];
    }
    cout << L[N] << endl;
}
