#include<stdio.h>
#include<string.h>
#define d 256


void searchRabinKarp(char* pattern , char* text, int q)
{
    int patteL= strlen(pattern);
    int textL= strlen(text);
    int i, j;
    int p=0;
    int t=0;
    int h;
    for(i=0;i<patteL-1;i++)
    {
        h=(h*d)%q;
    }
    
    for(i=0;i<patteL;i++)
    {
        p=(d*p+pattern[i])%q;
        t = (d*t+text[i])%q;
    }
    
    for(i=0;i<textL-patteL;i++)
    {
        if(p==t)
        {
            
        
        for(j=0;j<patteL;j++)
        {
            if(text[i+j]!=pattern[j])
            {
                break;
            }
           
                if (j == patteL)
printf("Pattern found at index %d\n", i);
            }
        
        if (i <textL-patteL) {
t = (d * (t - text[i] * h) + text[i + patteL]) % q;
// We might get negative value of t, converting it to positive
if (t < 0)
t = (t + q);
}
    }
    
    }
}
int main()
{
    char text[100];
char pattern[100];
int q = 101;
printf("Input Text: ");
scanf("%s", text);
printf("Input Pattern: ");
scanf("%s", pattern);
printf("Text: %s\n", text);
printf("Pattern: %s\n", pattern);
searchRabinKarp(pattern, text, q);
}
