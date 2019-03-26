#include<stdio.h>
#include<string.h>

int main()
{
    int i, j;
    char string[51], vogais[] = "aeiou", consoantes[] = "bcdfghjklmnpqrstvwxyz";
    fgets(string, 51, stdin);

    printf("Vogais: ");
    for(i=0; i<strlen(string); i++){
        for(j=0; j<strlen(vogais); j++){
            if(vogais[j] == string[i]){
                printf("%c", vogais[j]);
            }
        }
    }

    printf("\nConsoantes: ");
    for(i=0; i<strlen(string); i++){
        for(j=0; j<strlen(consoantes); j++){
            if(consoantes[j] == string[i]){
                printf("%c", consoantes[j]);
            }
        }
    }

    return 0;
}