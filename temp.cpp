#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
 int x = 0, y=1,z,i, staue=0;;
 ifstream infile("string.txt");
 string temp;
 while (getline(infile, temp))
 {
  
  i = 0;
  int len = temp.length();
  while (len--)
  {
   if (temp[i] == 'i')
   {
    if (staue != 0)
    {
     staue = 4;
    }
    else
     staue = 1;
   }
   if (temp[i] == 'f')
   {
    if (staue == 1)
     staue = 2;
    else
     staue = 4;
   }
   if (temp[i] != 'i'&&temp[i] != 'f'&&temp[i] > 'a'&&temp[i] < 'z')
    staue = 3;
   if (temp[i] == ' '&&temp[i-1]!=' '||len==0)
   {
    if (staue == 2)
    {
     cout << "IF  " << "      (" << y << "," << i - 2 << ")" << endl;
     staue = 0;
    }
    else
    {
     i--;
     z = 0;
     cout << "ID(";
     while (temp[i] != ' '&&i!=0)
     {
      i--;
     }
     if (i != 0)
      i++;
     z = i;
     while (temp[i] != ' ')
     {
      cout << temp[i];
      i++;
     }
     cout << ")" << "   " << "(" << y << "," << z << ")" << endl;
     staue = 0;
    }
   }
   i++;
  }
  y++;
 }
 system("pause");
 return 0;
}
