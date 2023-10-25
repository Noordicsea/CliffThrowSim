#include <iostream>
#include <string>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


using namespace std;

int main()
{
    char choice;

    do {
        // Variable declaration
        double gravity = -9.8;
        double XvelocityInit, YvelocityInit, height, distanceFromEdge;

        // User input
        cout << "Please enter initial X velocity: ";
        cin >> XvelocityInit;

        cout << "Please enter initial Y velocity (This is not gravity.): ";
        cin >> YvelocityInit;

        cout << "What is the hight of the cliff?";
        cin >> height;

        cout << "How far from the edge of the cliff are you (in m): ";
        cin >> distanceFromEdge;

        // Calculate the things.
        double posYInit = height;
        double posXInit = distanceFromEdge;

        cout << "The initial position of X and Y are: (" << distanceFromEdge << " , " << height << " )\n";
        cout << "The components of the initial velocity of the stone are: (" << XvelocityInit << " , " << YvelocityInit << " )\n";

        // Calculate time taken for stone to reach the ground
        double a = 0.5 * gravity;  // Using the positive value here, hence the 0.5*gravity.
        double b = YvelocityInit;
        double c = posYInit;

        double discriminant = b * b - 4 * a * c;

        if (discriminant >= 0) {
            double t1 = (-b + sqrt(discriminant)) / (2 * a);
            double t2 = (-b - sqrt(discriminant)) / (2 * a);

            double t = (t1 > 0) ? t1 : t2;

            cout << "Time taken for the stone to reach the ground: " << t << " seconds.\n";

            // Calculate final Y velocity
            double finalYVelocity = YvelocityInit + gravity * t;

            // Resultant velocity
            double resultantVelocity = sqrt(XvelocityInit * XvelocityInit + finalYVelocity * finalYVelocity);

            // Angle of impact with respect to the horizontal
            double impactAngle = atan2(finalYVelocity, XvelocityInit) * (180.0 / M_PI);

            cout << "Speed of impact: " << resultantVelocity << " m/s\n";
            cout << "Angle of impact with respect to the horizontal: " << impactAngle << " degrees.\n";

        }
        else {
            cout << "The stone won't hit the ground based on the given input.\n";
        }

        cout << "Would you like to continue? Press 'y' to continue or 'n' to exit: ";
        cin >> choice;
        cin.ignore();  // Clear the buffer

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
