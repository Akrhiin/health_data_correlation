
/*----------------------------------------------------------------------------------------------------------------------
Michael Pace - Program #2
Date last modified: 09.19.2021
Summary: This program takes user input for three sets of (x,y) pairs and calculated hte correlation coefficient
    and the strength of association. The correlation coefficient (r) states roughly how correlated a data set is based
    on the correlation between the x and y values.
----------------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------
INPUT(from keyboard, stdin):
    Three sets of real (x,y) pairs, for example:
        98    15  is a valid input from (98, 15)

OUTPUT(to console, stdout):
    the correlation coefficient, the strength of association, and whether the association is "strong", "moderate",
    or "weak.
----------------------------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <cstdio>
#include <cmath>

#include "vitalSigns.h"

// declare variables ---------------------------------------------------------------------------------------------------

int main() {

	// DECLARE CONSTANTS
	const short								// ----- CONSTANT declarations -----
            N = 3;                          // number of (x,y) pairs
	
	const double STRONG = 0.75;			    // value to measure strength of association
    const float TOLERANCE = 0.000005;       // tolerance of strength of association
	
	
	// DECLARE VARIABLES
	double									// ----- VARIABLE declarations -----
	x1, y1,									// first  (x,y) pair
	x2, y2,									// second (x,y) pair
	x3, y3;									// third  (x,y) pair

    double
    firstHalfN,                             // first half of numerator --> nExiyi
    secondHalfN,                            // second half of numerator --> ExiEyi
    numerator;                              // numerator values

    double
    firstQuarterD,                          // first quarter of denominator --> nExi^2
    secondQuarterD,                         // second quarter of denominator --> (Exi)^2
    thirdQuarterD,                          // third quarter of denominator --> nEyi^2
    fourthQuarterD,                         // fourth quarter of denominator --> (Eyi)^2
    firstHalfD,                             // first half of denominator --> first quarter - second quarter
    secondHalfD,                            // second half of denominator --> third quarter - fourth quarter
    firstHalfDRoot,                         // square root of first half of denominator
    secondHalfDRoot,                        // square root of second half of denominator
    denominator;                            // denominator values

    double r;                               // equation result
    double r2;                              // strength of association

    double
    Exi,                                    // sum of x values
    Eyi,                                    // sum of y values
    Exi2,                                   // sum of squares of x values
    Eyi2,                                   // sum of squares of y values
    Exiyi;                                  // sum of products of corresponding x and y values

// define (x,y) pairs --------------------------------------------------------------------------------------------------

    // print Title
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Finding Correlation Between Temperature and Respiratory Rate" << std::endl;

    // define Variable (x,y) Pairs
	x1 = getBodyTemperature_F();
	y1 = getRespirationRate_BPM();
    
    printf("(x,y) pair 1:  (%6.2f, %6.2f)\n", x1, y1);
    std::cout << std::endl;

    x2 = getBodyTemperature_F();
    y2 = getRespirationRate_BPM();

    printf("(x,y) pair 2:  (%6.2f, %6.2f)\n", x2, y2);
    std::cout << std::endl;

    x3 = getBodyTemperature_F();
    y3 = getRespirationRate_BPM();

    printf("(x,y) pair 3:  (%6.2f, %6.2f)\n", x3, y3);
    std::cout << std::endl;

// correlation calculation ---------------------------------------------------------------------------------------------

    // define function variables
    Exi = x1 + x2 + x3;
    Eyi = y1 + y2 + y3;
    Exi2 = (x1 * x1) + (x2 * x2) + (x3 * x3);
    Eyi2 = (y1 * y1) + (y2 * y2) + (y3 * y3);
    Exiyi = (x1 * y1) + (x2 * y2) + (x3 * y3);

    // calculate numerator
    firstHalfN = N * Exiyi;
    secondHalfN = Exi * Eyi;
    numerator = firstHalfN - secondHalfN;

    // calculate denominator
    firstQuarterD = N * Exi2;
    secondQuarterD = Exi * Exi;
    thirdQuarterD = N * Eyi2;
    fourthQuarterD = Eyi * Eyi;

    firstHalfD = firstQuarterD - secondQuarterD;
    secondHalfD = thirdQuarterD - fourthQuarterD;
    firstHalfDRoot = sqrt(firstHalfD);
    secondHalfDRoot = sqrt(secondHalfD);
    denominator = firstHalfDRoot * secondHalfDRoot;

    if (denominator == 0 || firstHalfD == 0 || secondHalfD == 0) {
        std::cout << "Current input leads to error, please enter real numbers." << std::endl;
        return 1;
    }

    // calculate r
    r = numerator / denominator;
    r2 = r * r;

    std::cout << r << std::endl;

// strength of association ---------------------------------------------------------------------------------------------

    if (r2 >= 0.75 || fabs(r2 - STRONG) < TOLERANCE) {
        std::cout << "Strongly Related" << std::endl;
        std::cout << std::endl;
        //Strong
    } else if (r2 > 0.5) {
        std::cout << "Moderately Related" << std::endl;
        std::cout << std::endl;
        //Moderate
    } else {
        std::cout << "Weakly Related" << std::endl;
        std::cout << std::endl;
        //Weak
    }

    std::cout << "Done." << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
	return 0;
	
} // end main()
