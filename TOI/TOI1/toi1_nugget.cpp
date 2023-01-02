#include<bits/stdc++.h>
using namespace std;
bitset<101>nugget ;
void generate(int n){
    
    if(n > 100)return ;
    nugget[n] = true ;
    generate(n + 6) ;
    generate(n + 9) ;
    generate(n + 20) ;
}
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    int n ; cin >> n ;
    
    if(n <= 5)cout << "no" ;
    else {
        generate(0);
        for(int i = 6 ; i <= n ; i ++ ){
            if(nugget[i])cout << i << '\n' ;
        }
    }
    return 0 ;
}