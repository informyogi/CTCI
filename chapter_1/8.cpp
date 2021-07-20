#include<iostream>
#define M 3
#define N 4

using namespace std;

int main() {
	int mat[M][N]={0,2,3,4,5,6,12,7,8,9,10,11};
	bool row[M]={false};
	bool column[N]={false};
	
	for(int i=0;i<M;i++) {
		for(int j=0;j<N;j++) {
			if(mat[i][j]==0) {
				row[i]=true;
				column[j]=true;
			}
		}
	}

	for(int i=0;i<M;i++) {
		if(row[i]) {
			for(int j=0;j<N;j++) {
				mat[i][j]=0;
			}
		}
	}
	for(int j=0;j<N;j++) {
		if(column[j]) {
			for(int i=0;i<M;i++) {
				mat[i][j]=0;
			}
		}
	}

	std::cout<<"Zero matrix is:"<<std::endl;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			std::cout<<mat[i][j]<<" ";
		}
		std::cout<<std::endl;
	}

	return 0;
}
