//Brute Force implementation using vectors.
//Time Complexity - O(n^2) 
//Space Complexity - 
#include<iostream>
#include<vector>
#include<cstdlib>

//Just a function to full the array with random numbers. 
//Not included as a the part of the algorithm.
std::vector<std::vector<int>> fillPixels(int m , int n){

    std::vector<std::vector<int>> pixels(m, std::vector<int> (n, 0));

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            pixels[i][j] = (rand() % 10);
    }
    return pixels;
}


void rotate(int m , int n){

    std::vector<std::vector<int>> pixels = fillPixels(m , n);   //fill pixel array with random numbers.
    std::vector<std::vector<int>> rotatedPixels(m, std::vector<int> (n, 0));

    int p = 0;
    for (int i = 0; i < m; ++i)
    {
        p = m-1;
        for (int j = 0; j < n; ++j)
        {
            rotatedPixels[i][j] = pixels[p][i];
            p--;
        }
        
    }

    //Not part of the algorithm . 
    //Only used to display the original matrix.
    std::cout<<"Original Matrix"<<std::endl<<std::endl;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout<<pixels[i][j]<<"   ";
        }
        std::cout<<std::endl;
        
    }
    //Not part of the algorithm . 
    //Only used to display rotated the matrix.
    std::cout<<std::endl<<"rotated Matrix"<<std::endl<<std::endl;
    
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout<<rotatedPixels[i][j]<<"   ";
        }
        std::cout<<std::endl;
        
    }

    
}

int main(){

int m , n;
std::cout<<"Enter the image pixel resolution : "<<std::endl;
std::cout<<"row = ";
std::cin>>m;
std::cout<<"col = ";
std::cin>>n;

rotate(m , n);
}