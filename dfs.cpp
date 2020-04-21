#include <bits/stdc++.h>
using namespace std;


void DFS(vector<vector<char>>& grid,vector<vector<bool>>& visited,int row,int col){
    visited[row][col] = true;

    //Lambda function to check the important conditions for being an Island
    auto check = [&](int row,int col){
        return (0 <= row) && (row < grid.size()) && (0 <= col) && (col < grid[0].size()) && (grid[row][col] =='1') &&(!visited[row][col]);
    };

    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}}; // All possible directions to move from a particular location first-->row , second-->col

    for(pair<int,int> dir : directions){
        int new_row = row + dir.first;
        int new_col = col + dir.second;
        if(check(new_row,new_col))
            DFS(grid,visited,new_row,new_col);
    } 
}

int islandCount(vector<vector<char>>& grid){
    int count = 0; // Keeps a count of the Islands in the map

    if(grid.empty() || grid[0].empty()) // No map provided
        return 0;

    vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size())); // Keeps Track of the islands that are already visited

    for(int row = 0 ; row < grid.size() ; row++){
        for(int col = 0; col < grid[0].size() ; col++){
            if(grid[row][col] == '1' && !visited[row][col]){
                count++ ; //It is a unique Island
                DFS(grid,visited,row,col); // Main function to calculate the connected components of the island
            }
        }
    }

    return count;
}

int main(){

    int row,col;

    cout<<"Enter the number of rows and cols"<<endl;
    cin>>row>>col;
    
    vector<vector<char>> grid(row,vector<char>(col));
    
    cout<<"Enter the island structure"<<endl;
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            cin>>grid[i][j];


    cout<<"Number of Islands in the location is :: "<<islandCount(grid)<<endl;
    
    return 0;
}