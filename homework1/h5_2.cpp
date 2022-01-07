#include <iostream>
using namespace std;
class Person 
{
  private:
  static const int LIMIT=25;
  string lname;   //Person’s last name
  char fname[LIMIT];   //Person’s first name
  public:
  Person( ) {lname =" "; fname[0] = '\0'; }   //#1
  Person(const string &ln, const char *fn = "Hey you")  //#2
  {
  lname=ln;
  for(int i=0;*(fn+i)!='\0';i++)
  *(fname+i)=*(fn+i);
  }
  // the following methods display lname and fname
  void show( ) const;  //firstname lastname format
  void FormalShow( ) const;  //lastname, firstname format
};
void Person::show()const
{
  for(int i=0;*(fname+i)!='\0';i++)
  cout<<fname[i];
  cout<<endl;
  cout<<lname<<" ";
} 

void Person::FormalShow()const
{
    cout<<lname<<" ";
    for(int i=0;*(fname+i)!='\0';i++)
    cout<<fname[i];
    cout<<endl;
}

int main()
{
Person one;   //use default constructor
Person two("Smythecraft");  //use #2 with one default argument
Person three("Dimwiddy", "Sam");  //use #2, no defaults
one.show();
two.show( );
cout<<endl;
three.FormalShow( );
// etc. for two and three
    return 0;
}










