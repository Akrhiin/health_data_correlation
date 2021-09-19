
#include <iostream>
#include <chrono>
#include <thread>

#include "vitalSigns.h"

// -------------------\
//  getBodyTemperature \
// --------------------------------------------------------------
// IN: (no arguments)
// RETURNS: simulated body temperature in degrees F
// --------------------------------------------------------------
double getBodyTemperature_F(void) {
    double temp;    // Temperature

//  manual data entry
    std::cout << "Enter a body temp(F): ";
    std::cin >> temp;

//  random data entry
//    srand(time(0));
//    temp =  96 + (rand() % 9);   // generate random value for temperature
//    std::this_thread::sleep_for(std::chrono::milliseconds(700));
    
    return temp;
}       // Get User Input for Temperature

// -----------------------\
//  getRespirationRate_BPM \
// --------------------------------------------------------------
// IN: (no arguments)
// RETURNS: simulated respiration rate
// --------------------------------------------------------------
double getRespirationRate_BPM(void) {
    double resp;    // Respiration Rate

//  manual data entry
    std::cout << "Enter a respiration rate(BPM): ";
    std::cin >> resp;

//  random data entry
//    srand(time(0));
//    resp = 10 + (rand() % 14);    // generate random value for respiratory rate
//    std::this_thread::sleep_for(std::chrono::milliseconds(700));

    return resp;
}       // Get User Input for Respiration Rate

