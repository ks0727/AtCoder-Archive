#include<iostream>
using namespace std;
int main(){
    int flag = 0;
    int n;
    long long x;
    cin >> n >> x;
    long long  a[n];
    for(int i=0;i<n ;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(a[i] - a[j] == x){
                flag = 1;
            }
        }
    }
    if(flag == 1){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}