//number gussing number
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    srand(time(0));
    int randomNumber =(rand()%100)+1;
   // printf("Random number :%d\n",randomNumber);
   int no_of_guesses =0;
   int guessed;
   do{
printf("guess the number\n");
scanf("%d",&guessed);
if(guessed>randomNumber){
printf("lower number please\n");}
else{
    printf("higger number please\n");
}
no_of_guesses++;
   }while(guessed!=randomNumber);
   printf("you guessed the number in %d guesses",no_of_guesses);
    return 0;
}