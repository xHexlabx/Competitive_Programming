#include<bits/stdc++.h> 
using namespace std ;
int a[500001];
int b[500001];
bool cmp(int a, int b){
    return a > b ;
}
int main(){
    int n ; cin >> n ;
    int MAX  = INT_MIN ;
    int MIN  = INT_MAX ;
    for(int i = 0 ; i < n ; i ++ ){
        cin >> a[i] ;
    }
    for(int i = 0 ; i < n ; i ++ ){
        cin >> b[i] ;
    }
    sort(a , a + n);
    sort(b , b + n , cmp);
    for(int i = 0 ; i < n ; i ++ ){
        int now = a[i] + b[i] ;
        MAX = max(MAX , now) ;
        MIN = min(MIN , now) ;
    }
    cout << MAX - MIN ;
    return 0 ;
}