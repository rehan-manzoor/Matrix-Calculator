#include <iostream>
#include <fstream>

using namespace std;



// Function prototypes

void inputMatrix(int**& matrix, int& rows, int& cols);

void displayMatrix(int** matrix, int rows, int cols);

int** sumOfMatrices(int** matrix1, int** matrix2, int rows, int cols);

int** productOfMatrices(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2);

int** transposeMatrix(int** matrix, int rows, int cols);

int determinantOfMatrix(int** matrix, int rows, int cols);

void deleteMatrix(int**& matrix, int rows);

void saveMatrixToFile(const char* filename, int** matrix, int rows, int cols);

int** readMatrixFromFile(const char* filename, int& rows, int& cols);






//main function

int main() {

    int** matrix1 = NULL;
    int** matrix2 = NULL;

    int rows1, cols1, rows2, cols2;


    
    cout << "\n|******************************************************************************|\n";
	cout << "                   *  Welcome to Matrix Manipulator *							  ";
	cout << "\n|******************************************************************************|\n\n\n";




    // Input matrices 
    cout << "Matrix 1:\n";
    inputMatrix(matrix1, rows1, cols1);

     
    cout<<endl; 

    cout << "\nMatrix 2:\n";
    inputMatrix(matrix2, rows2, cols2);



    cout<<endl;
    

    // Display matrices
    cout << "\nYour Matrix 1 is:\n";
    displayMatrix(matrix1, rows1, cols1);

    cout << "\nYour Matrix 2 is:\n";
    displayMatrix(matrix2, rows2, cols2);


    cout<<endl;
    cout<<endl;


    // Save matrices to files
    saveMatrixToFile("matrix1.txt", matrix1, rows1, cols1);
    saveMatrixToFile("matrix2.txt", matrix2, rows2, cols2);

   
    cout<<endl;
    
    
    // Read matrices from files
    int** matrix1FromFile = readMatrixFromFile("matrix1.txt", rows1, cols1);
    int** matrix2FromFile = readMatrixFromFile("matrix2.txt", rows2, cols2);

   
   cout<<endl;
   cout<<endl;
   
   
   
    // Display matrices read from files
    cout << "\nMatrix 1 read from file (matrix1.txt):\n";
    displayMatrix(matrix1FromFile, rows1, cols1);

    cout << "\nMatrix 2 read from file (matrix2.txt):\n";
    displayMatrix(matrix2FromFile, rows2, cols2);

    
    cout<<endl;
    cout<<endl;

   
   
   // Perform matrix operations...
  
    int choice;
  
    do {
    char operation;
	cout << "Choose the operation: " << endl;
    cout << "1. Sum of Matrices" << endl;
    cout << "2. Product of Matrices" << endl;
    cout << "3. Transpose of Matrix 1" << endl;
    cout << "4. Transpose of Matrix 2" << endl;
    cout << "5. Determinant of Matrix 1" << endl;
    cout << "6. Determinant of Matrix 2" << endl;
    cout << "7. Exit" << endl;


    cout << endl;


    cout << "Enter the operation number (1-7): ";
    cin >> operation;


    cout << endl;


    switch (operation) {
    case '1': {
            	
    // Calculate and display the sum of matrices
    if (rows1 == rows2 && cols1 == cols2) {
			
    int** sumMatrix = sumOfMatrices(matrix1, matrix2, rows1, cols1);        

	if (sumMatrix != NULL) {
    cout << "Sum of Matrices:" << endl;
    displayMatrix(sumMatrix, rows1, cols1);
    deleteMatrix(sumMatrix, rows1);
    }
    }
            
	else{
    cout<<"Addition is not possible, Because No of Rows is not equal to No of Columns."<<endl;
    } 
			           
	break;
    }

    cout << endl;



    case '2':{
            
	// Calculate and display the product of matrices
    int** productMatrix = productOfMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2);
    if(productMatrix != NULL) {
    cout << "Product of Matrices:" << endl;
    displayMatrix(productMatrix, rows1, cols2);
    deleteMatrix(productMatrix, rows1);
    }

    break;
    }
			            
	cout << endl;



    case '3': {
            
	// Calculate and display the transpose of Matrix 1
    int** transposeMatrix1 = transposeMatrix(matrix1, rows1, cols1);
	cout << "Transpose of Matrix 1:" << endl;
    displayMatrix(transposeMatrix1, cols1, rows1);
    deleteMatrix(transposeMatrix1, cols1);

    break;
    }
            
	cout << endl;

            
			
	case '4': {
            
	// Calculate and display the transpose of Matrix 2
    int** transposeMatrix2 = transposeMatrix(matrix2, rows2, cols2);
    cout << "Transpose of Matrix 2:" << endl;
    displayMatrix(transposeMatrix2, cols2, rows2);
    deleteMatrix(transposeMatrix2, cols2);
            
	break;
    }
    
	cout << endl;



    case '5': {
            
	// Calculate and display the determinant of Matrix 1
    int detMatrix1 = determinantOfMatrix(matrix1, rows1, cols1);
            
	if(detMatrix1!=0){
    cout << "Determinant of Matrix 1: " << detMatrix1 << endl;
    }
    
    else{
    cout << "Determinant is not possible." << endl;	
	}
    
    break;
    }
            
	cout << endl;

            
			
	case '6': {
            
	// Calculate and display the determinant of Matrix 2
    int detMatrix2 = determinantOfMatrix(matrix2, rows2, cols2);

    if(detMatrix2!=0){
    cout << "Determinant of Matrix 2: " << detMatrix2 << endl;
    }
    else{
    cout << "Determinant is not possible." << endl;	
	}

    break;
    }
            
    cout << endl;



    case '7':
    cout << "Exiting the program." << endl;
    break;
    
    default: 
    cout<<"Invalid Operation." << endl;
    }
     
     
    cout<<endl;
    cout<<endl;
	cout<<endl; 
        
        
	if ( operation != '7' ){
    cout << "Do You Want To Perform Another Operation? (1 For Yes) .";
    cin>>choice;    
    cout<<endl;
	}
    
	else{            
    choice = 0;
    }

    if(choice!=1){	
    cout<<"Good Bye!";	
	}

    cout << endl;


    } while(choice == 1 );




    cout << endl;



    // Clean up memory
    deleteMatrix(matrix1, rows1);
    deleteMatrix(matrix2, rows2);
    deleteMatrix(matrix1FromFile, rows1);
    deleteMatrix(matrix2FromFile, rows2);



    return 0;
}





// Function to input matrix from the user
void inputMatrix(int**& matrix, int& rows, int& cols) {
	
	cout<<"Enter the number of rows: ";
    cin>>rows;
    cout<<"Enter the number of columns: ";
    cin>>cols;

cout<<endl;

    matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
    matrix[i] = new int[cols];
    cout << "Enter elements for row " << i + 1 << ": \n";
    for (int j = 0; j < cols; ++j) {
    cin >> matrix[i][j];
    }
    }
}




// Function to display matrix
void displayMatrix(int** matrix, int rows, int cols) {

    for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
    cout << matrix[i][j] << " ";
    }
        
    cout << endl;
    }
}




// Function to calculate the sum of two matrices
int** sumOfMatrices(int** matrix1, int** matrix2, int rows, int cols) {

    if (rows != rows || cols != cols) {
    cout << "Addition is Not possible, Because No of Rows is not equal to No of Columns." << endl;
    return NULL;  
    }

    
    int** result = new int*[rows];
    for (int i = 0; i < rows; ++i) {
    result[i] = new int[cols];
     
     
    for (int j = 0; j < cols; ++j) {
    result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
    }
    
	return result;
}





// Function to calculate the product of two matrices
int** productOfMatrices(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2) {
    
	if(cols1!=rows2) {
    cout << "Multiplication is Not Possible for these Matrices." << endl;
    return NULL;
    }

    int** result = new int*[rows1];
    for (int i = 0; i < rows1; ++i) {
    result[i] = new int[cols2];
    for (int j = 0; j < cols2; ++j) {
    result[i][j] = 0;
    for (int k = 0; k < cols1; ++k) {
    result[i][j] += matrix1[i][k] * matrix2[k][j];
    }
    }
    }
    
	return result;
}




// Function to transpose a matrix
int** transposeMatrix(int** matrix, int rows, int cols) {
    
	int** result = new int*[cols];
    for (int i = 0; i < cols; ++i) {
    result[i] = new int[rows];
    for (int j = 0; j < rows; ++j) {
    result[i][j] = matrix[j][i];
    }
    }
    
	return result;
}




// Function to calculate the determinant of a square matrix
int determinantOfMatrix(int** matrix, int rows, int cols) {
	
	if (rows != cols) {	
    cout << "Determinant is not possible." << endl;      
    return 0;
	}
    
    if (rows == 1) {
    return matrix[0][0];
    }
	 
	else if (rows == 2) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
	 
	else {
    int det = 0;
    for (int i = 0; i < rows; ++i) {
    int** submatrix = new int*[rows - 1];
    for (int j = 0; j < rows - 1; ++j) {
    submatrix[j] = new int[cols - 1];
    }
    for (int j = 1; j < rows; ++j) {
    for (int k = 0, l = 0; k < cols; ++k) {
    if (k != i) {
    submatrix[j - 1][l++] = matrix[j][k];
    }
    }
    }
    int sign = (i % 2 == 0) ? 1 : -1;
    det += sign * matrix[0][i] * determinantOfMatrix(submatrix, rows - 1, cols - 1);
    for (int j = 0; j < rows - 1; ++j) {
    delete[] submatrix[j];
    }
    
	delete[] submatrix;
    }
    
    return det;
    }
}




// Function to delete a matrix and free memory
void deleteMatrix(int**& matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
    delete[] matrix[i];
    }

    delete[] matrix;
    matrix = NULL;
}




// Function to save matrix to a file
void saveMatrixToFile(const char* filename, int** matrix, int rows, int cols) {
    
	ofstream outFile(filename);

    if (outFile.is_open()) {
    outFile << rows << " " << cols << endl;

    for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
    outFile << matrix[i][j] << " ";
    }
    outFile << endl;
    }
    
	outFile.close();
	
	if(filename=="matrix1.txt"){	  
	cout<<"Matrix 1 saved to file: " << filename << endl;
    }
    
	else{
    cout<<"Matrix 2 saved to file: " << filename << endl;	
	}
	
    }
	else{
    cout<<"Unable to open file: " << filename << endl;
    }
}





// Function to read matrix from a file
int** readMatrixFromFile(const char* filename, int& rows, int& cols) {
    
	ifstream inFile(filename);
	
    if (inFile.is_open()) {
    inFile >> rows >> cols;

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
    matrix[i] = new int[cols];
    for (int j = 0; j < cols; ++j) {
    inFile >> matrix[i][j];
    }
    }
    inFile.close();
    
	if(filename=="matrix1.txt"){
	cout<<"Matrix 1 read from file: " << filename << endl;
    }
    
	else{
    cout<<"Matrix 2 read from file: " << filename << endl;	
	}
	
	return matrix;    
	}
	
	else{
    cout<< "Unable to open file: " << filename << endl;
	return NULL;
    }
}

