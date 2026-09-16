#include<iostream>
#include<vector>
#include<array>
#include<random>
#include<chrono>
#include<algorithm>
using namespace std;
int main(){
    std::ios::sync_with_stdio(0),cin.tie(nullptr);
    mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
    vector<vector<char>>mp(10,vector<char>(10,'.'));
    const array<int,4>dx{1,-1,0,0},dy={0,0,1,-1};
    for(int i=0,x=0,y=0;;i++){
        mp[x][y]=i+'A';
        if(i==25)break;
        vector<int>v({0,1,2,3});
        bool flag=1;
        for(;!v.empty();){
            uniform_int_distribution rnd(0,int(v.size()-1));
            int pos=rnd(gen),nx=x+dx[v[pos]],ny=y+dy[v[pos]];
            if(nx>=0&&ny>=0&&nx<10&&ny<10&&mp[nx][ny]=='.'){
                flag=0,x=nx,y=ny,mp[nx][ny]='A'+i;
                break;
            }
            swap(v[pos],v[v.size()-1]),v.pop_back();
        }
        if(flag)break;
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++)cout<<mp[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}