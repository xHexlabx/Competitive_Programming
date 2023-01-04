#include<bits/stdc++.h>
#define umap unordered_map
using namespace std ;
string del_num(string a){
	string temp = "";
	for(int i = 0 ; i < a.size() ; i ++){
		if(a[i] >= 'A')temp += a[i];
	}
	return temp ;
}
int main(){
	
	string n ; string dir ;
	
	umap<string , double> sum ;
	
	do{	
	
		cin >> dir ;
		if(dir == "*")break ;
		n = "" ;
		for(int i = 0 ; i < dir.size() ; i ++){
			if(dir[i] < 'A'){
				n += dir[i] ;
			}
		}
		sum[del_num(dir)] += stod(n); 
		
	}while(true);
	
	double x , y ; 
	y = sum["N"] + sum["NW"] / sqrt(2) + sum["NE"] / sqrt(2) - sum["S"] - sum["SE"] / sqrt(2) - sum["SW"] / sqrt(2) ; 
	x = sum["E"] + sum["NE"] / sqrt(2) + sum["SE"] / sqrt(2) - sum["W"] - sum["NW"] / sqrt(2) - sum["SW"] / sqrt(2) ;
	
	printf("%.3lf %.3lf\n%.3lf" , x , y , sqrt( x*x + y *y ) );
	return 0 ;
}