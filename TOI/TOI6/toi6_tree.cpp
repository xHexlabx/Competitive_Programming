#include<bits/stdc++.h>
using namespace std;
int t = 5 , n ;
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    
    vector<pair<int , int>>node_1 ;
    vector<pair<int , int>>node_2 ;
    
    while(t-- ){
        node_1.clear() ;
        node_2.clear() ;
        int a , b , n ; cin >> n ;
        for(int i = 0 ; i < n - 1 ; i ++ ){
            cin >> a >> b ;
            node_1.push_back({min(a , b) , max(a , b)});
        }
        for(int i = 0 ; i < n - 1 ; i ++){
            cin >> a >> b ;
            node_2.push_back({min(a , b) , max(a , b)});
        }
        sort(node_1.begin(), node_1.end());
        sort(node_2.begin(), node_2.end());
        (node_1 == node_2) ? cout << 'Y' : cout << 'N' ;
    }
    return 0 ;
}