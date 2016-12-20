/* BlueCowGame.cpp 0.0.2              UTF-8                        2016-12-19*/
/* ------1---------2---------3---------4---------5---------6---------7------ */

#include <iostream>
#include <string>

using namespace std;

const int WordSize = 5;

int main() 
{   
    // INTRODUCE THE GAME
    cout
        << "Welcome to Bulls and Cows, a fun word game.\n"
        << "Guess a secret word having " << WordSize << " letters,"
        << " all different.\n";

    // GET A GUESS FROM THE PLAYER
    string Guess = "";
    cout << "\n Your guess? ";
    getline(cin, Guess);

    // REPEAT THE GUESS BACK TO THEM
    cout << "\nYou guessed: " << Guess << endl;


    // compensate for using different Project template for this code:
    cout << "\nPress Enter to quit\n";
    cin.ignore();

    return 0;
}

/* TODO:
     * Make a README.md for the GitHub folks
     * Build the skeleton using explicit name qualification for now.
     * Consider letting the student choose the maximum number of letters,
       based on what there is in a directory of word choices.
     /


/* 0.0.3 2016-12-19-21:42 Lesson 17 alignment.  Using different nomenclature
         and WordSize spelling.  Got getline working.
   0.0.2 2016-12-19-10:14 Initial Build success.  Added hack to wait for
         input so console shell does not exit automatically.
   0.0.1 2016-12-19-09:50 Added Section02 Project to GitHub for Windows
         The solution, with the default .gitignore, is published to my
         GitHub Account.  Some touchups and review of what is kept in Git.
         The Section02-BullCow-GDD.txt file is maintained at project level.
   0.0.0 2016-12-19-09:16 Create Initial Setup for Orcmid's Favorite Style 
         There is a Git repository at the Section02 project level.
		 The initial templates is Visual C++ > General > Empty Project.
		 BlueCowGame is the single startup project of Section02.
         BlueCowGame.cpp is used instead of main.cpp ... just because.
		 Warning Level 4 (/W4) is set for the BlueCowGame C/C++ options
		 Unicode Character Set is selected for the Project
		 Editor settings are for soft tabs every 4 columns, and the horizontal
         ruler in line 2 is manually honored in my layouts.
         */

/*                   ***** end of BullCowGame.cpp *****                      */