#include <stdio.h>
#include <string.h>
char* longestCommonPrefix(char strs[][100], int n)
{
    static char prefix[100];  
    static char empty[1] = "";  
    strcpy(prefix, strs[0]);  
    
    for (int i = 1; i < n; i++)
      {
        int j = 0;
        while (prefix[j] && strs[i][j] && prefix[j] == strs[i][j])
          {
            j++;
        }
        prefix[j] = '\0'; 
        if (prefix[0] == '\0') 
        {
            return empty;
        }
    }
    return prefix;
}
int main()
{
    char strs[3][100] = {"flower", "flow", "flight"};
    int n = 3;
    
    char *result = longestCommonPrefix(strs, n);
    if (strlen(result) == 0)
        printf("Output: \"\"\n");
    else
        printf("Output: \"%s\"\n", result);
    return 0;
}
#Output:Output: "fl"
