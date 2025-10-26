#include <stdio.h>
#include <conio.h>  /*Header file for function getche*/
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void keyshift (int key, char pretxt[],char aftertxt[]);

int main(){
    int j;
    char fintxt[MAX]={0};
    char txt[MAX]={0};
    printf("Enter the text to be locked: ");
    fgets(txt, MAX, stdin);
    txt[strcspn(txt, "\n")] = '\0'; /* Remove the newline character if present */
    printf("-----------------encryption outcomes------------------\n");
    for(j=0;j<25;j++){
      keyshift(j, txt, fintxt);
      printf("When the key is %d     the locked text is: %s\n", j, fintxt);
    }
    printf("Choose which you want :) .\n");
    return 0;
}
void keyshift(int key, char pretxt[], char aftertxt[]){
    int i=0;
    while (pretxt[i]!='\0')
    {   
        char c=pretxt[i];
        if (c>='a'&&c<='z')
        {
            aftertxt[i] = (c - 'a' + key) % 26 + 'a';
        }
        else if (c>='A'&&c<='Z')
        {
            aftertxt[i] = (c - 'A' + key) % 26 + 'A';
        }
        else
        {
            aftertxt[i]=c;
        }
        i++;
    }
    aftertxt[i] = '\0';  // 添加字符串终止符
}