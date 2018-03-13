#include <fstream>
#include <iostream>
using namespace std;

int main() {
	cout<<"hello";
   ifstream ifs( "unitcube_3d.txt" );       // note no mode needed
   if ( ! ifs.is_open() ) {                 
      cout <<" Failed to open" << endl;
   }
   else {
      cout <<"Opened OK" << endl;
   }
   return 0;
}