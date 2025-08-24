#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmpChar(const void *a, const void *b)
 {
    return (*(char*)a - *(char*)b);
}

void makeKey(char *word, char *key)
 {
    strcpy(key, word);
    qsort(key, strlen(key), sizeof(char), cmpChar);
}

int main() 
{
    int n;
    printf("Enter number of words: ");
    scanf("%d", &n);

    char words[n][100], key1[100], key2[100];
    int used[n];
    for (int i = 0; i < n; i++) 
	{
        scanf("%s", words[i]);
        used[i] = 0;
    }

    printf("\nGrouped Anagrams:\n");
    for (int i = 0; i < n; i++) 
	{
        if (used[i]) continue;
        makeKey(words[i], key1);
        printf("[ %s", words[i]);
        used[i] = 1;

        for (int j = i + 1; j < n; j++) 
		{
            if (!used[j]) {
                makeKey(words[j], key2);
                if (strcmp(key1, key2) == 0) 
				{
                    printf(", %s", words[j]);
                    used[j] = 1;
                }
            }
        }
        printf(" ]\n");
    }
    return 0;
}
/*Output
  :Enter number of words: 6
eat
tea
tan
ate
nat
bat

Grouped Anagrams:
[ eat, tea, ate ]
[ tan, nat ]
[ bat ]*/
