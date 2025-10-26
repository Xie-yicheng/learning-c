#include <stdio.h>
#include <conio.h>  /*Header file for function getche*/
#include <stdlib.h>
#include <string.h>
#include <math.h>

    /*
int main0(){
    char c1,c2;
    printf("put two chars in format of'x y':");
    scanf("%c %c",&c1,&c2);
    printf("%c   %c\n",c1,c2);
    printf("%d   %d\n",c1,c2);
}
    the learning of what char is.
    */


#if 0 /*The following code is version 1*/

#define MAX 1000 /* Maximum length */


void keyshift(char solvedtext[],int key,char lockedtext[]);/* function that shifts the text by key */


int main1(){
    char text[MAX];
    printf("Enter the locked text:\n");
    fgets(text,MAX,stdin);

}

void keyshift(char solvedtext[],int key,char lockedtext[]){
    int i=0;/*set beginning one*/
    while(lockedtext[i]!='\0'/*'\0' is the null space of solvedtext,and '' is whe way to get a char*/)/*add i+1 when i not approach the last letter*/
    {
        /*lockedtext[i]=solvedtext[i]+key;
        i++;
        I think it's not the correct code*/
        char c=lockedtext[i];
        if(c>='a'&&c<='z')/*letter check*/{
            solvedtext[i]=(c-key+26)%26+'a';/*not let char out of a-z*/
        }
        else if (c>='A'&&c<='Z')/*letter check*/{
            solvedtext[i]=(c-key+26)%26+'A';/*not let char out of A-Z*/
        }
        else{ 
            solvedtext[i]=c;/*letter remains the same*/
        }
        i++;
    }
    solvedtext[i]='\0';/*put the null char after the last letter in[],because we need to mark the end.Otherwise the output will be incorrect.*/
}

/*Now we gonna think about how to write the score function*/
int score(char solvedtext[]){
    int score=0;
    int j;
    int k;
    char commonletters[]="etaoins";/*common letters*/
    for (j=0,k=0; solvedtext[j]!="\0"; j++)/*run and calculate the score*/
    {
        if (strchr(commonletters, solvedtext[j]) != NULL && k<8)
        {
            commonletters[k++]=solvedtext[j];
            score=score+(4-k*0.5);
        }
        if (j==' ')
        {
            score=score+2;
        }
    }
   
    return score;
}

void choosebest(char unlockedtext[]){/*← AI helped me to text these codes,I haven't thought about this way to use if before.That's so fantastic.*/
    char solvedtext[MAX];
    int bestscore=0;
    int bestkey=0;

    printf("Trying keys from 1 to 25:\n");
    for(int key=1;key<=25;key++){
        keyshift(solvedtext,key,unlockedtext);
        int currentscore=score(solvedtext);

        printf("Key: %2d     score: %3d  solvedtext: %s\n",key,currentscore,solvedtext)
        ;
        if (currentscore>bestscore)/*Another way to use 'if',like Max={a,b} in Math.*/
        {
            bestscore=currentscore;
            bestkey=key;
        }
    }

    printf("Best key: %d\n", bestkey);
    printf("Best score: %d\n", bestscore);
    printf("solved text: %s\n", solvedtext);

}

#endif /*I learnt this.#if 0 → #endif :)*/


/*The following code is version 2*/
#define MAX 1000 /* Maximum length */


void keyshift(char solvedtext[],int key,char lockedtext[]);/* function that shifts the text by key */
int score(char solvedtext[]);
void choosebest(char unlockedtext[]);/* declare the function before main()*/

int main(){
    char text[MAX]={0};
    printf("Enter the locked text:\n");
    fgets(text,MAX,stdin);
    text[strcspn(text, "\n")] = '\0'; /* Remove the newline character if present */
    choosebest(text);
    return 0;
}

void keyshift(char solvedtext[], int key, char lockedtext[]){
    int i=0;
    while(lockedtext[i]!='\0')
    {
        char c=lockedtext[i];
        if(c>='a'&&c<='z'){
            solvedtext[i] = (c - 'a' - key + 26) % 26 + 'a';
        }
        else if (c>='A'&&c<='Z'){
            solvedtext[i] = (c - 'A' - key + 26) % 26 + 'A';
        }
        else{ 
            solvedtext[i]=c;
        }
        i++;
    }
    solvedtext[i]='\0';
}

/*Now we gonna think about how to write the score function*/
int score(char solvedtext[]){
    int s=0;
    char commonletters[] = "etaoinsETAOINS";
    
    for(int j=0; solvedtext[j]!='\0'; j++)
    {
        for(int k=0; commonletters[k]!='\0'; k++)
        {
            if(solvedtext[j] == commonletters[k])
            {
                int position = k % 7; 
                s += (int)(4 - position * 0.5);
                break;
            }
        }
        
        if(solvedtext[j] == ' ')
        {
            s += 2;
        }
    }
    return s;
}

#if 0
void choosebest(char unlockedtext[]){/*← AI helped me to text these codes,I haven't thought about this way to use if before.That's so fantastic.*/
    char solvedtext[MAX];
    char bestsolvedtext[MAX];
    int bestscore=0;
    int bestkey=0;

    printf("Trying keys from 1 to 25:\n");
    for(int key=1;key<=25;key++){
        keyshift(solvedtext,key,unlockedtext);
        int currentscore=score(solvedtext);

        printf("Key: %2d     score: %3d  solvedtext: %s\n",key,currentscore,solvedtext)
        ;
        if (currentscore>bestscore)/*Another way to use 'if',like Max={a,b} in Math.*/
        {
            bestscore=currentscore;
            bestkey=key;
            strcpy(bestsolvedtext, solvedtext);/* Copy the best solved text to bestsolvedtext */
        }
    }
#endif/*The code above is not the perfect one compare to what AI did below,though it could run well.However,that is too hard for me to understand now.So I'll just copy it.*/
void choosebest(char unlockedtext[]){
    char solvedtext[MAX];
    // 创建一个结构来保存前四名结果
    typedef struct {
        int key;
        int score;
        char text[MAX];
    } Result;
    
    Result topResults[4] = {0}; // 初始化前四名结果
    
    printf("Trying keys from 1 to 25:\n");
    for(int key=1;key<=25;key++){
        keyshift(solvedtext,key,unlockedtext);
        int currentscore=score(solvedtext);

        printf("Key: %2d     score: %3d  solvedtext: %s\n",key,currentscore,solvedtext);
        
        // 检查是否能进入前四名
        for(int rank=0; rank<4; rank++){
            if(currentscore > topResults[rank].score){
                // 将当前结果插入到前四名中的适当位置
                for(int shift=3; shift>rank; shift--){
                    topResults[shift] = topResults[shift-1];
                }
                // 插入新结果
                topResults[rank].key = key;
                topResults[rank].score = currentscore;
                strcpy(topResults[rank].text, solvedtext);
                break;
            }
        }
    }

    // 输出前四名结果
    printf("\n=== TOP 4 RESULTS ===\n");
    for(int i=0; i<4; i++){
        printf("Rank %d: Key %2d, Score %3d: %s\n", 
               i+1, topResults[i].key, topResults[i].score, topResults[i].text);
    }
    
    // 仍然输出最佳结果
    printf("\nBest key: %d\n", topResults[0].key);
    printf("Best score: %d\n", topResults[0].score);
    printf("Best solved text: %s\n", topResults[0].text);
}

