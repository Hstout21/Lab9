/**
 *   @file: Lab9.cc
 * @author: Hunter Stout
 *   @date: 10/22/2021
 *  @brief: 30 Temperature counter.
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

/**
 * minTemp - finds minimum temperature.
 * @param num - Number from array.
 * @param n2 - New minimum number.
 * @return - New minimum number.
 */
int minTemp (int num, int min);

/**
 * maxTemp - finds maximum temperature.
 * @param num - Number from array.
 * @param max - New maximum number.
 * @return - New maximum number.
 */
int maxTemp (int num, int max);

/**
 * avgTemp - finds average of all temperatures.
 * @param num - Number from array.
 * @param counter - counts numbers entered into array.
 * @param avg - finds average of total sum.
 */
void avgTemp (int num, int &counter, double &avg);

//Main Function.
int main() {

    //Main file instream.
    ifstream inStream;
    //Array for temperatures.
    int arr[30];
    //Main integers, I for the array, min & max for lowest & highest, num & counter for functions.
    int i = 0, min = 1000, max = -1000, num, counter = 0;
    //Average could have decimal so we made it a double.
    double avg = 0.0;

    //Opening the main instream.
    inStream.open("athens_low_temps.txt");

        //Instream fail check.
        if (inStream.fail()) {
            cout << " " << endl;
            cout << "Error we could not locate this file. Try again" << endl;
            exit (0);
        }

    //Gets the first integer from file before the loop.
    inStream >> arr[i];

        //Loop to run each integer in the file.
        while (i != 30) {

            //Turns current array integer into num.
            num = arr[i];
            //Checks min of array.
            min = minTemp(num, min);
            //Checks max of array.
            max = maxTemp(num, max);
            //Totals sum of array.
            avgTemp(num, counter, avg);
            //Counts array placeholder.
            i++;
            //Grabs new integer from inside the loop.
            inStream >> arr[i];
        }
    //Close instream.
    inStream.close();

    //Main output messages.
    cout << fixed << setprecision(1) << endl;
    cout << "Minimum Temperature: " << min << endl;
    cout << "Maximum Temperature: " << max << endl;
    cout << "Average Temperature: " << avg << endl;

	return 0;
}

//Function for finding minimum temperature.
int minTemp (int num, int min) {

    //Logic for checking if number is smaller or larger.
    if (num < min) {
        min = num;
    }
    else {
        min = min;
    }
//Returns new min.
return (min);
}

//Function for finding maximum temperature.
int maxTemp (int num, int max) {

    //Logic for checking if number is smaller or larger.
    if (num >= max) {
        max = num;
    }
    else {
        max = max;
    }
//Returns new max.
return (max);
}

//Function for finding sum of array.
void avgTemp (int num, int &counter, double &avg) {
    //Finds sum.
    avg = avg + num;
    //Counts integers entered.
    counter++;
        //Finds average once 30 temperatures are entered.
        if (counter == 30) {
            avg = avg / 30;
        }
}