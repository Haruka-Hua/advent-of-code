# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int move(char manifold[][256], int rows, int cols, int r){
    int split_cnt = 0;
    for(int c=0;c<cols;c++){
        if(manifold[r][c]=='.'){
            if (manifold[r-1][c]=='|' || manifold[r-1][c]=='S'){
                manifold[r][c]='|';
            } 
        }
        else if (manifold[r][c]=='^'){
            if (manifold[r-1][c]=='|' || manifold[r-1][c]=='S'){
                if (c>0 && manifold[r][c-1]!='^') manifold[r][c-1] = '|';
                if (c<cols-1 && manifold[r][c+1]!='^') manifold[r][c+1] = '|';
                split_cnt++;
            }
        }
    }
    return split_cnt;
}

int main(){
    FILE *fp = fopen("d7.in","r");
    char manifold[256][256];
    int rows = 0;
    while(fscanf(fp,"%s",manifold[rows])!=EOF){
        rows++;
    }
    int cols = strlen(manifold[0]);
    int split_cnt = 0;
    for(int r=1;r<rows;r++){
        split_cnt += move(manifold,rows,cols,r);
    }
    printf("%d",split_cnt);
    fclose(fp);
    return 0;
}