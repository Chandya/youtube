#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *entry_point(void *value) {
    printf("hello from the second thread :)\n");

    int *num = (int *) value;

    printf("the value of value is %d", *num);

    return NULL;
}

void message_for_chandya(char *msg){
    for (int i = 0; i < sizeof(msg); i++){
        printf("%c",msg[i]);
    }
}

int main(int argc, char **argv) {
    pthread_t thread;

    printf("hello from the first thread :D\n");

    int num = 123;

    pthread_create(&thread, NULL, entry_point, &num);

    pthread_join(thread, NULL);
    
    message_for_chandya("Hello from London!");

    return EXIT_SUCCESS;
}
