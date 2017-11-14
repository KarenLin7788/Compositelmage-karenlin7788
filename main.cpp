//Author: Xinru Lin (Kairen):
#include "bitmap.h"
#include<vector>
#include<string>
#include<cstdlib>
#include<fstream>
#include<iostream>
using namespace std;

vector<string>list();
Bitmap image;

//Global constants
const int HOW_MANY_INPUT= 10;
//prototype:
bool validBmp(string response);
bool Bitmap_isImage(int row,int cols);

vector< vector<Pixel> > composite(vector< vector< vector<Pixel> > > & Bmp);
void save(vector<vector<Pixel> >);

int main ()
{

        vector<string>list_of_files;
        vector<vector<Pixel> >bmp;
        list_of_files=list();
        string response;
        vector<string>file;

        int number_of_input;
        //The computer will ask you for  file names first(get a list of filenames)
        //As response, you have to provide file name.You can stop if you want to or you have mamimum ten times to enter your respose.
        //(use while loop here)
        do 
        { 
                cout<<"Give me a file name, and enter Done if you do not want to add more"<<endl;
                cin>>response;
                validBmp(response);
                if( number_of_input>0&&number_of_input<HOW_MANY_INPUT)
                {
                        cout<<"You can enter more files!";

                }
                else
                {
                        cout<<"You cannot add more files!";

                }

                if (response=="Done")
                {
                        cout<<"You have finished entering all files";
                }
                else
                {
                        file.push_back(response);
                }

        }
        while (response !="Done");
        bmp = image.toPixelMatrix();



        if (validBmp(response) != true)
        {
                cout<<"the file must be a 24 bit depth Windows BMP file, please ener the file name again";
        }
        if (validBmp(response) == true);

        {
                cout<<"The size of the file is "<< bmp.size() << " Pixel's height and " <<bmp[0].size() <<  " Pixel's width"<<endl;
        }
        if( number_of_input>0&&number_of_input<HOW_MANY_INPUT)
        {


        }
        else {
                cout<<"You cannot add more files!"<<endl;

        }
        
        vector<vector<vector<Pixel> > > result(vector<string>file);
        result.resize(file.size());
        for(x=0;x<)



        return 0;

}

//Function definitions...


//If the file that you provided is invalid(not a bmp file), there wil l be an error message.
//verify that the file opened was a valid image, if the input is bmp, return true, or else, return false.

//dimention test.
//You can also get an error message if your file is not in the same dimentions.
bool validBmp(string response)
{
        bool result;
        Bitmap image;
        image.open(response);
        result = image.isImage();
        int number_of_input;
        vector<vector<Pixel> >bmp;
        Pixel rgb;
        if (validBmp(response) != true)
        {
                cout<<"the file must be a 24 bit depth Windows BMP file, please ener the file name again";
        }
        if (validBmp(response) == true);
        { if(number_of_input>0&&number_of_input<HOW_MANY_INPUT)
                {
                        return true;

                }
                else{
                        return false;
                }
        }

        bmp = image.toPixelMatrix();
        if (validBmp(response) == true)
        {
                cout<<"The size of the file is "<< bmp.size() << " Pixel's height and " <<bmp[0].size() <<  " Pixel's width"<<endl;
        }
        const int height=bmp.size();
        if(height==0||bmp[0].size()==0)
        {
                return false;
        }
        const int width=bmp[0].size();
        for(int row=0;row<height;row++)
        {
                if(bmp[row].size()!=width)
                {

                        return false;
                }
                else
                {

                        return true;
                }
        }
        for(int cols=0;cols<width;cols++)
        {
                if( bmp[cols].size()!=height)
                {
                        return false;
                }
                else
                {
                        return true;
                }

        }

}




//The computer will composite all valid files that you entered regardless of size.
//All files that you input as responses will be combined together.
//By combining all files that you entered, the composite image will take the average calue of RGB.
vector< vector<Pixel> > composite(vector< vector< vector<Pixel> > > & Bmp)
{
        
        vector< vector<Pixel> >result;
       
        vector<vector<Pixel> >bmp;
        Pixel rgb;
        int z=Bmp.size();
        int r;
        int g;
        int b;
        int rnew;
        int gnew;
        int bnew;

        result.resize(Bmp[0].size());
        for(int x=0;x<result.size();x++)
        {
         result[x].resize(Bmp[0][0].size());
        }
        for (int row=0;row<Bmp.size();row++)
        {
                for (int cols=0;cols<Bmp[0].size();cols++)
                {

                        for(int number_of_input=0;number_of_input<HOW_MANY_INPUT;number_of_input++)

                        {
                               r= Bmp[number_of_input][row][cols].red;
                               g= Bmp[number_of_input][row][cols].green;
                               b= Bmp[number_of_input][row][cols].blue;
                               rnew=r+rnew;
                               gnew=g+gnew;
                               bnew=b+bnew;
                               

                        }
                      r=rnew/z;
                      g=gnew/z;
                      b=bnew/z;
                      rnew=0;
                      gnew=0;
                      bnew=0;
                    rgb.red=r;
                    rgb.green=g;
                    rgb.blue=b;
                   result[row][cols]=rgb;
                }     
             
              

        }

        return result;


}


//The computer will print out the progress when it is trying to combine the files.

//After computer finish the combining work, the "combined file" will save the file in another name.
void save(vector<vector<Pixel> >result)
{
        image.fromPixelMatrix(result);
        image.save("Composite-karenlin7788.bmp");


}


























