#include <iostream>

using namespace std;
int m, **matrix, **visited;
void print_matrix(){

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < m; ++j){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}
int is_okay(int i, int j){

    if(i >= 0 && i < m && j >= 0 && j < m && visited[i][j] == 0 && matrix[i][j] == 1){
        return 1;
    }
    return 0;

}
void dfs(int i, int j, int number_of_the_island){


    visited[i][j] = 1;
    matrix[i][j] = number_of_the_island;
    if(is_okay(i - 1, j)){
    //up
    dfs(i - 1, j, number_of_the_island);
    }
    if(is_okay(i, j - 1)){
    //left
    dfs(i, j - 1, number_of_the_island);
    }
    if(is_okay(i, j + 1)){
    //right
    dfs(i, j + 1, number_of_the_island);
    }
    if(is_okay(i + 1, j)){
    //down
    dfs(i + 1, j, number_of_the_island);
    }

}
void mark_the_islands(){


    int number_of_the_island = 1;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < m; ++j){
            if(matrix[i][j] == 1 && visited[i][j] == 0){
                ++number_of_the_island;
                dfs(i, j, number_of_the_island);
            }
        }
    }

}
int main()
{
    cout << "m = ";
    cin >> m;
    matrix = new int* [m];
    visited = new int* [m];
    for(int i = 0; i < m; ++i){
        matrix[i] = new int [m];
        visited[i] = new int [m];
        for(int j = 0; j < m; ++j){
            cin >> matrix[i][j];
            visited[i][j] = 0;
        }
    }
    mark_the_islands();
    print_matrix();
    return 0;
}
