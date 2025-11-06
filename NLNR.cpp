#include <bits/stdc++.h>
using namespace std;

double F1(double x, double y) {
    return x * x + y * y - 4;
}

double F2(double x, double y) {
    return exp(x) + y - 1;
}


struct J {
    
    double  x , y , det ,delx ,dely ;
    int n = 2 ;
    vector<vector<double>> j ,jinv ;
    
    J (double x , double y )  {
        
        
        j = vector<vector<double>>(2, vector<double>(2));
        jinv = vector<vector<double>>(2, vector<double>(2));
        
        this-> x = x ;
        this-> y =y ;
        j[0][0] = 2*x ;
        j[0][1] = 2*y ;
        j[1][0] = exp(x) ;
        j[1][1] = 1 ;
        
        det = j[0][0]*j[1][1] - j[1][0]*j[0][1];
        
        jinv[0][0] = j[1][1] /det ;
        jinv[1][1] = j[0][0] /det  ; 
        jinv[1][0] = -j[1][0] /det ;
        jinv[0][1] = -j[0][1] /det ;
        
        double f1 = F1(x,y) ;
        double f2 = F2(x,y) ;
        delx = f1*jinv[0][0] + f2*jinv[0][1] ;
        dely = f1*jinv[1][0] + f2*jinv[1][1] ;
    } 
};





int main() {
	// your code goes here
	
	double xn = 1;
	double yn = 1 ; 
	double eps = 1e-6 ;
	
	while( fabs(F1(xn,yn)) >= eps|| fabs(F2(xn,yn)) >= eps  ){
        J jacobian(xn,yn) ;
        xn -= jacobian.delx ;
        yn -= jacobian.dely ;
	}
	
	cout << xn << " " << yn << endl; 
	
	return 0 ;

}
