#include <stdio.h>
#include <conio.h> 
#include <stdlib.h>
#include <time.h>

//if语句的训练自添加作业：猜数字//

//basic one：//
void guess(int lowerbound,int upperbound,int num);
int main(){
    int a,b,c,d;
    // c=rand();/*access random number*/;  
    //↑That's not perfact,because if u run this program again you'll find that the aim num is the same as the first-runned aim number... 
    //So I prefer using srand(xtime(NULL)) than just a rand() function.
    //Now I learnt how to access a random number :).

    srand((unsigned int)time(NULL));
    c=rand();

    printf("enter two natural numbers to define the range you want to guess:");
    scanf("%d%d",&a,&b);

    if(a!=b && b>a){
         d=(c+1-a-b);
         c=(d>=0) ? (d%(b-a)+a) : ((-d)%(b-a)+a);/*Is this a necessity to add () before : ?*/
         printf("A natural number has been prepared in [%d,%d].\nTry to guess it. :)\n",a,b);
         guess(a,b,c);

    }else if(a!=b && b<a){
         d=(c+1-a-b);
         c=(d>=0) ? (d%(a-b)+a) : ((-d)%(a-b)+a);/* : equals else*/
         printf("A natural number has been prepared in [%d,%d].\nTry to guess it. :)\n",b,a);
         guess(b,a,c);


    }else{
         printf("wrong input :( \nRun it again!");
    }

    
}

void guess(int lowerbound/*the minium num*/,int upperbound/*the maximum num*/,int num){
    int count=1;
    int i;
    int current_min=lowerbound,current_max=upperbound;

   do{
    scanf("%d",&i);
    /*What if someone enters a "str" or "float" or even " "? The security should be concerned...*/
    //However,I don't have the capability to make it safer. 
    
        if(i<num){
            current_min=i;
             printf("\nwhat you have given is smaller than the aim number.\nThe aim number is in [%d,%d]\nYou may try it again:\n",current_min,current_max);
             count++;

         }else if 
         (i>num){
            current_max=i;
             printf("\nwhat you have given is larger than the aim number.\nThe aim number is in [%d,%d]\nYou may try it again:\n",current_min,current_max);
             count++;

         }
   }while(i!=num);
   printf("\nYou nailed it!\nThe number is %d,and you have guessed for %d times.",num,count);
}

