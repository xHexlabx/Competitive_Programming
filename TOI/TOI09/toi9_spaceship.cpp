#include<bits/stdc++.h>
using namespace std;
int k , x , y , z , n , MIN = INT_MAX ;
struct coor {
    int x , y , z , gx , gy , gz ;
};
bitset<21>visited ;
coor arr[21] ;
int pow(int x){
    return x * x ;
}
void solve(int cost , int nx , int ny , int nz , int gx , int gy , int gz){
    
    if(cost >= MIN)return ;
    
    if(gx >= k && gy >= k && gz >= k){
        MIN = min(MIN , cost) ;
        return ;
    }
    else{
        for(int i = 0 ; i < n ; i ++ ){
            if(visited[i])continue;
            visited[i] = true ;
            solve(cost + pow(arr[i].x - nx) + pow(arr[i].y - ny ) + pow(arr[i].z - nz) , arr[i].x, arr[i].y , arr[i].z , gx + arr[i].gx , gy + arr[i].gy , gz + arr[i].gz);
            visited[i] = false ;
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    cin >> k >> x >> y >> z >> n ;
    for(int i = 0 ; i < n ; i ++ ){
        cin >> arr[i].x  >> arr[i].y >> arr[i].z >> arr[i].gx >> arr[i].gy >> arr[i].gz ;
    }
    solve(0 , x , y , z , 0 , 0 , 0);
    cout << MIN ;
    return 0 ;
}