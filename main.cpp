#include <iostream>

using namespace std;
#define gap_penalty  2
#define match_award  0
#define mismatch_penalty 1
void printer(int m,int n,int** arr){
int i,j;
    for(i=0;i<m;i++){

        for(j=0;j<n;j++){
            cout<< arr[i][j]<<" ";        }
        cout<<"\n";
    }
}

int** init_matrix(int m,int n){
    int **arr=0;
    arr = new int*[m];
    int i,j;
    for(i=0;i<m;i++){
        arr[i]=new int[n];
        for(j=0;j<n;j++){
            arr[i][j]=0;        }
    }
return arr;
}

int score_calculator(char a,char b){
    if(a==b)
        return match_award;
    else if(a=='_'|| b=='_' )
        return gap_penalty;
    else
        return mismatch_penalty;
}

int scorer(string& str1,string& str2){
    int m=str1.length();
    int n=str2.length();
    int i,j;
    int match,up,side;
    int** arr=init_matrix(m+1,n+1);
    for(i=0;i<m+1;i++)
        arr[i][0]=gap_penalty*i;
    for(i=0;i<n+1;i++)
        arr[0][i]=gap_penalty*i;
    for(i=1;i<m+1;i++)
        for(j=1;j<n+1;j++)
        {
            match=arr[i-1][j-1]+score_calculator(str1[j-1],str2[i-1]);
            up=arr[i-1][j]+gap_penalty;
            side=arr[i][j-1]+gap_penalty;

            arr[i][j]=min(min(match,up),side);


        }
    string x="";
    string y="";
    i=m;
    j=n;
    while (i>0 and j>0){
        int current = arr[i][j];
        int diagonal = arr[i-1][j-1];
        int up = arr[i][j-1];
        int left = arr[i-1][j];

        if(current==up+gap_penalty){
            x.append(str1[j-1],1);
            y.append("_");
            j--;

        }
        else if(current==left+gap_penalty){
            y.append(str2[i-1],1);
            x.append("_");
            i--;

        }
        else

    }
    printer(m+1,n+1,arr);


}


int main() {
    string seq1 = "ATTACA";
    string seq2 = "ATGCT";
     scorer(seq1,seq2);
    return 0;
}
