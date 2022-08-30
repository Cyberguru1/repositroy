#include "main.h"

void main(void){
    size_t var;
    char *buff = NULL;
    ssize_t out;
    char *token;
    char s[2] = " ";

    
    var = 0;
    printf("$ ");
    out = get_line(&buff, &var, stdin);
     token = _strtok(buff, s);
    while (token != NULL){
        printf("%s\n", token);
        token = _strtok(NULL, s);
    }

    printf("%s\n",buff);
    printf("%zu",out);
}