#include <iostream>
#include <algorithm>
using namespace std;
string s[1<<17],t[1<<17];
bool match(string a, string b)
{
  int sa = a.size(); 
  int sb = b.size();
  if(sa != sb) return false;
  for(int i=0;i<sa;i++)
  {
    if(a[i] != b[i]) return false;
  }
  return true;
}
int main(){
  int n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++) cin >> s[i];
  for(int i=0;i<m;i++) cin >> t[i];
  int now = 0;
  for(int i=0;i<n;i++){
    if(match(s[i],t[now]))
       {
         cout << "Yes" << endl;
         now++;
       }
     else{
       cout << "No" << endl;
     }
   }
      
  return 0;
}

