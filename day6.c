#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "the sky is blue";
    char *words[100];  
    int count = 0;

    char *token = strtok(s, " ");
    while (token != NULL)
	{
        words[count++] = token;
        token = strtok(NULL, " ");
    }

    for (int i = count - 1; i >= 0; i--)
	{
        printf("%s", words[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");

    return 0;
}
#Output:blue is sky the
