#include <iostream>
#include <vector>
 
using namespace std;

// ~ printing the matrix ~
void printsudoku(int v[9][9]){
    cout << "[]======================[]"<< endl;
        for ( int r = 0 ; r < 9 ; r++){
            cout<<"||";
                for ( int c = 0 ; c < 9 ; c++){
                    
                    if(c%3==0 && c>0 ) cout<<"||";
                    cout<<v[r][c]<<" ";
                    
                }

            cout<<"||"<<endl;
            
            if((r+1)%3 == 0 && r<8) cout << "||======================||"<< endl;

            
        
        }
    cout << "[]======================[]"<< endl;
}



// ~ Checking if the number is already present ~
bool checkvalue(int a[9][9], int row , int column , int num ){
    for ( int i = 0 ; i < 9 ; i ++){
        if ( a[i][column] == num ) return false ;
        if ( a[row][i] == num ) return false ;
        if ( a[3 * (row / 3) + i / 3][3 * (column / 3) + i % 3] == num) return false;
    }
return true;
}



// ~ iterating through numbers ~
bool solvesudoku(int v[9][9]){
    for ( int r = 0 ; r < 9 ; r++){
        for ( int c = 0 ; c < 9 ; c++ ){
            if(v[r][c]==0){

                for ( int i = 1 ; i <= 9 ; i ++){
                    if(checkvalue(v, r , c , i )) {
                        v[r][c] = i;

                        if(solvesudoku(v) == true ) return true;
                        else v[r][c] = 0 ;
                    }
                }
                return false ; 
            }
        }
    }
    return true ; 
}





int main()

{
    int sudoku[9][9] = {
       {0,0,0,0,7,8,0,0,5},
		{0,0,5,4,2,9,0,0,0},
		{7,3,0,0,0,1,0,9,0},
		{0,7,0,0,0,0,0,2,0},
		{9,0,6,0,0,0,5,0,7},
		{1,2,0,0,0,5,9,3,6},
		{0,6,9,0,5,7,0,8,1},
		{3,0,1,9,0,0,0,6,0},
		{2,0,0,6,1,0,4,5,0}
         };
    if(solvesudoku(sudoku)) printsudoku(sudoku);
    else
      cout<<"No solution exists"<<endl;
    return 0;

}

