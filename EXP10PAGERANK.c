#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cout << "Enter the no of pages: \n";
    cin >> n;
    
    vector<vector<int>> linkmatrix(n,vector<int>(n));
    cout << "\nEnter the links(1 if i and j have link,else 0):\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> linkmatrix[i][j];
        }
    }
    
    double d = 0.85;//damping no
    vector<double> rank(n,1.0);
    vector<double> newrank(n,0.0);
    
    cout << "\n Initial Page Rank : ";
    for(int i=0;i<n;i++){
        cout << "p" << i+1 << "=" << rank[i] << " ";
    }
    
    int iterations = 5;
    for(int iter=0;iter<iterations;iter++){
        for(int i=0;i<n;i++){
            double sum =0;
            for(int j=0;j<n;j++){
                if(linkmatrix[j][i] == 1){
                    int outdegree = 0;
                    for(int k=0;k<n;k++){
                        if(linkmatrix[j][k]==1){
                            outdegree++;
                        }
                    }
                    sum = sum + rank[j]/outdegree;
                }
            }
            newrank[i] = (1-d)+d*sum;
        }
        
        rank=newrank;
        cout << "\nAfter iteration " << iter+1 << " : " ;
        for(int i=0;i<n;i++){
            cout << "p" << i+1 << "=" << rank[i] << " ";
        }
    }
    
    cout << "\nFinal Rank :\n";
    for(int i=0;i<n;i++){
        cout << "p" << i+1 << "=" << rank[i] << endl;
    }
    return 0;
}