# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int vector[8][2] = {{0,1},{0,-1},{1,0},{1,1},{1,-1},{-1,0},{-1,1},{-1,-1}};

int inbound(int r, int c, int rows, int cols){
    return r>=0 && c>=0 && r<rows && c<cols;
}

int accessible(char grid[][256], int r, int c, int rows, int cols){
    if (grid[r][c]!='@') return 0;
    int cnt = 0;
    for(int dir=0; dir<8; dir++){
        int x = r + vector[dir][0],
        y = c + vector[dir][1];
        if(inbound(x,y,rows,cols)){
            if(grid[x][y]=='@'){
                cnt++;
            }
        }
    }
    return cnt<4;
}

int main(){
    FILE *fp = fopen("d4.in","r");
    char grid[256][256];
    int rows = 0, cols = 0, cnt=0;
    while (fscanf(fp,"%s", grid[cols])!=EOF){
        cols++;
    }
    rows = strlen(grid[0]);
    for(int r=0;r<rows;r++){
        for(int c=0;c<cols;c++){
            cnt += accessible(grid,r,c,rows,cols);
        }
    }
    printf("%d",cnt);
    fclose(fp);
    return 0;
}