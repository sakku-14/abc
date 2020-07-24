#include <stdio.h>
int main(void){
    int fee, change;

    scanf("%d", &fee);

    while(fee > 0){
        fee -= 1000;
    }

    change = fee * (-1);
    printf("%d\n", change);

}
