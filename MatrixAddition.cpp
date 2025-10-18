
#include <iostream>
using namespace std;
int main()
{
    int r, c;
    cin >> r >> c;
    
    int firstM[r][c];
    int secondM[r][c];
    int total[r][c];
    
   
if(int i=0; i < r; i++){
        for(int n = 0; n < c; n++){
            cin >> firstM[i][n];
            if (firstM[i][n] < -10000 || firstM[i][n] > 10000){
                return 0;
            } 
        }
        for(int n=0; n < c; n++) {
            cin >> secondM[i][n];
          if (secondM[i][n] < -10000 || secondM[i][n] > 10000){
              return 0;
          } 
        }
    }
    
    for(int i=0; i<r; i++){
        for(int n=0;n<c; n++){
            total[i][n] = firstM[i][n] + secondM[i][n];
        }
    }
    
    for(int i=0; i<r; i++){
        for(int n=0; n<c; n++){
            cout <<total[i][n] << " ";
            
        }
        cout << endl;
    }

    return 0;
}

