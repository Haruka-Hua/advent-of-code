# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void move(long long timeline[][256], int rows, int cols, int r){
    for(int c=0;c<cols;c++){
        if(timeline[r][c]!=-1){
            if(timeline[r-1][c]!=-1){
                timeline[r][c] += timeline[r-1][c];
            }
        } else{
            if (c>0 && timeline[r][c-1]!=-1){
                timeline[r][c-1] += timeline[r-1][c];
            }
            if (c<cols-1 && timeline[r][c+1]!=-1){
                timeline[r][c+1] += timeline[r-1][c];
            }
        }
    }
}

int main(){
    FILE *fp = fopen("d7.in","r");
    long long timeline[256][256];
    memset(timeline, 0, sizeof(long long)*256*256);
    int cols = 0, rows = 0;
    char buffer_reader;
    while (1){
        cols = 0;
        while(1){
            buffer_reader = fgetc(fp);
            if(buffer_reader=='S'){
                timeline[rows][cols]=1;
            } else if(buffer_reader=='^'){
                timeline[rows][cols]=-1;
            } else if(buffer_reader=='\n' || buffer_reader==EOF){
                break;
            }
            cols++;
        }
        if(buffer_reader==EOF) break;
        rows++;
    }
    for (int r=1;r<rows;r++){
        move(timeline,rows,cols,r);
    }
    long long timeline_cnt = 0;
    for(int c=0;c<cols;c++){
        if(timeline[rows-1][c]!=-1){
            timeline_cnt += timeline[rows-1][c];
        }
    }
    printf("%lld", timeline_cnt);
    fclose(fp);
    return 0;
}