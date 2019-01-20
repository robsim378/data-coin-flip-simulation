#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rb(int min, int max){
    return (rand() % (max + 1 - min)) + min;
}

int main() {
    srand(time(NULL));

    int heads;
    unsigned long long numHeads[4] = {0, 0, 0, 0};

    unsigned long long trials = 1000000000;

    for (unsigned long long i = 0; i < trials; ++i){
        heads = 0;
        for (int j = 0; j < 3; ++j){
            if (rb(0, 1)){
                ++heads;
            }
        }
        ++numHeads[heads];
    }

    printf("Number of Heads\tNumber of Times\t Probability\n");

    for (int i = 0; i < 4; ++i) {
        printf("%i\t\t%i\t\t%f%%\n", i, numHeads[i], (float)numHeads[i] / trials * 100);
    }
}