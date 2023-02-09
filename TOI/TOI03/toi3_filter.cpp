#include<bits/stdc++.h>
using namespace std;
int arr[3001] ;
int w , h , t ,sum_0 , sum_1 ;
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0);
    cin >> w >> h >> t ;
    while(t -- ){
        int l , r ; cin >> l >> r ;
        for(int i = l ; i < l + r ; i ++ ){
            arr[i] ++ ;
        }
    }
    for(int i = 0 ; i < w ; i ++ ){
        if(arr[i] == 0)sum_0 += h ;
        if(arr[i] == 1)sum_1 += h ;
    }
    cout << sum_0 << ' ' << sum_1 ;
}