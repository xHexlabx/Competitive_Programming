#include<bits/stdc++.h>
#define vec vector
#define endll '\n'
#define umap unordered_map
using namespace std ;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n ,k; cin >> n >> k;
    vec<int>line(90001);
    vec<int>ans(90001);
    int temp ;
    while(n--){
        cin >> temp;
        line[temp] = 1;
        ans[temp] = 1;
    }
    for(int i = 1 ; i <= temp ; i ++ ){
        line[i] = max(line[i],line[i] + line[i-1]);
    }
    int max = INT_MIN;
    for(int i = 0 ; i <= temp ; i ++ ){
        if(ans[i] == 1){
            ans[i] = line[i+k] - line[i];
        }
        if(ans[i] > max)max = ans[i];
    }
    cout << max;
}