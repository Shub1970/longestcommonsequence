/* this was a worst way of doing this*/
/*#include<iostream>    
using namespace std;
int max(int a, int b);
int LCS(char *x,char *y,int m, int n){
    if(m==0||n==0)
        return 0;
    if(x[m-1]==y[n-1])
        return 1+LCS(x,y,m-1,n-1);
    else
        return max(LCS(x,y,m,n-1),LCS(x,y,m-1,n));
    
}
int max(int a,int b){
    return(a>b)?a:b;
}
int main()
{
    char X[]="AGGTAB";
    char Y[]="GXTXAYB";
    int m=sizeof(X)/sizeof(X[0])-1;
    int n=sizeof(Y)/sizeof(Y[0])-1;
    cout << " max sequence is"<<LCS(X,Y,m,n);
}
*/
#include <iostream>
#include<cstring>
using namespace std;
int lcsAlgo(char *s1,char *s2,int m,int n){
    int LCS_table[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if (i==0||j==0)
             LCS_table[i][j]=0;
            else if (s1[i-1]==s2[j-1])
             LCS_table[i][j]=LCS_table[i-1][j-1]+1;
            else
             LCS_table[i][j]=max(LCS_table[i-1][j],LCS_table[i][j-1]);

        }
    }
    int index =LCS_table[m][n];
    char lcsAlgo[index+1];
    lcsAlgo[index]='\0';
    int i=m,j=n;
    while(i>0 && j>0){
        if (s1[i-1]==s2[j-1]){
            lcsAlgo[index -1]=s1[i-1];
            i--;
            j--;
            index--;
        }
        else if (LCS_table[i-1][j]>LCS_table[i][j-1])
         i--;
        else
         j--;
    }
    // printing the sub sequences
    cout << "s1:" << s1<<"\ns2:"<<s2<<"\nLCS "<< lcsAlgo<<"\n";
}
int main(){
    char X[]="AGGTAB";
    char Y[]="GXTXAYB";
    int m=strlen(X);
    int n=strlen(Y);

    lcsAlgo(X,Y,m,n);
}