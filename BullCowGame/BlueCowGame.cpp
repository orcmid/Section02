/* BlueCowGame.cpp 0.0.9              UTF-8                       2016-12-** */
/* ------1---------2---------3---------4---------5---------6---------7------ */

#include <iostream>
#include <string>

const int WordSize = 5;

void IntroduceGame();
void PlayGame();
bool SaysToPlayAgain();


int main() 
{
    do  
    {
         IntroduceGame();
         PlayGame();
    } while (SaysToPlayAgain());

    return 0;
}

/* INTRODUCE THE GAME */
void IntroduceGame()
{
    std::cout
        << "\nWelcome to Bulls and Cows, a fun word game.\n"
           "Guess a secret word having " 
        << WordSize 
        << " letters, all different.\n";
    return;
}

// PLAY A GAME UNTIL SOLVED OR ATTEMPTS EXHAUSTED

std::string GetWellFormedGuess();

void PlayGame()
{
    const int MaxTries = 5;

    for (int tries = 1; tries <= MaxTries; tries++)
    {
        std::string Guess = GetWellFormedGuess();

        // Here is where we actually need to check the Guess

    }

    return;

}


// DETERMINE USER WANTS TO PLAY SOME MORE
bool SaysToPlayAgain()
{
    std::cout << "Do you want to Play again (y/N)? ";
    std::string Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 'y' || Response[0] == 'Y');
}


// GET A PROPER GUESS FROM THE PLAYER
std::string GetWellFormedGuess()
{
    /* The guess must have the correct number of letters without
       duplicates.  It might be checked against a word list, but not now.
       If the user chooses not to enter a guess, we return an empty string.
       */

    std::string Guess = "";
    std::cout << "\n Your guess? ";
    std::getline(std::cin, Guess);


    /*  I want the input-output to line up in a way where it is easy for the
        player to see what is happening.  There is some coupling between
        this and the responses to well-formed words of the correct length
        that happen elsewhere.  My goal is to have clear columnns where
        the user can easily review the previous well-formed guesses and
        consider how to craft additional guesses.
           One way might be to have the output messages be from a single
        (static) class where the alignments and such are easily reviewed
        in one place.  That would also allow for internationalization,
        I suppose.  (NOT NOW)
    */

    /* TODO: Failing verification of the input should not lead to
    return of a Guess.  We don't want it to count as a try until a
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


/* 0.0.9 2016-12-**-**:** Eliminate "using namespace" 
   0.0.8 2016-12-21-11:29 Abandoning stdio-dialog experiment.  I started a branch
         to see if I could do character level input-output, in versions 0.0.6-.7.
         Because fgetc echoes the characters, this does not give the necessary
         control.  I will continue with <iostream> and line input, finding an
         alternative way to keep things lined up for the player to review
         easily.  This version continues from 0.0.5 with edited adjustments.
   0.0.5 2016-12-20-15:42 Through Lesson 22 now.  The main skeleton is now
         mostly complete.  I will want to change the input-output to get
         each guess and the assessment on a single line.  It will be interesting
         if the abstraction levels can get this to work.
   0.0.4 2016-12-20-13:53 Lesson 18 alignment, with many notes.  I am 
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