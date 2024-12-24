#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

bool arr[51][51];
bool visited[51][51];

bool dfs(int x, int y);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

bool dfs(int x, int y){
    if(visited[x][y]){
        return false;
    }else{
        visited[x][y] = true;
        
    }
}