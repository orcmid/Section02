/* BlueCowGame.cpp 0.0.4              UTF-8                       2016-12-20 */
/* ------1---------2---------3---------4---------5---------6---------7------ */

#include <iostream>
#include <string>

using namespace std;

const int WordSize = 5;



void IntroduceGame();
string GetValidGuess();

int main() 
{
    IntroduceGame();

    string Guess = GetValidGuess();

    // compensate for using different Project template for this code:
    cout << "\nPress Enter to quit\n";
    cin.ignore();

    return 0;
}

/* INTRODUCE THE GAME */
void IntroduceGame()
{
    cout
        << "Welcome to Bulls and Cows, a fun word game.\n"
        << "Guess a secret word having " << WordSize << " letters,"
        << " all different.\n";
    return;
}

// GET A PROPER GUESS FROM THE PLAYER
   /* The guess must have the correct number of letters without
      duplicates.  It might be checked against a word list, but not now. 
      If the user chooses not to enter a guess, we return an empty string.
      Another way would be to return a different string that is impossible
      to have entered. 
      */

string GetValidGuess()
{
    string Guess = "";
    cout << "\n Your guess? ";
    getline(cin, Guess);
        // verification and whether to quit or not needed here.
    cout << "\nYou guessed: " << Guess << endl;

        /* We don't need this, but it is not clear whether
           the checking can be here or has to follow.  I would
           like it all on one line somehow, so guesses and Bulls+Cows are
           in an easy-to-use column.
           This changes the abstraction and coupling between getting a guess
           and reporting its strength.
           */
        /* TODO: Failing verification of the input should not lead to a
                 return.  We don't want it to count as a try until a 
                 good try is returned, so that will be handled in the
                 bounded loop, once we know how to limit guesses based
                 on word size. 
                 */

    return Guess;
}


/* TODO:
     * Make a README.md for the GitHub folks
     * Consider letting the student choose the maximum number of letters,
       based on what there is in a directory of word choices.
     * NOT DOING NOW: A big hashtable dictionary which is randomly probed to
       get qualifying words.  I bet I can use the hash algorithm from Adv10.
       Then I need to get/make a dictionary of isograms.
     /


/* 0.0.4 2016-12-20-13:53 Lesson 18 alignment, with many notes.  I am 
         deviating, but not by much.
   0.0.3 2016-12-19-21:42 Lesson 17 alignment.  Using different nomenclature
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