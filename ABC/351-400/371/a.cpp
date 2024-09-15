#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    char ab,ac,bc;
    cin >> ab >> ac >> bc;
    int a=0,b=0,c=0;
    if(ab == '>') a++;
    else b++;
    if(ac == '>') a++;
    else c++;
    if(bc == '>') b++;
    else c++;
    if(a == 1) cout << 'A' << endl;
    else if(b == 1) cout << 'B' << endl;
    else cout << 'C' << endl;
    return 0;
}