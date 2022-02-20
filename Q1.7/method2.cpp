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

    if (m!=n){
     std::cout<<"not a square matrix \n";
     return;
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

    //For understanding the shiting lets take an example of 4 x 4 matrix.
    //the loop iterates from 0 - 2.
    for (int layer = 0; layer < n/2  ; ++layer)
    {
        int first  = layer;
        int last = n - 1 - layer; 
        for (int i = first ; i < last; ++i)
        {
            int offset = i - first;
            int top = pixels[first][i]; //store top the value from the top layer.

            //Left to Top
            pixels[first][i] = pixels[last-offset][first];
            pixels[last-offset][first] = pixels[last][last-offset];
            pixels[last][last-offset] = pixels[i][last];
            pixels[i][last] = top;
        }
    }

     //Not part of the algorithm . 
    //Only used to display rotated the matrix.
    std::cout<<std::endl<<"rotated Matrix"<<std::endl<<std::endl;
    
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout<<pixels[i][j]<<"   ";
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