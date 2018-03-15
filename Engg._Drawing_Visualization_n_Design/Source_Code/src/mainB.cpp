// #include <3D/threeDPoint.h>
#include <3D/threeDObject.h>
#include <3D/threeDInput.h>
#include <2D/twoDProjectionView.h>
#include <2D/twoDProjection.h>
#include <2D/twoDInput.h>
#include <iostream>

int main()
{
    int mode;
    std::cout << "Enter Mode: ";
    std::cin >> mode;

    while (mode != 2 && mode != 3)
    {
        std::cout << "Please try again: ";
        std::cin >> mode;
    }

    if (mode == 2)
    {   
        int number_of_views;
        std::cout << "You have choosed 2D" << std::endl;
        std::cout<< "Enter how many views you wish to enter(2 or 3)" <<std::endl;
        std::cin>>number_of_views;

        twoDInput reader = twoDInput();
        twoDProjectionView projectionDrawing = *reader.getProjectionDrawing(number_of_views);
        std::cout<<"Success at creating 2D ProjectionView";

        threeDObject my3d = *projectionDrawing.create3Dmodel();
        my3d.printer();
    }
    else
    {
        std::cout << "You have choosed 3D" << std::endl;

        // Construct the three dimensional object
        threeDObject object;

        // Take input for points
        threeDInput threeDin;
        //threeDin.inputPoints();
        //threeDin.inputEdges();
        threeDin.inputData();
        // add the point set and edge set to the object
        threeDin.get3DObject(&object);

        // Generate 2-D projection
        twoDProjection * projection = object.genProjection(1);
        projection->printer();
    }
}