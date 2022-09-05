#include "main.h"

int main(void){
    size_t var;
    char *buff = NULL;
    char **token;

    
    var = 0;
    printf("$ ");
    out = get_line(&buff, &var, stdin);
    token = parse_cmd(buff); // sotring the output into an array

   /* for (int i = 0; token[i] != NULL; i++) //looping and printing each element
    {
        printf("%s\n", token[i]);
    } */

    if (execve(token[0], token, NULL) == -1)
    {
        perror("Error:");
        return (NULL);
        
    }
    return (0);
}