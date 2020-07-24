#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
    int num, counter_ac = 0, counter_wa = 0, counter_tle = 0, counter_re = 0;
    char result[10];

    scanf("%d", &num);

    int i = 0;
    while(i < num){
        scanf("%s", result);
        if(strcmp(result, "AC") == 0){
            counter_ac++;
        } else if(strcmp(result, "WA") == 0){
            counter_wa++;
        } else if(strcmp(result, "TLE") == 0){
            counter_tle++;
        } else{
            counter_re++;
        }
        i++;
    }
    i = 0;

    printf("AC x %d\n", counter_ac);
    printf("WA x %d\n", counter_wa);
    printf("TLE x %d\n", counter_tle);
    printf("RE x %d\n", counter_re);
}
