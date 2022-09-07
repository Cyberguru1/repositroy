#include "main.h"

int main(void){
    size_t var;
    char *buff = NULL;
    ssize_t out;
    char **token;

    
    var = 0;
    printf("$ ");
    out = get_line(&buff, &var, stdin);
    token = parse_cmd(buff); 
   /* for (int i = 0; token[i] != NULL; i++)
   {
        printf("%s\n", token[i]);
    } */
    printf("%lu", out);
    if (execve(token[0], token, NULL) == -1)
    {
        perror("Error:");
        return (0);
        
    }
    return (0);
}