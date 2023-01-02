#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    int n , q ; cin >> n >> q ;
    string first , second ; 
    cin >> first ;
    for(int i = 0 ; i < q - 1 ; i ++ ){
        cin >> second ;
        int diff = 0 ;
        for(int j = 0 ; j < n ; j ++ ){
            if(first[j] != second[j])diff ++ ;
        }
        if(diff > 2){
            cout << first ;
            return 0 ;
        }
        first = second ;
    }
    cout << first ;
    return 0 ;
}