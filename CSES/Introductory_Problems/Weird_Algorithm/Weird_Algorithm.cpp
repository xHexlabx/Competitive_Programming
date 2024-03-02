#include<bits/stdc++.h>

using namespace std;

long long n ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);

    cin >> n ;

    while(true){

        cout << n << ' ' ;
        
        if(n == 1)break ;

        if(n & 1){
            n = n * 3 + 1 ;
        }
        else {
            n /= 2 ;
        }
    }

    return 0 ;
}