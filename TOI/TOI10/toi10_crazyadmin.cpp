#include<bits/stdc++.h>
using namespace std;
int k , n , mid ;
int arr[101] ;
int MIN = INT_MIN , MAX = 150000 ;
int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);
    cin >> k >> n ; 
    for(int i = 1 ; i <= n ; i ++ ){
        cin >> arr[i] ;
        MIN = max(MIN , arr[i]) ;
    }
    //MIN -> lowest memory 
    //arr -> mem
    while(MIN < MAX){
        mid = (MIN + MAX) / 2 ;
         //mid -> cable mem
        int cnt = 0 ;
        int mem = 0 ;
        for(int j = 1 ; j <= n ; j ++ ){
            if(mem + arr[j] > mid){
                cnt ++ ;
                mem = arr[j] ;
            }
            else {
                mem += arr[j] ;
            }
        }
        if(mem != 0){
            cnt ++ ;
        }
        if(cnt <= k){
            MAX = mid ;
        }
        else {
            MIN = mid + 1 ;
        }
    }
    cout << MIN ;
    return 0 ;
}