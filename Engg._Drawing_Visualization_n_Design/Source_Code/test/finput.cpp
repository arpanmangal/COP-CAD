#include <fstream>
#include <iostream>
using namespace std;

int main() {
	cout<<"hello";
   ifstream ifs;
   ifs.open( "unitcube.txt" ,ios::in);  
   char c;
   ifs>>c;
   cout<<c;     // note no mode needed
   if ( !ifs.is_open() ) {                 
      cout <<" Failed to open" << endl;
   }
   else {
      cout <<"Opened OK" << endl;
   }
   return 0;
}