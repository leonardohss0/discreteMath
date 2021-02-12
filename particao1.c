#include <stdio.h>
#include <stdlib.h>

void print(int p[], int number){

    for(int i=0; i<number; i++){
        printf("%d ", p[i]);
    } printf("\n");
}


void partition(int number){

    int last = 0;
    int p[number];
    int integer, counter = 1;

    p[last]= number;

    while(1){

        print(p, last+1);
        integer = 0;

        while(last>=0 && p[last]==1){
            integer = integer + p[last];
            last--;
        }

        if(last<0){

            printf("%d\n", counter);
            return;
        }

        p[last]--;
        integer++;

        while(integer > p[last]){
            p[last+1]= p[last];
            integer = integer - p[last];
            last++;
        }

        p[last+1] = integer;
        last++;

        counter++;
        
    }

}


int main(int argc, char *argv[]){

    int number;

    printf("Tap the number you want to partition\n");
    scanf("%d", &number);
    fflush(stdin);
    printf("\n");

    partition(number);

    return 0;
}