#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int modInverse(int e, int M)
{
    for (int X = 1; X < M; X++)
        if (((e % M) * (X % M)) % M == 1)
            return X;
}
int decryption(int c , int d, int n){

    int r=pow(c,d);
    return r-(r/n)*n;

}


int main()
{   int p,q,n,e,d,M,ci;

    printf("Enter two prime number:");
    scanf("%d %d",&p,&q);
    printf("Enter the value of e:");
    scanf("%d",&e);
    n=p*q;
    M=(p-1)*(q-1);
    d=modInverse(e,M);
    printf("public key is:%d %d\n",e,n);
    printf("secret key is %d %d:\n",d,n);


    int massage;
    printf("Enter the massage:");
    scanf("%d",&massage);
    int z = pow(massage,e);
    ci=z-(z/n)*n;
    printf("Encrypted value is:%d",ci);

    printf("original massage is: %d",decryption(ci,d,n));

    return 0;
}
