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
  fstream myfile ("ddl.csv" , ios::in | ios::out);
  fstream op("final.csv" , ios::out | ios::trunc | ios::in);
  if (myfile.is_open())
  {int i=0;
     myfile.getline(head, 198, '\n');
  op<<head;

    // for(int i=0;head[i] !='\n';i++)
    //   op<<head[i];


    while ( myfile.get(ch) )
    {
      switch (ch)
      {
      case '\n':
         count++;
         op<<ch;

       
       break;

       case ';':
       op<<',';
       
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
    op<<ch;

      }

   } 


   myfile.close(); 
   op.close();
}


  else 
    cout << "Unable to open file "; 
cout<<endl<<"No. of lines are "<<count<<endl;

  return 0;
}