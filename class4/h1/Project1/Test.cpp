#include <iostream>
using namespace std;
//²âÊÔ
int main()
{
   int i;
   char a = 'y';
   char b = 'n';
   cin>>i;
   if (i>3) cout<<"ok";
   else cout<<"wrong";
   
   switch(b){
      case 'y':
         cout<<"a µÈÓÚ b"<<endl;
         break;
      default:
         cout<<"a is not equal b"<<endl;
         break;
   } 

   if(a==c?0:1){cout<<"a£¡=c"<<endl;}
   else cout<<"a==c"<<endl;

   double d = 1.01e+2, e = 2.01E-3, f = -9.5;
   int otc = 1234567;
   cout << hex*otc << endl;

   while (true) {
       cout << d << endl;
       if (Bit)break;
   }

   int m = 10, n = 9;
   cout << m  ^ n << endl;

   string str = "abc123";
   for (int i = 0; i < str.length(); i++) {
       cout << str[i];
   }

   return 0;
}