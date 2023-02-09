#include<bits/stdc++.h>
using namespace std;
struct node {
    int x , y ;
};
int n , k , res = 0 , now = 0 ;
int dis[15001] ;
vector<int>ans ;
node arr[15001] ;
bool visited[15001] ;
int cal(node a , node b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    cin >> n >> k ;
    for(int i = 0 ; i < n ; i ++ ){
        cin >> arr[i].x >> arr[i].y ;
        dis[i] = INT_MAX ;
    }
    for(int i = 0 ; i < n - 1 ; i ++ ){
        int MIN = INT_MAX ;
        int idx ;
        for(int j = 1 ; j < n ; j ++ ){
            
            if(visited[j])continue ;
            int nowdis = cal(arr[now] , arr[j]) ;
            dis[j] = min(dis[j] , nowdis) ;
            if(dis[j] < MIN){
                MIN = dis[j] ;
                idx = j ;
            }
        }
        now = idx ;
        visited[now] = true ;
        ans.push_back(MIN) ;
    }
    sort(ans.begin() , ans.end()) ;
    for(int i = 0 ; i < n - k ; i ++ ){
        res += ans[i] ;
    }
    cout << res ;
    
    return 0;
}