/* 
 * File:   Triangular_Matrix.h
 * Caleb Rosenquist
 */

#ifndef TRIANGULAR_MATRIX_H
#define	TRIANGULAR_MATRIX_H

#include <string>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <iomanip>

template <class T, class R, class C> class TriMatrix{
    private:
      //Triangular Matrix
        T** triMatrix;
      //Number of rows
        R* rows;
      //Array storing the length of each row
        C* cols;
    public:
      //Constructor
        TriMatrix();
        TriMatrix(int, int*);
      //Destructor
        ~TriMatrix();
      //Create a random element
        T randomElement();
      //Create a 1d array
        T* array1d(int);
      //return a stringstream with the matrix
        std::string printMatrix();
};

//Constructor for the Triangular Matrix
template<class T>
TriMatrix<T>::TriMatrix(int row, int* columns){
  //Initialize
    R* rows = row;
    C* cols = columns;
  //Create matrix
    T** matrix = new T*[rows];
  //Create each array
    for(int row=0 ; row<rows ; row++){
        matrix[row] = new T[cols[row]];
    }
  //Fill the arrays
    for(int row=0 ; row<rows ; row++){
      //Set the array to array 1D
        matrix[row] = array1d(cols[row]);
    }
  //Set the temp matrix to the class matrix
    triMatrix = matrix;
}
/**
 * \brief Deconstructor for the matrix
 */
template<class T>
TriMatrix<T>::~TriMatrix(){
    //Destroy columns first
    for(int row=0;row<rows;row++){
        delete []triMatrix[row];
    }
    delete[]triMatrix;
}
/**
 * @param size the size of the array
 * @return an array of template T
 */
template<class T>
T* TriMatrix<T>::array1d(int size){
  //Generate temp array
    T* array = new T[size];
  //Fill the array
    for(int row=0 ; row<size ; row++){
        array[row] = randomElement();
    }
  //Return the array
    return array;
}
/**
 * @return random T between 0 and 100
 */ 
template<class T>
T TriMatrix<T>::randomElement(){
    T random = static_cast<T>((rand()/(RAND_MAX/90.0f)) + 10.0f);
    return random;
}
/**
 * @return stringstream representing the matrix
 */
template<class T>
std::string TriMatrix<T>::printMatrix(){
    std::stringstream print;
    for(int row=0 ; row<rows ; row++){
        for(int col=0; col<cols[row]; col++){
            print<<std::fixed<<std::setprecision(2)<<triMatrix[row][col]<<"  ";
        }
        print<<std::endl;
    }
    return print.str();
}

#endif	/* TRIANGULAR_MATRIX_H */