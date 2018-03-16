// #include <3D/threeDPoint.h>
#include "include/3D/threeDObject.h"
#include "include/3D/threeDInput.h"
#include "include/2D/twoDProjectionView.h"
#include "include/2D/twoDProjection.h"
#include "include/2D/twoDInput.h"
#include <iostream>

int maein()
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

        twoDInput frontIn,topIn,sideIn;

        std::cout<< "Enter data for front view"<<std::endl;
        //frontIn.inputPoints();
        //frontIn.inputEdges();
        frontIn.inputData();
        twoDProjection frontView;
        frontView.add_pointSet(frontIn.getPoints());
        frontView.add_edgeSet(frontIn.getEdges());

        std::cout<< "Enter data for top view"<<std::endl;
        //topIn.inputPoints();
        //topIn.inputEdges();
        topIn.inputData();
        twoDProjection topView;
        topView.add_pointSet(topIn.getPoints());
        topView.add_edgeSet(topIn.getEdges());

        twoDProjection sideView;
        twoDProjection * sideViewPointer;
        if (number_of_views==3)
        {
            std::cout<< "Enter data for side view"<<std::endl;
            //sideIn.inputPoints();
            //sideIn.inputEdges();
            sideIn.inputData();
            sideView.add_pointSet(sideIn.getPoints());
            sideView.add_edgeSet(sideIn.getEdges());
            sideViewPointer = &sideView;
        }
        else
        {
            sideViewPointer = NULL;
        }

        twoDProjectionView projectionDrawing(& frontView,& topView, sideViewPointer);
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