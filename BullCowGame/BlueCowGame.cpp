/* BlueCowGame.cpp 0.0.7              UTF-8                       2016-12-21 */
/* ------1---------2---------3---------4---------5---------6---------7------ */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>

using namespace std;

const int WORD_SIZE = 5;
const int MAX_WORD_SIZE = 10;

void IntroduceGame(int WordSize);
void PlayGame(int WordSize);
bool SaysToPlayAgain();
void SayGoodbye();


int main() 
{
    do  
    {
         IntroduceGame(WORD_SIZE);
         PlayGame(WORD_SIZE);
    } while (SaysToPlayAgain());
 
    SayGoodbye();
    return 0;
}

/* INTRODUCE THE GAME */
void IntroduceGame(int WordSize)
{
    fputs("Welcome to Bulls and Cows, a fun word game.\n"
          "Guess a secret word having ", stdout);
    char buffer[10];
    _itoa_s(WordSize, buffer, 9);
    fputs(buffer, stdout);
    fputs(" letters, all different.\n", stdout);
    return;
}


// DETERMINE USER WANTS TO PLAY SOME MORE
bool SaysToPlayAgain()
{
    fputs("\nDo you want to Play again (y/N)? ", stdout);

    char Response = (char) fgetc(stdin);

    char read = Response;
    while (read != '\n' && feof(stdin) == 0)
    {   // consume any additional characters up to EOL
        read = (char)fgetc(stdin);
    }

    fputc('\n', stdout);

    return (Response == 'y' || Response == 'Y');
}


// SAY GOODBYE
void SayGoodbye()
{
    fputs("\n", stdout);
    // TODO: provide more later when we have something more to say.
    return;
}


// PLAY A GAME UNTIL SOLVED OR ATTEMPTS EXHAUSTED

string GetWellFormedGuess(int WordSize);

void PlayGame(int WordSize)
{
    const int MaxTries = 5;
    /* TODO: determine from word information and let the
    user know the threshhold
    */

    for (int tries = 1; tries <= MaxTries; tries++)
    {
        string Guess = GetWellFormedGuess(WordSize);

        // Here is where we actually need to check the Guess

    }

    return;

}


// GET A PROPER GUESS FROM THE PLAYER
string GetWellFormedGuess(int WordSize)
{
    /* The guess must have the correct number of letters without
       duplicates.  It might be checked against a word list, but not now.
       If the user chooses not to enter a guess, we return an empty string.
       Another way would be to return a different string that is impossible
       to have entered.
       */

    char Guess[MAX_WORD_SIZE + 1] = { 0 };

    fputs("\n Your guess? ", stdout);
    for (int i = 0; i < WordSize; i++)
    {
        while (1)
        {
            Guess[i] = (char) tolower((char)fgetc(stdin));
            if (isalpha(Guess[i])) break;
            if (Guess[i] == '\0x08')
               {// backspace character
                i = (i > 0 ? i-1 : 0);
                Guess[i] = 0;
                continue;
               }
            /* else if (!isalpha(Guess[i]) */          
        }
    }
    


    /*  I would
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

    return string(Guess);
}



/* TODO:
     * Make a README.md for the GitHub folks
     * Consider letting the student choose the maximum number of letters,
       based on what there is in a directory of word choices.
     * NOT DOING NOW: A big hashtable dictionary which is randomly probed to
       get qualifying words.  I bet I can use the hash algorithm from Adv10.
       Then I need to get/make a dictionary of isograms.
     * Maybe say goodbye, provide information on the success, performance, etc.
     * Then do we need a startup also?
     /


/* 0.0.7 2016-12-21-11:09 Abandon this branch.  Since there is no way to have
         fgets not echo, the problems about backspacing, line ending, etc.
         is too much to attempt here.  I will design an interaction using
         line input that still has a clean output as well as confirmation
         of the input with any errors there might be.
            The master will be jumped up to 0.0.8 though.
   0.0.6 2016-12-20-20:18 Switch to stdio input/output in preparation for
         making a single-line arrangement.  Experiment with fgetc entry and
         controlling echo.
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