#include<iostream>
#include<math.h>
using namespace std;

//prototypes
void one();
void two_i_a();
void two_i_b();
void two_ii();

int main(){
	cout<<"Computational Mathematics (SECI-1113)"<<endl;
    cout<<"Project #1: Programming based Assignment "<<endl;
	cout<<"\n##############################\nProblem (1)\n"; one();
	cout<<"\n##############################\nProblem (2:i:A)\n"; two_i_a();
	cout<<"\n\n##############################\nProblem (2:i:B)\n"; two_i_b();
	cout<<"\n\n##############################\nProblem (2:ii)\n"; two_ii();
	cout<<endl;
    return 0;
}

void one(){
	int i,j,k,n=3;
    float mat[n][n+1]={{2,4,-1,2},{4,9,-3,8},{-2,-3,7,10}};
    float res[n];
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(abs(mat[i][i]) < abs(mat[j][i])){
                for(k=0;k<n+1;k++){
                    /* swapping mat[i][k] and mat[j][k] */
        			mat[i][k]=mat[i][k]+mat[j][k];
                    mat[j][k]=mat[i][k]-mat[j][k];
                    mat[i][k]=mat[i][k]-mat[j][k];
	}}}}
    /* performing Gaussian elimination */
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            float f=mat[j][i]/mat[i][i];
            for(k=0;k<n+1;k++){mat[j][k]=mat[j][k]-f*mat[i][k];}
	}}
    /* Backward substitution for discovering values of unknowns */
    for(i=n-1;i>=0;i--){
        res[i]=mat[i][n];
        for(j=i+1;j<n;j++){if(i!=j)res[i]=res[i]-mat[i][j]*res[j];}
  		res[i]=res[i]/mat[i][i];  
    }
    cout<<"The values of unknowns for the equations:\n";
    for(i=0;i<n;i++){cout<<res[i]<<"\n";}
}

void two_i_a(){
	double fa = (pow(1.5,3)-6*pow(1.5,2)+11*1.5-6);
	double fb = (pow(5,3)-6*pow(5,2)+11*5-6);
	double fab = fa*fb;
	cout << fab << " > 0";	
}

void two_i_b(){
	double fa = (pow(2.5,3)-6*pow(2.5,2)+11*2.5-6);
	double fb = (pow(4,3)-6*pow(4,2)+11*4-6);
	double fab = fa*fb;
	cout << fab << " < 0";
}

double fx(double x){
	return pow(x,3)-pow(6*x,2)+11*x-6;
}

void two_ii(){
   double a=2.5,b=4,c=b;
   while((b-a) >= 0.01) {
      c = (a+b)/2;
      if(fx(c) == 0.0) break;
      else if(fx(c)*fx(a)<0) b = c;
      else a = c;}
   cout << "The value of Root is : " << (int)c;
}

