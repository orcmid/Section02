/* BlueCowGame.cpp 0.0.10             UTF-8                       2016-12-23 */
/* ------1---------2---------3---------4---------5---------6---------7------ */

#include <iostream>
#include <string>

#include "FBullCowGame.hpp"

void IntroduceGame(FBullCowGame NewGame);
void PlayGame(FBullCowGame CurrentGame);
bool SaysToPlayAgain();


int main() 
{   //TODO: Announce the program in some handy way.
    do  
    {
        FBullCowGame PlayerGame("isogram"); 
            // TODO: Eventually randomized choice
            // TODO: Protect against improper SecretWord
         IntroduceGame(PlayerGame);
         PlayGame(PlayerGame);
    } while (SaysToPlayAgain());

    return 0;
}

/* INTRODUCE THE GAME */
void IntroduceGame(FBullCowGame NewGame)
{
    std::cout
        << "\nWelcome to Bulls and Cows, a fun word game.\n"
        "Guess a secret word having "
        << NewGame.WordSize()
        << " letters, all different.\n";
    // TODO: Also indicate the number of tries allowed.
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


// PLAY A GAME UNTIL SOLVED OR ATTEMPTS EXHAUSTED



void PlayGame(FBullCowGame CurrentGame)
{
    std::string WordSpace = " ";
    for (unsigned i = 0; i < CurrentGame.WordSize(); i++)
        WordSpace += " ";
    
    while (1)
    {
        std::cout << std::endl;
        std::cout << " Your guess? ";

        do
        {
            std::string Guess = "";
            std::getline(std::cin, Guess);

            if (Guess.length() == 0)
            {   //           " Your guess? "
                std::cout << " Giving up after " << CurrentGame.WellFormedTries();
                if (CurrentGame.WellFormedTries() == 1)
                    std::cout << " guess.\n\n";
                else std::cout << " guesses.\n\n";

                return;
            }

            CurrentGame.SetGuess(Guess);

            if (!CurrentGame.IsOnlyLetters())
            {   //           " Your guess? "
                std::cout << "             Use exactly "
                    << CurrentGame.WordSize()
                    << " different alphabetical letters.\n"
                    << "  Try again: ";
                continue;
            }

            if (!CurrentGame.IsCorrectLength())
            {   //           " Your guess? "
                std::cout << "             Use exactly "
                    << CurrentGame.WordSize() << " different letters.\n"
                    << "  Try again: ";
                continue;
            }

            if (!CurrentGame.IsGoodIsogram())
            {   //           " Your guess? "
                std::cout << "             The letters must be all different.\n"
                    << "  Try again: ";
                continue;
            }
            else
            {
                //           " Your guess? "
                std::cout << "             " << WordSpace
                    << "Bulls: " << CurrentGame.Bulls()
                    << " Cows: " << CurrentGame.Cows() << std::endl;
            }

            if (CurrentGame.IsSecretGuessed())
            {
                //           " Your guess? "
                std::cout << " CONGRATULATIONS! You got it in "
                    << CurrentGame.WellFormedTries();

                if (CurrentGame.WellFormedTries() == 1)
                    std::cout << " guess.\n\n";
                else std::cout << " guesses.\n\n";

                return;
            }

            if (CurrentGame.SuggestedMaxTries() <= CurrentGame.WellFormedTries())
            {
                //           " Your guess? "
                std::cout << "      SORRY! " << WordSpace
                    << "You exhausted your "
                    << CurrentGame.SuggestedMaxTries()
                    << "-guess allowance.\n\n";

                return;
            }

        } while (!CurrentGame.IsGoodIsogram());

    }

}

/* ------1---------2---------3---------4---------5---------6---------7------ */

/* TODO:
     * Make a README.md for the GitHub folks
     * Consider letting the student choose the maximum number of letters,
       based on what there is in a directory of word choices.
     * NOT DOING NOW: A big hashtable dictionary which is randomly probed to
       get qualifying words.  I bet I can use the hash algorithm from Adv10.
       Then I need to get/make a dictionary of isograms.
     /


/* 0.0.10 2016-12-23-19:29 Get complete game, crying for refactoring.
   0.0.9 2016-12-23-11:52 Eliminate "using namespace", integrate the FBullCowGame
         class and introduce it in place of the previous use of strings.
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