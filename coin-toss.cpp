// Brianna Murray 
/*
 This is a program that asks the user for the name of an output file and how many times a coin
 should be tossed, then writes a numbered list of the toss results followed by a summary that
 includes both the number of tosses that were heads/tails and the percentage of tosses that
 were heads/tails.
 */

#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;

int coinToss(); // Coin toss function.
void percentResults(int heads, int tails, int flipNumber, ofstream & outputFile); // Percentage calculator / display function.

int main()
{
    // Set random seed

    double seed = time(0);
    srand(seed);

    // Assign variables

    string filename;
    int flipNumber, coin, heads = 0, tails = 0;

    cout << "Enter the name of the output file. " << endl;
    cin >> filename; // Prompt for file name

    cout << endl << "How many times would you like to see the coin tossed? ";
    cin >> flipNumber; // Prompt for number of coin flips

    ofstream outputFile(filename); // Open output file

    for(int i = 1; i <= flipNumber; i++) // Set loop for iterations of flips
    {
        coin = coinToss(); // Get coin value

        if(coin == 1) // For heads
        {
            outputFile << "Toss #" << i << ": Heads" << endl;
            heads++; // Increase counter
        }
        else // For tails
        {
            outputFile << "Toss #" << i << ": Tails" << endl;
            tails++; // Increase counter
        }
    }

    percentResults(heads, tails, flipNumber, outputFile); // Call percent function

    cout << endl << endl << "Data written to the file " << filename << endl << "Goodbye!" << endl; // Closing cout statement

    outputFile.close(); // Close output file.

} // End of main

/*
 This function does not take in any input, however it returns an int value.
 It creates a random coin value and returns the value back to where it was
 called from.
 */

int coinToss()
{
    int coin; // Coin variable

    coin = (rand() % 2) + 1; // Generate coin value
    return coin;

} // End of coinToss function

/*
 This function does not return any values however it does take in three ints
 and one ofstream. This function calculates the percentage values of the
 amount of heads and tails flipped. Then sends statements to the outputFile.
 */

void percentResults(int heads, int tails, int flipNumber, ofstream & outputFile)
{
    double headPercentage = (static_cast<double>(heads) / flipNumber) * 100; // Head percentage

    double tailPercentage = (static_cast<double>(tails) / flipNumber) * 100; // Tail percentage

    outputFile << endl << heads << " of the " << setprecision(1) << fixed << flipNumber << " tosses were heads or " << headPercentage << " percent."; // Head display
    outputFile << endl << tails << " of the " << setprecision(1) << fixed << flipNumber << " tosses were tails or " << tailPercentage << " percent."; // Tail display

} // End of percentResults function
