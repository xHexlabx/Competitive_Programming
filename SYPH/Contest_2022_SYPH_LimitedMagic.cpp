#include <iostream>
 
using namespace std;
 
string add(string a,string b){
    string c;
    int r=0;
 
    int i=a.length()-1,j=b.length()-1;
    while(i>=0 || j>=0){
        if(i>=0 && j>=0){
            c = char(((a[i]+b[j]-'0'-'0'+r)%10)+'0') + c;
            r = (a[i]+b[j]-'0'-'0'+r)/10;
            i--,j--;
        }else{
            if(i>=0){
                c = char(((a[i]-'0'+r)%10)+'0') + c;
                r = (a[i]-'0'+r)/10;
                i--;
            }else{
                c = char(((b[j]-'0'+r)%10)+'0') + c;
                r = (b[j]-'0'+r)/10;
                j--;
            }
        }
    }
 
    if(r){
        c = char(r+'0') + c;
    }
 
    return c;
}
 
int main(){
 
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
 
    int n; cin >> n;
 
    string a; cin >> a;
    
    int zeros=0;
    bool iszero= a=="0";
    for(int i=0 ; i<n-1 ; i++){
        string b; cin >> b;
 
        if(b=="0") iszero=true;
 
        string ans="0";
 
        {
            string tmp="";
            bool notzero=false;
            for(int j=b.length()-1 ; j>=0 ; j--){
                if(notzero || b[j]!='0'){
                    notzero=true;
                    tmp = b[j]+tmp;
                }else{
                    zeros++;
                }
            }
            if(tmp.length()!=0) b=tmp;
        }
 
        {
            string tmp="";
            bool notzero=false;
            for(int j=a.length()-1 ; j>=0 ; j--){
                if(notzero || a[j]!='0'){
                    notzero=true;
                    tmp = a[j]+tmp;
                }else{
                    zeros++;
                }
            }
            if(tmp.length()!=0) a=tmp;
        }
 
        if(a.length() > b.length()){
            for(string j="0" ; j!=b && b!="0" ; j=add(j,"1")){
                ans=add(ans,a);
            }
        }else{
            for(string j="0" ; j!=a && a!="0" ; j=add(j,"1")){
                ans=add(ans,b);
            }
        }
        a = ans;
    }
 
    if(iszero){
        cout << "0";
    }else{
        cout << a;
        for(int i=0 ; i<zeros ; i++)cout << "0";
    }
 
    return 0;
}