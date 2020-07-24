#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 2*1000000
int main(void){
    char str[N];
    char before[N], after[N];
    fgets(str, sizeof(str), stdin);
    sscanf(str, "%s", before);
    fgets(str, sizeof(str), stdin);
    sscanf(str, "%s", after);

    int i = 0, counter = 0;
    while(before[i] != '\0'){
        if(strncmp(&before[i], &after[i], 1) != 0){
            counter++;
        }
        i++;
    }
    i = 0;

    printf("%d\n", counter);
    return 0;
}
