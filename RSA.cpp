
#include<iostream>
#include<math.h>
using namespace std;
// найти нод
int gcd(int a, int b) {
   int t;
   while(1) {
      t= a%b;
      if(t==0)
      return b;
      a = b;
      b= t;
   }
}
int main() {
   //выбрпать 2 любых числа
   double p = 13;
   double q = 11;
   double n=p*q;//вычисление числа n
   double track;
   double phi= (p-1)*(q-1);//вычисление фи
   //открытый ключ
   //e для шифрования
   double e=7;
   //выбор для 1 < e < phi(n) и нод(e, phi(n)) = 1; i.e., e и phi(n) взаимно простые числа.
   while(e<phi) {
      track = gcd(e,phi);
      if(track==1)
         break;
      else
         e++;
   }
   //закрытый ключ
   //d для расшифорования
   //выбрать d для того чтобы он подходил d*e = 1 mod phi
   double d1=1/e;
   double d=fmod(d1,phi);
   double message = 9;
   double c = pow(message,e); //шифрование письма
   double m = pow(c,d);
   c=fmod(c,n);
   m=fmod(m,n);
   cout<<"Original Message = "<<message;
   cout<<"\n"<<"p = "<<p;
   cout<<"\n"<<"q = "<<q;
   cout<<"\n"<<"n = pq = "<<n;
   cout<<"\n"<<"phi = "<<phi;
   cout<<"\n"<<"e = "<<e;
   cout<<"\n"<<"d = "<<d;
   cout<<"\n"<<"Encrypted message = "<<c;
   cout<<"\n"<<"Decrypted message = "<<m;
   return 0;
}
