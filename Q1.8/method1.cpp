//Brute force Implementation using extra arrays to store position of zero.
//Time Complexity - O(n^2) 
//Space Complexity - O(m*n) - m = no. of rows , n = no. of columns.
#include<iostream>
#include<vector>
#include<cstdlib>


//Not part of the algorithm . 
//Only used to display the original matrix.
void displayMatrix(std::vector<std::vector<int>> matrix , std::string s){

    std::cout<<s<<std::endl<<std::endl;
    for (int i = 0; i < matrix[0].size(); ++i)
    {
        for (int j = 0; j < matrix.size(); ++j)
        {
            std::cout<<matrix[i][j]<<"   ";
        }
        std::cout<<std::endl;
    }

}
void setRowZero(std::vector<std::vector<int>> &matrix, int row){
    for (int i = 0; i < matrix[0].size(); i++)
        matrix[row][i] = 0;
}
void setColumnZero(std::vector<std::vector<int>> &matrix, int column){
    for (int i = 0; i < matrix.size(); i++)
        matrix[i][column] = 0;
}

//Just a function to full the array with random numbers. 
//Not included as a the part of the algorithm.
std::vector<std::vector<int>> fillPixels(int m , int n){

    std::vector<std::vector<int>> matrix(m, std::vector<int> (n, 0));

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            matrix[i][j] = (rand() % 10);
    }
    return matrix;
}

void zero(int m , int n){

    std::vector<std::vector<int>> matrix = fillPixels(m , n);
    displayMatrix(matrix , "original matrix");

    bool row[m] = {false}; // boolean array to store the positions of zero in row.
    bool column[n] = {false}; // boolean array to store the positions of zero in column.


    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] == 0){
                row[i] = true;
                column[i] = true;
            }
        }
    }

    for (int i = 0; i < m; ++i)
        if (row[i])
            setRowZero(matrix , i);
    
    for (int j = 0; j < n; ++j)
        if (column[j])
            setColumnZero(matrix , j);

    displayMatrix(matrix , "new zero matrix");
}







int main(){

int m , n;
std::cout<<"Enter the image pixel resolution : "<<std::endl;
std::cout<<"row = ";
std::cin>>m;
std::cout<<"col = ";
std::cin>>n;

zero(m , n);

}