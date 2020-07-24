#include <stdio.h>

#define SWAP(a,b) (a += b,b = a - b,a -= b)
int main(void){
    int num, container[2*100000] = {0}, total = 0;
    scanf("%d", &num);

    int i = 0;
    while(i < num){
        scanf("%d", &container[i]);
        // printf("%d\n", container[i]);           //checker
        i++;
    }
    i = 0;

    //配列昇順並び替え
    int swapped = 1;
    while(swapped == 1){
        swapped = 0;
        while(i < num - 1){
            if(container[i] < container[i + 1]){
                SWAP(container[i], container[i+1]);
                swapped = 1;
            }
            i++;
        }
        i = 0;
    }

    // while(i < num){                             //checker
    //     printf("%d\n", container[i]);           //checker
    //     i++;                                    //checker
    // }                                           //checker
    // i = 0;                                      //checker
    int counter = num -2;
    total = container[0];
    // printf("初期値:%d\n", total);               //checker
    i = 1;
    if(num % 2 == 0){
        while(i < num){
            total += container[i];
            counter--;
            if(counter <= 0)break;
            if(counter > 0){
                total += container[i];
                counter--;
                if(counter <= 0)break;
            }
            // printf("%d\n", total);                  //checker
            i += 1;
        }
    } else {
        while(i < num){
            total += container[i];
            counter--;
            if(counter <= 0)break;
            if(counter > 0){
                total += container[i];
                counter--;
                if(counter <= 0)break;
            }
            // printf("%d\n", total);                  //checker
            i += 1;
        }
    }

    printf("%d\n", total);
    return 0;

}
