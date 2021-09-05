#include<iostream>
#include<cmath>
#include<climits>
#include<vector>
#include<algorithm>
#include<time.h>
#include<fstream>
using namespace std;

//holds the matrix element by coordinates wise.
struct matrixElement{
	int row;
	int col;
	int value;
};

//Functions declarations
bool checkElement(vector<matrixElement>, int, int);
int sparseMatrixAddition(vector <matrixElement>, vector<matrixElement>);
void noramlMatrixAddition(int, int, int);



int main(){

	int m,n,p, size = 9;
	float sp;

	cout << "Enter the matrices dimensions m,n and p: ";
	cin >> m >> n >> p;

	ofstream file_writer("runtime.txt");
	file_writer << "Run time for martix of dimensions " << m << "*" << n << endl;
	file_writer << "(sparsity -> runtime)" << endl;

	for(int i=0; i<size; i++){

		cout << "Enter the matrix sparsity value [0-1]: ";
		cin >> sp;


		//calculating how many non zero element is required in matrix A
		//calulated as per question
		int total_non_zero_value;
		total_non_zero_value = round((m*n) * sp);


		// Triplet Representation(row, col and value)
		//For matrix A
		vector <matrixElement> matrixA;

		//For matrix B
		vector<matrixElement> matrixB;

	

		int countA = 0;

		matrixElement meA;
		//Generating random row and column for matrix A

		srand(time(0));

		for(;;){
			if(countA == total_non_zero_value){
				break;
			}

			meA.row = rand()%m;
			meA.col = rand()%n;
			meA.value = rand()%100;

			if(matrixA.size() == 0){
				matrixA.push_back(meA);
				countA += 1;
			}else{

				if(checkElement(matrixA, meA.row, meA.col) == false){
					matrixA.push_back(meA);
					countA += 1;
				}
			}
		}

		//sort the matrix by row wise
		sort(matrixA.begin(), matrixA.end(), [](matrixElement a, matrixElement b){
			return a.row < b.row;
		});



		//Generating random row and column for matrix B

		int countB = 0;
		matrixElement meB;

		for(;;){
			if(countB = total_non_zero_value){
				break;
			}

			meB.row = rand()%n;
			meB.col = rand()%p;
			meB.value = rand()%100;

			if(matrixB.size() == 0){
				matrixB.push_back(meB);
				countB += 1;
			}else{
				if(checkElement(matrixB, meB.row, meB.col) == false){
					matrixB.push_back(meB);
					countB += 1;
				}
			}
		}

		//sort the matrix by row wise
		sort(matrixB.begin(), matrixB.end(), [](matrixElement a, matrixElement b){
			return a.row < b.row;	
		});
	

		reverse(matrixA.begin(), matrixA.end());
		reverse(matrixB.begin(), matrixB.end());

		clock_t start, stop;

		start = clock();
		sparseMatrixAddition(matrixA, matrixB);
		stop = clock();

		double runtime = double(stop - start)/CLOCKS_PER_SEC;
		file_writer << "(" << sp << " -> " << runtime << " seconds)" << endl;
		

	}

	cout << "Run time for different sparsity value is computed \nOpen runtime.txt file for data" << endl;
	
	//Calculating the run time for normal matrix addition
	clock_t start1, stop1;
	file_writer << "\n\nThe normal matrix addition of dimensions " << m << "*" << n << " takes" << endl;
	start1 = clock();
	noramlMatrixAddition(m,n,p);
	stop1 = clock();
	double runtime1 = double(stop1 - start1)/CLOCKS_PER_SEC;
	file_writer << runtime1 << "seconds" << endl;
	file_writer.close();

	return 0;
	
}


int sparseMatrixAddition(vector<matrixElement> matrixA, vector<matrixElement> matrixB){

	vector <matrixElement> matrixR;

	int rA, cA, vA, rB, cB, vB;
	matrixElement meR;

	while(!matrixA.empty() || !matrixB.empty()){
		if(matrixA.size() != 0){
			rA = matrixA[matrixA.size()-1].row;
			cA = matrixA[matrixA.size()-1].col;
			vA = matrixA[matrixA.size()-1].value;
		}else{
			rA = INT_MAX;
			cA = INT_MAX;
			vA = INT_MAX;
		}

		if(matrixB.size() != 0){
			rB = matrixB[matrixB.size()-1].row;
			cB = matrixB[matrixB.size()-1].col;
			vB = matrixB[matrixB.size()-1].value;
		}else{
			rB = INT_MAX;
			cB = INT_MAX;
			vB = INT_MAX;
		}
		



		if(rA < rB){
			matrixR.push_back(matrixA[matrixA.size()-1]);

			matrixA.pop_back();


		}
		else if(rB < rA){
			matrixR.push_back(matrixB[matrixB.size()-1]);

			matrixB.pop_back();
		}

		else{
			if(cA < cB){
				matrixR.push_back(matrixA[matrixA.size()-1]);

				matrixA.pop_back();
			}
			else if(cB < cA){
				matrixR.push_back(matrixB[matrixB.size()-1]);
				matrixB.pop_back();

			}
			else{
				meR.row = rA;
				meR.col = cA;
				meR.value = vA + vB;

				matrixR.push_back(meR);
				
				matrixA.pop_back();
				matrixB.pop_back();
			}
		}

	}
	/*
	//Accessing the resultant matrix R
	cout << "Result Matrix: ";
	for(int i=0; i<matrixR.size(); i++){
		cout << "(" << matrixR[i].row << "," << matrixR[i].col << "," << matrixR[i].value << "), ";
	}
	cout << endl;
	*/
	return 0;
}


//Function to check that there is no overlap of the coordinates
bool checkElement(vector<matrixElement> matrix, int row, int col){
	for(int i=0; i<matrix.size(); i++){
		if(matrix[i].row == row && matrix[i].col == col){
			return true;
		}
	}
	return false;
}


void noramlMatrixAddition(int m, int n, int p){


	int matrixA[m][n], matrixB[n][p], matrixR[m][p];


	//Creating matrix of size m*n randomnly
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			matrixA[i][j] = rand()%100;
		}
	}


	//Creating Matrix of size n*p randomnly
	for(int i=0; i<n; i++){
		for(int j=0; j<p; j++){
			matrixB[i][j] = rand()%100;
		}
	}

	//Doing normal matrix Multiplication


	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			matrixR[i][j] = matrixA[i][j] + matrixB[i][j];
		}
	}

}