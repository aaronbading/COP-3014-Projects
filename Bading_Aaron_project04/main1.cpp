//Aaron Bading
#include <iostream>
#include <fstream>
#include<ios>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;
//good job
class file
{
 public:
//constructor
 file(int rows, int columns, int pixel)
{ this->rows=rows;
  this->columns=columns;
  this->pixel=pixel;}

int getrows()
{return this->rows;}

int getcolumns()
{return this-> columns;}

void setrows(int rows)
{this->rows=rows;}

 void setcolumns(int columns)
{this->columns=columns;}

void setpixel(int pixel)
{this->pixel=pixel;}

int getpixel()
{return this->pixel;}

  private :
int rows;
int columns;
int pixel;
};
void display()
{

const int numWidth      =50;

cout  << "+" << setw(numWidth) << setfill('=') << "+" << endl;
cout <<"|"   << setfill(' ')<<  setw(numWidth-1) << left <<  " Pgm Image Manipulation Program  " << "|" << endl;
cout  << right << "|" << setw(numWidth) << setfill('-') << "|" << endl;
cout <<"|" <<left  << setfill(' ')<<  setw(numWidth-1) <<   "1. Rotate image 90 degrees clockwise  " << "|" << endl;
cout <<"|"   << setfill(' ')<<  setw(numWidth-1) <<   "2. Rotate image 180 degrees clockwise  " << "|" << endl;
cout <<"|"   << setfill(' ')<<  setw(numWidth-1) <<   "3. Rotate image 270 degrees clockwise  " << "|" << endl;
cout <<"|"   << setfill(' ')<<  setw(numWidth-1) <<   "4. Flip image vertically (about x-axis)" << "|" << endl;
cout <<"|"   << setfill(' ')<<  setw(numWidth-1) <<   "5. Flip image horizontally (about y-axis) " << "|" << endl;
cout <<"|"   << setfill(' ')<<  setw(numWidth-1) <<   "6. Convert to high contrast " << "|" << endl;
cout <<"|"   << setfill(' ')<<  setw(numWidth-1) <<   "7. Save image to a file  " << "|" << endl;
cout <<"|"   << setfill(' ')<<  setw(numWidth-1) <<   "8. Load another image file  " << "|" << endl;
cout <<"|"   << setfill(' ')<<  setw(numWidth-1) <<   "9. Display this menu  " << "|" << endl;
cout  << right << "|" << setw(numWidth) << setfill(' ') << "|" << endl;
cout <<"|" <<left  << setfill(' ')<<  setw(numWidth-1) <<   "0.  Quit" << "|" << endl;
cout  << right << "|" << setw(numWidth) << setfill('-') << "|" << endl;

}
void rotate(file &temp1,int** &ippArray1,int** &ippArray2)
{
  int x ,y;
  x= temp1.getrows();
  y= temp1.getcolumns();

  if(temp1.getrows()<temp1.getcolumns())
  {

        //start of rotation algorithm
        int temp[y][x];
        // attempting this Now
        for(int i=0;i<temp1.getrows();i++)
        {
            for(int j=0;j<temp1.getcolumns();j++)
            {temp[j][i]= ippArray1[i][j];}
        }
        for(int i=0;i<temp1.getcolumns(); i++)
        {
          for(int j=0;j<temp1.getrows()/2;j++)
              { int tempo;
                tempo=temp[i][temp1.getrows()-j-1];
                temp[i][temp1.getrows()-j-1]=temp[i][j];
                temp[i][j]=tempo;
              }
        }



        for(int i=0; i<temp1.getcolumns(); i++)
        {
            for(int j=0; j<temp1.getrows();j++)
            {ippArray2[i][j]=temp[i][j];}

        }

        temp1.setrows(y);
        temp1.setcolumns(x);


  }
  else
  {



  //start of rotation algorithm
  int temp[y][x];
  // attempting this Now
  for(int i=0;i<temp1.getrows();i++)
  {
    for(int j=0;j<temp1.getcolumns();j++)
    {temp[j][i]= ippArray2[i][j];}

  }

  for(int i=0;i<temp1.getcolumns(); i++)
  {
    for(int j=0;j<temp1.getrows()/2;j++)
        { int tempo;
          tempo=temp[i][temp1.getrows()-j-1];
          temp[i][temp1.getrows()-j-1]=temp[i][j];
          temp[i][j]=tempo;
        }
  }



  for(int i=0; i<temp1.getcolumns(); i++)
  {
    for(int j=0; j<temp1.getrows();j++)
    {ippArray1[i][j]=temp[i][j];}

  }

    temp1.setrows(y);
    temp1.setcolumns(x);


  }

}
int main()
{

ifstream inFS;
ofstream outFS;
bool ultimatedecision=true;

do
{

      bool decision =true;
      string filename;
      //finds file name
      while(decision)
      {
          cout << "Please enter the name of the image file to open (31 characters max):" << endl;
          cin >> filename;
         if (filename.size()>31)
           {
             cout << "Try again" << endl;
           }
         else
           {
             decision=false;
           }
      }

      cout << "Opening pgm file" << endl;
        inFS.open(filename);
        if (!inFS.is_open())
        {
          cout << "Could not open file  " << filename<< endl;
          return 1;
        }
        cout << "File successfully opened, reading three integers." << endl;

      //Input file stream

      char num1FrmFile;
      int num2FrmFile,columns,rows,pixel;
      inFS >> num1FrmFile;
      inFS >> num2FrmFile;
      inFS >> columns;
      inFS >> rows;
      inFS >> pixel;
      file temp1(rows,columns,pixel);

      // dynamically allocated 2d array
      int** ippArray1= new int*[rows];
      for(int i=0 ; i<rows ; ++i)
      {
        ippArray1[i]=new int[columns];
      }
      //fill array
      for (int i=0; i<rows; i++)
      {
       for(int j=0; j<columns;j++)
       {inFS>>ippArray1[i][j];}

      }
      //allocate the array for the columns<rows
      int** ippArray2= new int*[columns];
      for(int i=0 ; i<columns; ++i)
      {
        ippArray2[i]=new int[rows];
      }
      cout << endl;
      cout << "Closing file myInputs." << endl;
      inFS.close();         // Done with file, so close it

      bool choice1=true;
       while(choice1)
      {
          display();
          int choice;
          cout << "Please select an action from the menu above (9 for menu):" << endl;
          cin >> choice;

        switch (choice)
        {

                case 1:
              {
                rotate(temp1,ippArray1,ippArray2);
                break;
              }
              case 2:
              {
                rotate(temp1,ippArray1,ippArray2);
                rotate(temp1,ippArray1,ippArray2);
                break;
              }
              case 3:
              {
                rotate(temp1,ippArray1,ippArray2);
                rotate(temp1,ippArray1,ippArray2);
                rotate(temp1,ippArray1,ippArray2);
                break;
              }
              case 4:
              {
                int x,y;
                x= temp1.getrows();
                y= temp1.getcolumns();

                int temp[x][y];

                if(temp1.getrows()<temp1.getcolumns())
                {


                    for(int i=0;i<temp1.getrows();i++)
                    {
                      for(int j=0;j<temp1.getcolumns();j++)
                      {temp[i][j]= ippArray1[i][j];}
                    }

                    for(int i=0;i<temp1.getrows(); i++)
                    {
                      for(int j=0;j<temp1.getcolumns()/2;j++)
                      { int tempo;
                        tempo=temp[i][temp1.getcolumns()-j-1];
                        temp[i][temp1.getcolumns()-j-1]=temp[i][j];
                        temp[i][j]=tempo;
                      }
                    }
                    for(int i=0; i<temp1.getrows(); i++)
                    {
                      for(int j=0; j<temp1.getcolumns();j++)
                        {ippArray1[i][j]=temp[i][j];}
                    }
                }
                else
                {
                      for(int i=0;i<temp1.getrows();i++)
                      {
                        for(int j=0;j<temp1.getcolumns();j++)
                          {temp[i][j]= ippArray2[i][j];}
                      }

                      for(int i=0;i<temp1.getrows(); i++)
                      {
                        for(int j=0;j<temp1.getcolumns()/2;j++)
                          { int tempo;
                            tempo=temp[i][temp1.getcolumns()-j-1];
                            temp[i][temp1.getcolumns()-j-1]=temp[i][j];
                            temp[i][j]=tempo;
                          }
                      }
                      for(int i=0; i<temp1.getrows(); i++)
                      {
                        for(int j=0; j<temp1.getcolumns();j++)
                        {ippArray2[i][j]=temp[i][j];}
                      }
                }
                break;
              }
              case 5:
              {
                   int x,y;
                   x= temp1.getrows();
                   y= temp1.getcolumns();

                  int temp[x][y];

                  if(temp1.getrows()<temp1.getcolumns())
                  {

                      for(int i=0;i<temp1.getrows();i++)
                      {
                          for(int j=0;j<temp1.getcolumns();j++)
                              {temp[i][j]= ippArray1[i][j];}
                      }

                      for(int i =0; i<temp1.getrows(); i++)
                      {
                          for(int j =0; j<temp1.getcolumns()/2; j++)
                          {

                            int tmp = temp[i][j];
                            temp[i][j]= temp[i][temp1.getcolumns()-1-j];
                            temp[i][temp1.getcolumns()-1-j]= tmp;
                          }
                      }



                      for(int i=0; i<temp1.getrows(); i++)
                      {
                        for(int j=0; j<temp1.getcolumns();j++)
                          {ippArray1[i][j]=temp[i][j];}
                      }
                      for (int i=0; i<temp1.getrows(); i++)
                      {
                        for(int j=0; j<temp1.getcolumns();j++)
                          {cout << ippArray1[i][j]<< "  ";}
                          cout << endl;
                     }
                   }
                   else
                   {

                      for(int i=0;i<temp1.getrows();i++)
                      {
                        for(int j=0;j<temp1.getcolumns();j++)
                          {temp[i][j]= ippArray2[i][j];}
                      }

                       for(int i =0; i<temp1.getrows(); i++)
                       {
                             for(int j =0; j<temp1.getcolumns()/2; j++)
                             {
                               int tmp = temp[i][j];
                               temp[i][j]= temp[i][temp1.getcolumns()-1-j];
                               temp[i][temp1.getcolumns()-1-j]= tmp;
                             }
                        }



                      for(int i=0; i<temp1.getrows(); i++)
                      {
                        for(int j=0; j<temp1.getcolumns();j++)
                          {ippArray2[i][j]=temp[i][j];}
                      }
                      for (int i=0; i<temp1.getrows(); i++)
                      {
                        for(int j=0; j<temp1.getcolumns();j++)
                          {cout << ippArray2[i][j]<< "  ";}
                          cout << endl;
                      }

                   }
                   break;
              }
              case 6:
              {
                int value;
                cout << "Please enter a desired threshold value: " <<endl;
                cin >> value;
                temp1.setpixel(value);
                cout << " Converted image to high contrast with threshold of   " << value << endl;

                break;
              }
              case 7:
              {
                    bool decision=true;
                    string filename;
                    while(decision)
                    {
                        cout << "Please enter the name of the image file to open (31 characters max):" << endl;
                        cin >> filename;
                       if (filename.size()>31)
                        {cout << "Try again" << endl;}
                       else
                        {decision=false;}
                    }
                    outFS.open(filename);
                    if (!outFS.is_open())
                    {
                          cout << "Could not open file myoutfile.txt." << endl;
                          return 1;
                    }

                    outFS << num1FrmFile << num2FrmFile << endl <<temp1.getcolumns() << " "<< temp1.getrows()<< endl<<temp1.getpixel() <<endl;

                    if(temp1.getrows()<temp1.getcolumns())
                    {
                      for (int i=0; i<temp1.getrows(); i++)
                        {
                         for(int j=0; j<temp1.getcolumns();j++)
                         {outFS<<ippArray1[i][j] << "  ";}
                         outFS <<endl;
                        }
                    }
                    else
                    {
                      for (int i=0; i<temp1.getrows(); i++)
                        {
                         for(int j=0; j<temp1.getcolumns();j++)
                         {outFS<<ippArray2[i][j] << "  ";}
                         outFS<<endl;
                        }
                    }
                    cout << "Written successfully to file myOutFile.txt." << endl;
                    cout << "Now closing file myOutFile.txt." << endl;
                    outFS.close();
                    break;

              }
              case 8:
              {
                ultimatedecision=true;
                choice1=false;
                //deallocation of the dynamically allocated 2D arrays
                for(int i=0;i<rows ;++i)
                {
                  delete [] ippArray1[i];
                }
                delete [] ippArray1;

                for(int i=0;i<rows ;++i)
                {
                  delete [] ippArray2[i];
                }
                delete [] ippArray2;

                break;
            }
            case 9:
            {
                cout << endl << endl;
                display();
                break;
            }

              case 0:
            {

                    choice1=false;
                ultimatedecision=false;

                for(int i=0;i<rows ;++i)
                {
                  delete [] ippArray1[i];
                }
                delete [] ippArray1;

                for(int i=0;i<rows ;++i)
                {
                  delete [] ippArray2[i];
                }
                delete [] ippArray2;
            }

        }

      }

}while(ultimatedecision);



  return 0;

}
