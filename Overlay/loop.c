#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int curr_value = 1, end_value = 2;
    
    if (argc == 1) {
        printf("end_value not specified: taking the default value 10");
        end_value = 10;
    } else {
        printf("argv[1] = %s\n", argv[1]);
        end_value = atoi(argv[1]);
    }

    while (end_value >= curr_value) {
        printf("%d\t", curr_value++);
    }
    
    printf("\n");
    
    return 0;
}
