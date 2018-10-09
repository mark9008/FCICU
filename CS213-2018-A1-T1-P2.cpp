// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 2
// Program: CS213-2018-A1-T1-P2
// Purpose: Processing functions and operations on matrices
// Author1:  Mark Ihab Ayad
// Author2:  Mark Samuel Shawki
// Author3:  Mario Osama Fayez
// Date:    9/10/2018
// Version: 1.0

#include <iostream>
#include <iomanip>
#include <valarray>
//#include <cassert>

using namespace std;

// A structure to store a matrix
struct matrix
{
  valarray<int> data;        // Pointer to 2-D array that will simulate matrix
  int row, col;
};

// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);

// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
					    // new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
					     // matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
       	// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
       // and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat);
       	// Print matrix  as follows (2 x 3)			4	 6 	  8
	    // and return ostream to cascade printing	9	12	  123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose  (matrix mat);    // Return new matrix with the transpose

//__________________________________________

int main()
{
  int data1 [] = {1,2,3,4,5,6,7,8};
  int data2 [] = {13,233,3,4,5,6};
  int data3 [] = {10,100,10,100,10,100,10,100};
  int data4 [] = {1,0,0,0,1,0,0,0,1};

  matrix mat1, mat2, mat3, mat4, trans, identity;
  createMatrix (4, 2, data1, mat1);
  createMatrix (2, 3, data2, mat2);
  createMatrix (4, 2, data3, mat3);
  createMatrix (3, 3, data4, identity);
  
 /* cout << "Enter your matrix in the form of ROW COL DATA(1 2 3 4 5 6)";
  cin >> mat4.row >> mat4.col >> mat4;
 
  cout << mat4 << endl;
  cout << mat1 << endl;
  cout << mat2 << endl;
  cout << mat3 << endl;

  cout << (mat1 + mat3) << endl << endl;
  cout << (mat3 + mat3) << endl << endl;
  cout << (mat1 + mat3) << endl << endl;*/
  cout << (mat1 * mat2) << endl << endl;
 // ++mat1;
 // cout << mat1 << endl;

 // mat1+= mat3 += mat3;
 // cout << mat1 << endl;
 // cout << mat2 << endl;
 // cout << mat3 << endl;
 // // Add more examples of using matrix
 // // .......
 //
 // if (isSymetric(mat4)) {
	//cout << "true" << endl;
 // } else {
	//cout << "false" << endl;
 // }
  cout << mat1 << endl;
  cout << transpose(mat1) << endl;
  return 0;
}

//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat) {
  mat.row = row;
  mat.col = col;
  mat.data.resize (row * col);
  for (int i = 0; i < row * col; i++)
    mat.data[i] = num[i];
}

// Student #1 
// Name: Mark Ihab Ayad
// ID: 20170205


// Add if same dimensions into a new matrix
matrix operator+  (matrix mat1, matrix mat2) {
	matrix mat3;
	if ((mat1.row == mat2.row) && (mat1.col == mat2.col)) {
		mat3.row = mat1.row;
		mat3.col = mat1.col;
		mat3.data.resize (mat1.row * mat1.col);
		mat3.data = mat1.data + mat2.data;
	}
	else {
		cout << "The 2 matrices are not of the same dimensions" << endl;
	}
	return mat3;
}

// Subtract if same dimensions into a new matrix
matrix operator-  (matrix mat1, matrix mat2) {
	matrix mat3;
	if ((mat1.row == mat2.row) && (mat1.col == mat2.col)) {
		mat3.row = mat1.row;
		mat3.col = mat1.col;
		mat3.data.resize (mat1.row * mat1.col);
		mat3.data = mat1.data - mat2.data;
	}
	else {
		cout << "The 2 matrices are not of the same dimensions" << endl;
	}
	return mat3;
}

// Multiply If Col1 = Row2 into a new matrix
matrix operator*  (matrix mat1, matrix mat2) {
	matrix mat3;
	if (mat1.col == mat2.row) {
		mat3.row = mat1.row;
		mat3.col = mat2.col;
		mat3.data.resize (mat1.row * mat2.col);

		for (int i = 0; i < mat3.row * mat3.col; i++)
			mat3.data[i] = 0;

		for (int i = 0; i < mat3.row; i++)
				for (int j = 0; j < mat3.col; j++)
					for (int k = 0; k < mat1.col; k++) {
						int n1,n2;						
						n1 = mat1.data[k + i * mat1.col]; 
						n2 = mat2.data[j + k * mat2.col];
						mat3.data[j + i*mat3.col] += n1 * n2;
					}
	}
	return mat3;
}

// Adds a number to all elements in matrix into a new matrix
matrix operator+  (matrix mat1, int scalar){
    for(int i = 0; i < mat1.row*mat1.col; i++)
		mat1.data[i] += scalar;
	return mat1;
}

// Subtracts a number from all elements in matrix into a new matrix
matrix operator- (matrix mat1, int scalar){
    for(int i = 0; i < mat1.row*mat1.col; i++)
		mat1.data[i] -= scalar;
	return mat1;
}

// Multiplies all elements in matrix by a number into a new matrix
matrix operator*  (matrix mat1, int scalar){
	for(int i = 0; i < mat1.row*mat1.col; i++){
			mat1.data[i]*=scalar;
	}
	return mat1;
}

// Student #2 
// Name: Mark Smauel Shawki
// ID: 20170206

// Accepts input of matrix elements
istream& operator>> (istream& in, matrix& mat) {
	 mat.data.resize (mat.row * mat.col);

	 for (int i = 0; i < mat.row * mat.col; i++)
		in >> mat.data[i];
	return in;
}

// Adds the values of matrix 2 to matrix 1 and saves in matrix 1
matrix operator+= (matrix& mat1, matrix mat2) {
	mat1.data += mat2.data;
	return mat1;
}

// Subtracts the values of matrix 2 from matrix 1 and saves in matrix 1
matrix operator-= (matrix& mat1, matrix mat2) {
	mat1.data -= mat2.data;
	return mat1;
}

// Adds the number to matrix 1 and saves in matrix 1
matrix operator+= (matrix& mat, int scalar) {
	mat.data += scalar;
	return mat;
}

// Subtracts the number from matrix 1 and saves in matrix 1
matrix operator-= (matrix& mat, int scalar) {
	mat.data -= scalar;
	return mat;
}

// Adds 1 to all elements in matrix 1
void operator++ (matrix& mat) {
	mat.data += 1;
}

// subtracts 1 to all elements in matrix 1
void operator-- (matrix& mat) {
	mat.data -= 1;
}

// Student #3 
// Name: Mario Osama Fayez
// ID: 20170209

// Print matrix  as follows (2 x 3)			4	 6 	  8
// and return ostream to cascade printing	9	12  	123
ostream& operator<< (ostream& out, matrix mat){
    int counter = 0;
    for(int i = 0; i < mat.row*mat.col; i++){
        out << mat.data[i]<<" ";
        counter++;
        if(counter==mat.col){
            cout << endl;
            counter = 0;
        }
    }

}

// Checks if both matrices are equal or not
bool   operator== (matrix mat1, matrix mat2){
        bool isEqual=true;
        if((mat1.row==mat2.row)&&(mat1.col==mat2.col)){
            for(int i=0; i<mat1.row*mat1.col; i++){
                if(mat1.data[i]!=mat2.data[i]){
                    isEqual=false;
                }
            }
            if(isEqual==true)return true;
            else{return false;}

        }
        else{return false;}
}

// Checks if both matrices are different or not
bool   operator!= (matrix mat1, matrix mat2){
        bool isNotEqual= false;
        if((mat1.row==mat2.row)&&(mat1.col==mat2.col)){
            for(int i=0; i<mat1.row*mat1.col; i++){
                if(mat1.data[i]!=mat2.data[i]){
                    isNotEqual=true;


                }

            }
            if(isNotEqual==true)return true;
            else{return false;}
        }
        else{return true;}

} 	// True if not same

// Checks if a matrix is square or not
bool   isSquare   (matrix mat){
    bool isSquare=true;
    if(mat.row!=mat.col){
        isSquare=false;
    }
    cout<<isSquare<<endl;
}  // True if square matrix

// Checks if a matrix is Symetric or not
bool   isSymetric (matrix mat){
        bool isSymetric=true;
        if(mat.row==mat.col){
          if(mat==transpose(mat)){
            isSymetric=true;
          }
          else{return false;}
        }
        else{return false;}


}

// Checks if a matrix is identity matrix or not
bool   isIdentity (matrix mat){
        if(mat.row==mat.col){
            for(int i=0; i<mat.row*mat.col; i+=(mat.row+1)){
                if(mat.data[i]!=1){
                    return false;
                }
                else if(mat.data[i]==1){
                    mat.data[i]=0;
                }

            }
            for(int i=0; i<mat.row*mat.col; i++){
                    if(mat.data[i]!=0){
                        return false;
                    }

                }
            return true;

        }
        else{
            return false;
        }


}

// Returns the transpose of a matrix into a new matrix
matrix transpose(matrix mat){
    matrix matX;

    int dataX[mat.row*mat.col];
    createMatrix(mat.col, mat.row, dataX, matX);

    for(int i=0; i<matX.row; i++){
        for(int j=0; j<matX.col; j++){
            matX.data[j+i*matX.col]=mat.data[i+j*mat.col];
        }


    }
    return matX;
    cout<<matX;


}
