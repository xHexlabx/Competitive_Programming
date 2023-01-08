#include<bits/stdc++.h>

using namespace std ;

vector<pair<int , int>>vec ;
bool cmp(pair<int , int>a, pair<int , int>b){
    return a.second < b.second ;
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    int n ; cin >> n ; 
    int now = -1 , cnt = 0 ;
    for(int i = 0 ; i < n ; i ++ ){
        int s , p ; cin >> s >> p ;
        vec.push_back({s , p});
    }
    sort(vec.begin(), vec.end() ,cmp);
    for(auto temp : vec){
        if(temp.first >= now){
            now = temp.second ;
            cnt ++ ;
        }
    }
    cout << cnt ;
    
    return 0 ;
}