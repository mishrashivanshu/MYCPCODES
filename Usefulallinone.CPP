//Euclid's Algorithm
int GCD(int A, int B) {
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}
//extended euclidean algorithm
void extendedEuclid(int A, int B) {
  //with globally declared d,x,y;
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}
//Modular Exponentiation with Mod 'M'
int modularExponentiation(int x,int n,int M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modularExponentiation((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;

}
//Modular Exponentiation without Modular or Binary Exponentiation
int binaryExponentiation(int x,int n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return binaryExponentiation(x*x,n/2);
    else                             //n is odd
        return x*binaryExponentiation(x*x,(n-1)/2);
}
//to find Modular multiplicative inverse
int modInverse(int A, int M)
//globally declared d,x,y
{
    extendedEuclid(A,M);
    return (x%M+M)%M;    //x may be negative
}
//to find Modular multiplicative inverse when the M is prime
int modInverse(int A,int M)
{
    return modularExponentiation(A,M-2,M);
}
