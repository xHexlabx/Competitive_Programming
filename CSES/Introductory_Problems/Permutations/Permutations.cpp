#include<bits/stdc++.h>

using namespace std;

int n ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    if(n == 1){
        cout << 1 ;
    }
    else if (n <= 3) {
        cout << "NO SOLUTION" ;
    }
    else {
        for(int i = 2 ; i <= n ; i += 2){
            cout << i << ' ' ;
        }
        for(int i = 1 ; i <= n ; i += 2){
            cout << i << ' ' ;
        }
    }
    
    return 0 ;
}