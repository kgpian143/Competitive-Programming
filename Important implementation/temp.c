#include <stdio.h>
#include <string.h>

int main()
{

    int N;
    scanf("%d", &N);
    getchar();
    int x, j;
    for (x = 1; x <= N; x++)
    {  
        char s[1000];
        char ptr[1000];
        scanf("%[^\n]s", s);
        int i = 0 ;

        while(s[i] == ' ')i++ ;
        
        printf("\n");
    }
    return 0;
}