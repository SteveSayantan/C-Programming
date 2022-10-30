#include <stdio.h>

void MeterToKm();
void CelToF();


int main()
{
    while(1){
        
        int input;
        printf("Press 1: Meter to KiloMeter\nPress 2: Celcius to Farenheit\nPress 3: Exit\n");
        scanf("%d",&input);
        
        switch(input){
           case 1: MeterToKm();
           break;
           case 2: CelToF();
           break;
           case 3: goto end;
           break;
           default: printf("Invalid Input\n");
        }
    }
   
    end:
    printf("Program Over");
    return 0;
}

void MeterToKm(){
    int num;
    printf("Enter the number in meter:\n");
    scanf("%d",&num);
    printf("%d meter is equal to %0.3f km\n",num,num/1000.0);
}

void CelToF(){
    int num;
    printf("Enter the number in celcius:\n");
    scanf("%d",&num);
    printf("%d degree celcius is equal to %0.3f degree farenheit\n",num,num*9/5+32.0);
}
