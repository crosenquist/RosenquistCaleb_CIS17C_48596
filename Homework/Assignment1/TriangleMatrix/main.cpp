/* 
 * File:   main.cpp
 * Caleb Rosenquist
 * Purpose:  First Data Structure Triangular Array
 */

//System Level Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>

//User Libraries
#include "Triangular_Matrix.h"

using namespace std;

//Main
int main(int argc, char** argv) {
  //Declare
    srand(time(0));
    int rows = 10;
    //int rows = rand()%20+5;
    int* lengths = new int[rows];
    for(int i=0 ; i<rows ; i++){
        //lengths[i] = rand()%15+1;
        lengths[i] = i+1;
    }
    
  //Create a Triangular Matrix with integers and print the matrix
    TriMatrix<int> intMatrix(rows,lengths);
    cout<<"Integer Matrix:  "<<endl;
    cout<<intMatrix.printMatrix()<<endl;
    
  //Create a Triangular Matrix with float and print the matrix
    TriMatrix<float> floatMatrix(rows,lengths);
    cout<<"Float Matrix:  "<<endl;
    cout<<floatMatrix.printMatrix()<<endl;
    
    delete [] lengths;
    
    return 0;
}
