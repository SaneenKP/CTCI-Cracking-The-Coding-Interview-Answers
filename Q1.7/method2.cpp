#include<iostream>
#include<vector>

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

void rotate(int m , int n ){

    std::vector<std::vector<int>> pixels = fillPixels(m , n);   //fill pixel array with random numbers.
    std::vector<std::vector<int>> rotatedPixels(m , std::vector<int>(n,0));

    if (m!=n) std::cout<<"not a square matrix \n";

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            
        }
        
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