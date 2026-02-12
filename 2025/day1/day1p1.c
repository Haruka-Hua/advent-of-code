// left: lower numbers(-)
// right: higher numbers(+)
#include<stdio.h>
#include<stdlib.h>

int main(){
    int cnt = 0;
    int dial = 50;
    FILE *fp = fopen("day1.in","r");
    char rotation[16];
    while (fscanf(fp,"%s",rotation)!=EOF){
        int sgn = rotation[0]=='L' ? -1 : 1;
        int walk = atoi(rotation+1);
        dial += sgn * walk;
        dial %= 100;
        if (dial==0) cnt++;
    }
    printf("%d",cnt);
    fclose(fp);
    return 0;
}