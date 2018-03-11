// #include <3D/threeDPoint.h>
#include <3D/threeDObject.h>
#include <3D/threeDInput.h>
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
        std::cout << "You have choosed 2D" << std::endl;
    }
    else
    {
        std::cout << "You have choosed 3D" << std::endl;

        // Construct the three dimensional object
        threeDObject object;

        // Take input for points
        threeDInput threeDin;
        threeDin.inputPoints ();
        threeDin.inputEdges ();
    }
}