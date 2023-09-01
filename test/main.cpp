#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){

    char number [1000] ;

    scanf("%s" , number) ; 

    float n = 0 ;
    float sum = 0 ;
    float average = 0 ;

    if(strcmp(number , "exit") == 0){
        printf("None") ;
        return 0 ;
    }

    while(strcmp(number , "exit") != 0){

        n += 1 ;

        int length = strlen(number) ;
        
        for(int i = 0 ; i < length ; i++){

            sum += (number[i] - '0') * (pow(10 , length - i - 1)) ;

        }

        scanf("%s" , number) ;
    }

    printf("%f" , sum / n) ;


    return 0 ;
}