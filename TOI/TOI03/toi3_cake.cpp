#include<bits/stdc++.h>
using namespace std;
float arr[] = {1.00 , 0.75 , 0.50 , 0.25 , 0.125} ;
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    int q ; cin >> q ;
    float res = 0 ;
    while(q -- ){
        float n ;
        for(int i = 0 ; i < 5 ; i ++ ){
            cin >> n ;
            res += arr[i] * n ;
        }
    }
    cout << ceil(res) ;
    return 0 ;
}