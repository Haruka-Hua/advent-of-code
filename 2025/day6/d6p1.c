# include <stdio.h>
# include <stdlib.h>

int eol(FILE *fp){
    while (1){
        char c = fgetc(fp);
        if(c != ' '){
            if(c=='\n'){
                return 1;
            }
            else{
                ungetc(c,fp);
                return 0;
            }
        }
    }
}

int main(){
    FILE *fp = fopen("d6.in","r");
    char op[2046];
    int num[4][2048];
    int cols=0;
    long long ans = 0;
    for(int r=0;r<4;r++){
        while (1){
            fscanf(fp,"%d",&num[r][cols]);
            cols++;
            if(eol(fp)){
                cols = 0;
                break;
            }
        }
    }
    while (1){
        char c = fgetc(fp);
        if (c=='*' || c=='+'){
            op[cols] = c;
            cols++;
        }
        else if (c==EOF) break;
    }
    for(int c=0;c<cols;c++){
        switch (op[c]){
            case '+': ans += (long long)num[0][c] + (long long)num[1][c]
                        + (long long)num[2][c] + (long long)num[3][c];
                        break;
            case '*': ans += (long long)num[0][c] * (long long) num[1][c]
                        * (long long)num[2][c] * (long long)num[3][c];
                        break;
        }
    }
    printf("%lld",ans);
    fclose(fp);
    return 0;
}