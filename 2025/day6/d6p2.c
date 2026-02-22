# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define rows 4

int read_col(char lines[][4096], int col){
    int ret = 0;
    for(int i=0;i<rows;i++){
        if(lines[i][col]>='0' && lines[i][col]<='9'){
            ret *= 10;
            ret += lines[i][col]-'0';
        }
    }
    return ret;
}

int is_aligned(char lines[][4096], int col){
    for(int i=0;i<rows;i++){
        if(lines[i][col]>='0' && lines[i][col]<='9') return 1;
    }
    return 0;
}

int main(){
    FILE *fp = fopen("d6.in","r");
    int cols=0;
    long long ans = 0;
    char lines[rows][4096],op[1024];
    for(int i=0;i<rows;i++){
        fscanf(fp,"%[^\n]",lines[i]);
        fgetc(fp);
    }
    while (1){
        char c = fgetc(fp);
        if (c=='*' || c=='+'){
            op[cols] = c;
            cols++;
        }
        else if (c==EOF) break;
    }
    int offset = 0;
    for(int i=0;i<cols;i++){
        long long sub = op[i]=='+' ? 0 : 1;
        while (is_aligned(lines,offset)){
            if(op[i]=='+'){
                sub += (long long)read_col(lines,offset);
            }
            else{
                sub *= (long long)read_col(lines,offset);
            }
            offset++;
        }
        offset++;
        ans += sub;
    }
    printf("%lld",ans);
    fclose(fp);
    return 0;
}