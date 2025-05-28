#include <stdio.h>
#define N 10

struct student {
   char name[10];
   int score;
};

 main() {
    struct student s[N];
    int i;
    float avg;
    for (i = 0; i < N; i++) {
        printf("Enter name and score for student %d: ", i + 1);
        scanf("%s %d", s[i].name, &s[i].score);
        avg += s[i].score;
    }
        avg /= N;
        printf("Average score: %.2f\n", avg);
    
}