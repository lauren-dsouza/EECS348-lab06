#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::string;

using Matrix = std::vector<std::vector<int>>;

//print the sum of 2 matrices
void print_matrix_sum(Matrix a, Matrix b) { //pass in 2 matrices
    cout << "Matrix Sum (A + B): " << endl; 
    for (int row = 0; row < a.size(); row++){ //iterate through rows
        for (int col = 0; col < a.size(); col++) //iterate through columns
        {
            cout<< a[row][col] + b[row][col] << " ";  //print the sum of the 2 matrices
        }
        cout << endl;
    }
}

//print the difference of 2 matrices
void print_matrix_diff(Matrix a, Matrix b) { 
    cout << "Matrix Difference (A - B): " << endl;
    for (int row = 0; row < a.size(); row++){  //iterate through rows
        for (int col = 0; col < a.size(); col++) //iterate through columns
        {
            cout << a[row][col] - b[row][col] << " ";  //print the difference of the 2 matrices
        }
        cout << endl;
    }
}

//print the product of 2 matrices
void print_matrix_product(Matrix a, Matrix b) { 
    Matrix result(a.size(), std::vector<int>(a.size())); //create a matrix to store the product
    cout << "Matrix Product (A * B): " << endl;

    for (int row = 0; row < a.size(); row++){ //iterate through rows
        for (int col = 0; col < a.size(); col++) //iterate through columns
        {
            for (int k = 0; k < a.size(); k++) //3rd variable to iterate through the rows and columns of the matrices to be multiplied
            {
                result[row][col] += (a[row][k] * b[k][col]); //multiply the elements of the matrices and store the result in the result matrix
            }
            cout << result[row][col] << " "; //print the result at a specific index
        }
        cout << endl; 
    }
}

//print the matrices and their sum, difference, and product
void print_info() {

    cout << "Enter the name of the file: " << endl; //ask user for file name
    string filename; //create a string to store the file name
    cin >> filename; //store the file name in the string

    ifstream input_file(filename); //open the file
    int matrix_size; //create a variable to store the size of the matrix

    if (input_file.is_open()) { 
        input_file >> matrix_size; //store the size of the matrix in the variable
        Matrix matrix1(matrix_size, std::vector<int>(matrix_size)); //create a matrix with the size stored previously
        cout << "Matrix A: " << endl;
        for (int i = 0; i < matrix_size; i++) { //iterate through rows
            for (int j = 0; j < matrix_size; j++) { //iterate through columns
                input_file >> matrix1[i][j]; //store the elements of the matrix in the matrix
                cout << matrix1[i][j] << " "; //print the elements of the matrix
            }
            cout << endl;
        }

        Matrix matrix2(matrix_size, std::vector<int>(matrix_size)); //create a matrix with the size stored previously
        cout << "Matrix B: " << endl; 
        for (int i = 0; i < matrix_size; i++) { //iterate through rows
            for (int j = 0; j < matrix_size; j++) { //iterate through columns
                input_file >> matrix2[i][j]; //store the elements of the matrix in the matrix
                cout << matrix2[i][j] << " "; //print the elements of the matrix
            }
            cout << endl;
        }

        print_matrix_sum(matrix1, matrix2); //print the sum of the 2 matrices
        print_matrix_product(matrix1, matrix2); //print the product of the 2 matrices
        print_matrix_diff(matrix1, matrix2); //print the difference of the 2 matrices
    } else {
        cout << "Error! The file " << filename << " cannot be opened." << endl; //print error message if file cannot be opened
        exit(1);
    }

}

//main function
int main(){
    print_info();
    return 0;
}

