#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    char mp[12][12];
    for(int i=1;i<=10;i++)for(int j=1;j<=10;j++)mp[i][j]='.';
    srand(time(0));
    mp[1][1]='A';
    for(int x=1,y=1,num=1;num<26;){
        if(mp[x+1][y]=='.'||mp[x-1][y]=='.'||mp[x][y+1]=='.'||mp[x][y-1]=='.'){
            int nx=x,ny=y,m=rand()%4;
            switch(m){
                case 0:nx++;break;
                case 1:nx--;break;
                case 2:ny++;break;
                case 3:ny--;break;
            }
            if(nx>=1&&nx<=10&&ny>=1&&ny<=10&&mp[nx][ny]=='.')x=nx,y=ny,mp[x][y]='A'+num,num++;
        }
        else break;
    }
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++)printf("%c",mp[i][j]);
        puts("");
    }
    return 0;
}