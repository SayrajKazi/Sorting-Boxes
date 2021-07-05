#include "box.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#define NUMBER_OF_boxes
#define inputboxfile "boxes_data.txt"
void sort( box *array, int count );

int main( int argc, char * argv[] ){
       	fstream names_file( inputboxfile, ios::in );
        box*    boxes= nullptr;
            
           string line;
    
           int Boxlength;
           if(names_file.is_open())
           {
               getline(names_file,line);      
                Boxlength= stoi(line);
                boxes= new box [Boxlength];
               
           
             for(int i=0; i< Boxlength; i++)
             {   
                getline(names_file,line);
      
                       
          
                int lineh= stoi(line.substr(0, line.find(' ')));
                int  linew= stoi(line.substr(line.find(' '), line.length()-1));
                
              
                boxes[i].height= lineh;
                boxes[i].width= linew;
                
               
                       
              } 
             
                      

                   

                
            

                sort(  boxes,  Boxlength );
               
                for(int i=0; i< Boxlength; i++){
                    cout << boxes[i].getSquareArea() << endl;

                }
           }

           
 }



void sort( box *array, int count )
{
  int i, j;

  for( i= 0; i < count - 1; i++ ){
    for( j= i+1; j < count; j++ ){
      if ( array[i].getSquareArea() > array[j].getSquareArea() ){
        box temp;
        temp= array[i];
        array[i]= array[j];
        array[j]= temp;
      }
    }
  }
}

