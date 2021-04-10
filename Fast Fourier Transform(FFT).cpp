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
complex fast_fourier_trasform(complex lst[],int N , int k , const int n){
 if (N == 1 ){



    return  lst[0];
 }

 else{

    const double pi = 3.14159265;

    complex even_seq[N/2];
    complex odd_seq[N/2];
    int o = 0 ;
    int e= 0;
    for(int i=0 ; i<N ; i++){
        if (i% 2 == 0){
                even_seq[e] = lst[i] ;




                e+=1;

        }
        else{
            odd_seq[o] = lst[i] ;
            o+=1 ;
        }

    }

        complex Wnk = complex(cos((2*pi*k)/n),-sin((2*pi*k)/n));
        k =k*2;
        N = N/2;


        complex even = fast_fourier_trasform(even_seq , N ,k , n) ;
        complex odd = fast_fourier_trasform(odd_seq ,N, k , n ) ;
        complex r = even.sum(even , odd.mul(odd , Wnk));


        return r ;



}

}


int main(){
    int N  ;
    double x ;
    const double pi = 3.14159265;


    cout<< "size of time sequence is " ;
    cin>> N;

    complex sequence[N];
    double phase[N] ;
     double magnitude[N] ;
      for(int i=0 ; i<N ; i++){
        cout<< "enter " << i+1 << " element ";
        cin>> x;
        sequence[i] = complex(x , 0) ;

    }

    complex  result[N];
    for (int i =0 ; i<N; i++){
            const int n = N ;

           result[i] = fast_fourier_trasform(sequence , N , i  , n );
            magnitude[i] = sqrt(pow( result[i].get_real(), 2) + pow( result[i].get_img(), 2));
         if ( result[i].get_real()< 0 &  result[i].get_img()> 0)
         {phase[i] =   (180-atan(abs( result[i].get_img()) / abs( result[i].get_real()))* 180 / pi );}
          else if ( result[i].get_real()< 0 &  result[i].get_img()<= 0)
         {phase[i] =  (180+atan(abs( result[i].get_img()) / abs( result[i].get_real()))* 180 / pi ) ;}
         else{
             phase[i] = (atan( result[i].get_img() /  result[i].get_real())* 180 / pi );
         }





             }  cout<< "The DFT of given  points is \n"  ;

     for (int i =0 ; i<N; i++){
        cout<< result[i].get_real() << " " << result[i].get_img() << "\n";

     }

    for ( int i = 0 ; i < N ; i++ ){
    cout<< "phase of point " << i+1  <<  " is " << phase[i]<< "\n" ;
    }
    for ( int i = 0 ; i < N ; i++ ){
    cout<< "magnitude of point "<< i+1  << " is " << magnitude[i]<< "\n" ;
    }









    return 0;
    }
