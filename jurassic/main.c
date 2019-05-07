#include <stdio.h>
#include <stdlib.h> 
#include <time.h>  
int main() 
{  
srand((unsigned)time(NULL));  
for(int i = 0; i < 10; i++ )  
    printf("%d", rand() % 8);  
    printf("\n");

return 0; 
}
/*
switch(randnum){
    case 0: 
    // North
    currentX = currentX - 1;
    case 1:
    // Northeast
    currentX = currentX - 1;
    currentY = currentY + 1;
    case 2:
    // East
    currentY = currentY + 1;
    case 3:
    // Southeast
    currentX = currentX + 1;
    currentY = currentY + 1;
    case 4:
    // South 
    currentX = currentX + 1;
    case 5:
    // Southwest  
    currentX = currentX + 1;
    currentY = currentY - 1;
    case 6:
    // West
    currentY = currentY - 1;
    case 7:
    // Northwest 
    currentX = currentX - 1;
    currentY = currentY - 1;
}
*/