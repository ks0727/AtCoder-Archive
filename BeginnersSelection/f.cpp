#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int Alice=0, Bob = 0;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin >> A[i];
    sort(A.rbegin(),A.rend());
    for(int i=0;i<N;i++){
        if(i%2 == 0) Alice += A[i];
        else Bob += A[i];
    }
    cout << Alice - Bob << endl;
}