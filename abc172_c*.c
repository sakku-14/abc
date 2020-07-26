#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10000
#define M 10000000000

void cmp(int *judge, int timeReq_a, int timeReq_b);

int main(void){
    char str[N];
    int books_a, books_b, limit, timeReq_a[N], timeReq_b[N], counter_a = 0, counter_b = 0, judge;

    //Aの本、Bの本、制限時間の入力
    fgets(str, sizeof(str), stdin);
    sscanf(str, "%d %d %d", &books_a, &books_b, &limit);

    //Aの本、上から順にかかる時間
    fgets(str, sizeof(str), stdin);
    timeReq_a[0] = atoi(strtok(str, " "));
    int i = 1;
    while(i < books_a){
        timeReq_a[i] = atoi(strtok(NULL, " "));
        // printf("%d ", timeReq_a[i]);                //checker
        i++;
    }
    i = 0;

    // printf("\n");                                   //checker

    //Bの本、上から順にかかる時間
    fgets(str, sizeof(str), stdin);
    timeReq_b[0] = atoi(strtok(str, " "));
    i = 1;
    while(i < books_b){
        timeReq_b[i] = atoi(strtok(NULL, " "));
        // printf("%d ", timeReq_b[i]);                //checker
        i++;
    }
    i = 0;

    //judge=0はAを読む。=1ならBを読む。
    while(limit > 0){
        if(timeReq_a[counter_a] == 0){
            judge = 1;
        } else if(timeReq_b[counter_b] == 0){
            judge = 0;
        } else {
            cmp(&judge, timeReq_a[counter_a], timeReq_b[counter_b]);
        }
        if(judge == 0 && counter_a < books_a){
            limit -= timeReq_a[counter_a];
            if(limit >= 0)counter_a++;
            // printf("aに+1\n");                  //checker
        } //else
        if(judge == 1 && counter_b < books_b){
            limit -= timeReq_b[counter_b];
            if(limit >= 0)counter_b++;
            // printf("bに+1\n");                  //checker
            // printf("通過したよ!\n");                //checker
        }
        // else {
        //     printf("error\n");
        //     printf("judge = %d, counter_a = %d, counter_b = %d\n", judge, counter_a, counter_b);
        //     break;
        // }

        //books_a&b共に読み終えた時の処理
        if(counter_a + counter_b == books_a + books_b)break;
    }

    int total = counter_a + counter_b;
    printf("%d\n", total);

    return 0;
}

void cmp(int *judge, int timeReq_a, int timeReq_b){
    if(timeReq_a <= timeReq_b){
        *judge = 0;
    } else {
        *judge = 1;
    }
    return;
}
