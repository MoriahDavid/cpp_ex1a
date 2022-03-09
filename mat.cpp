#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

namespace ariel{

    string mat(int colls, int rows, char c1, char c2){

        if(colls % 2 == 0 || rows % 2 == 0){
            throw invalid_argument("Mat size is always odd");
        }
        if(c1 < 0 || c2 < 0){
            throw invalid_argument("char must be ascii");
        }
        if(colls < 0 || rows < 0){
            throw invalid_argument("matrix rows and colloms must be positive");
        }
        
        char c;
        int min_v = min(colls, rows);
        int total_rings = min_v/2 + 1;

        char** matrix = new char*[rows];
        if(matrix == NULL){
            return NULL;
        }
        for (int i = 0; i < rows; i++){
            matrix[i] = new char[colls];
            if(matrix[i] == NULL){
                return NULL;
            }
        }

        for(int i = 0; i < total_rings; i++){
            c = c1;
            if(i % 2 != 0){
                c = c2;
            }
            for(int start = i; start < colls-i; start++){  
                matrix[i][start] = c;  // put up line values 
                matrix[rows-i-1][start] = c;  // put down line values
            }
            for(int start = i; start < rows-i; start++){
                matrix[start][i] = c;  // left collum
                matrix[start][colls-i-1] = c;  // right collum
            }
        }
        string s = "";
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < colls; j++){
                s = s + matrix[i][j];
            }
            s = s + "\n";
            delete [] matrix[i];
        }
        delete [] matrix;

        return s;
    }
}