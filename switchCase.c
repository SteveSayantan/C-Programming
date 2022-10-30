#include <stdio.h>

int main()
{
   int a=4,marks=56;
   float b=34.456;
   
  switch(a){ //switch expression must be an int or char

      case 1: printf("The value of a is 1"); //case value must be an integer or a character
      break;
      case 2: printf("The value of a is 2");
      break;
      case 3: printf("The value of a is 3");
        switch(marks){
            case 100: printf("\nYou are a nerd");
            break;
            case 60: printf("\nYou are a donkey");
            break;
        }
      break;
      default: printf("The value of a is 4");
      
  }

    return 0;
}