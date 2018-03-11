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
        twoDProjection frontview,topview,sideview;
        std::cout<< "Enter how many views you wish to enter(2 or 3)" <<std::endl;
        std::cin>>number_of_views;

        twoDInput frontIn,topIn,backIn;

        std::cout<< "Enter data for front view"<<std::endl;
        frontIn.inputPoints();
        frontIn.inputEdges();

        std::cout<< "Enter data for top view"<<std::endl;
        topIn.inputPoints();
        topIn.inputEdges();

        if (number_of_views==3)
        {
            std::cout<< "Enter data for side view"<<std::endl;
            sideIn.inputPoints();
            sideIn.inputEdges();
        }

        twoDProjection *frontview = new frontview(frontIn)
    }
    else
    {
        std::cout << "You have choosed 3D" << std::endl;

        // Construct the three dimensional object
        threeDObject object;

        // Take input for points
        threeDInput threeDin;
        threeDin.inputPoints();
        threeDin.inputEdges();
    }
}