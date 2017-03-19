// reading a text file
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () 
{
  char ch;
  int count=0,  j=0;
  char head[200];
  fstream myfile ("final.csv" , ios::in | ios::out);
  fstream op0("new0.csv" , ios::out | ios::trunc | ios::in);
  
  if (myfile.is_open())
  {
     myfile.getline(head, 198, '\n');
  op0<<head;
    
     while ( myfile.get(ch) )
    {
      switch (ch)
      {
      case '\n':
         count++;
  //       if (count >25)
  
         op0<<ch;

       
       break;

       case ';':
       op0<<',';
       break;

       case '"':
       myfile.seekp(1,ios::cur);
       if (ch =='"')
        break;
      else
      {
        myfile.seekp(-1,ios::cur);

      }

    default:
    op0<<ch;

      }

   myfile.close(); 
   op0.close();
}
}

  else 
    cout << "Unable to open file "; 

cout<<endl<<"No. of lines are "<<count<<endl;
cout<<"\tdas" << head << '\n';

  return 0;
}


  
  /* 
  fstream op1("new1.csv" , ios::out | ios::trunc | ios::in);

if (myfile.is_open())
  {
    while ( myfile.get(ch) )
    {
      switch (ch)
      {
      case '\n':
         count++;
         if (count >25)
         {
            
            op1<<head;
         }
         op0<<ch;

       
       break;

       case ';':
       op0<<',';
       break;

       case '"':
       myfile.seekp(1,ios::cur);
       if (ch =='"')
        break;
      else
      {
        myfile.seekp(-1,ios::cur);

      }

    default:
    op0<<ch;

      }
*/