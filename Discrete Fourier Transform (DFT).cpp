#include<iostream>
#include<cmath>

using namespace std;
class complex{
private :
    double real ;
    double img;
public:

    complex(double a = 0.0, double b  = 0.0){
    new_complex(a,  b);
    }
    double get_real(){
    return  real;
    }
     double get_img(){
    return  img;
    }
    void  new_complex(double a, double b);

    complex sum(complex  c1  ,  complex c2);
    complex mul(complex c1,  complex c2) ;

};

void complex::new_complex(double a, double b){
real =  a;
img= b  ;
}
complex complex::sum(complex c1 ,  complex c2){
 real  =  c1.get_real() + c2.get_real();
 img = c1.get_img() + c2.get_img();
 double threshold = .000001 ;
if (abs(real )<= threshold)
{
    real = 0 ;
}
if(abs(img) <= threshold){
    img = 0 ;
}


 return  complex(real ,  img);
}
complex complex::mul(complex c1 ,  complex c2){
 real  =  (c1.get_real() * c2.get_real()) - (c1.get_img() * c2.get_img());
 img = (c1.get_real() * c2.get_img()) + (c1.get_img() * c2.get_real());

 double threshold = .000001 ;
if (abs(real )<= threshold)
{
    real = 0 ;
}
if(abs(img) <= threshold){
    img = 0 ;
}


 return  complex(real ,  img);
}




int main(){
    int N  ;
    double x ;
    cout<< "size of time sequence is " ;
    cin>> N;

    complex sequence[N];
    for(int i=0 ; i<N ; i++){
        cout<< "enter " << i+1 << " element ";
        cin>> x;
        sequence[i] = complex(x ,  0);


    }
     double phase[N] ;
     double magnitude[N] ;
    const double pi = 3.14159265;
    complex arr[N];
    cout<< "The DFT of given  points is \n"  ;


    for(int i = 0  ;  i< N ; i++){
        complex sum(0,0);

        complex mul(0 , 0);
        complex arr[N]= {} ;


        for(int j=0 ;  j<N ;j++){


                arr[j] = complex(cos((2*pi*i*j)/N),-sin((2*pi*i*j)/N));
                mul.mul(arr[j] , sequence[j]);
                sum.sum(sum ,  mul);

        }

         cout<< sum.get_real()<< "  " << sum.get_img()<<"\n" ;
         magnitude[i] = sqrt(pow(sum.get_real(), 2) + pow(sum.get_img(), 2));
         if (sum.get_real()< 0 & sum.get_img()> 0)
         {phase[i] =   (180-atan(abs(sum.get_img()) / abs(sum.get_real()))* 180 / pi );}
          else if (sum.get_real()< 0 & sum.get_img()<= 0)
         {phase[i] =  (180+atan(abs(sum.get_img()) / abs(sum.get_real()))* 180 / pi ) ;}
         else{
             phase[i] = (atan(sum.get_img() / sum.get_real())* 180 / pi );
         }













    }
    for ( int i = 0 ; i < N ; i++ ){
    cout<< "phase of point " << i+1  <<  " is " << phase[i]<< "\n" ;
    }
    for ( int i = 0 ; i < N ; i++ ){
    cout<< "magnitude of point "<< i+1  << " is " << magnitude[i]<< "\n" ;
    }


    return 0;

}



