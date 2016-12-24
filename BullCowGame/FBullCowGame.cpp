/* FBullCowGame.cpp 0.0.5            UTF-8                        2016-12-24 */
/* ------1---------2---------3---------4---------5---------6---------7------ */



#include "FBullCowGame.hpp"

#include <string>
#include <ctype.h>


FBullCowGame::FBullCowGame(std::string SecretWord)
{
    MySecret = SecretWord;
    MyCurrentGuess = SecretWord;
        // XXX: temporarily to check as a good isogram

    if (!IsGoodIsogram())
        MySecret = std::string("");

    MyCurrentGuess = std::string("");
    MyWellFormedTries = 0;
    MySuggestedMaxTries = 5;
        /* TODO: Find a better way to estimate this. */
}

unsigned FBullCowGame::WordSize()
{
    return MySecret.length();
}

void FBullCowGame::SetGuess(std::string Guess)
{
    MyCurrentGuess = Guess;
    if (IsGoodIsogram()) MyWellFormedTries++;
}

std::string FBullCowGame::CurrentGuess()
{
    return MyCurrentGuess;
}

bool FBullCowGame::IsOnlyLetters()
{
    if (WordSize() == 0) return false;

    for (unsigned i = 0; i < MyCurrentGuess.length(); i++)
    {
        if (!isalpha(MyCurrentGuess[i])) return false;
    }

    return true; 
  
}

bool FBullCowGame::IsCorrectLength()
{
    if (!IsOnlyLetters()) return false;

    return MyCurrentGuess.length() == MySecret.length();
}

bool FBullCowGame::IsGoodIsogram()
{   
    if (!IsCorrectLength()) return false;

    for (unsigned i = 1; i < MyCurrentGuess.length(); i++)
        /* Require CurrentGuess[i] to differ from all preceding 
           CurrentGuess[j], j < i
           */
        for (unsigned j = 0; j < i; j++)
            if (MyCurrentGuess[i] == MyCurrentGuess[j]) return false;

    return true;
}

bool FBullCowGame::IsSecretGuessed()
{
    if (!IsGoodIsogram()) return false;

    return Bulls() == MySecret.length();
}

unsigned FBullCowGame::Bulls()
{
    if (!IsGoodIsogram()) return 0;

    unsigned MyBulls = 0;

    for (unsigned i = 0; i < MySecret.length(); i++)
        if (MySecret[i] == MyCurrentGuess[i]) MyBulls++;

    return MyBulls;
}

unsigned FBullCowGame::Cows()
{
    if (!IsGoodIsogram()) return 0;

    unsigned MyCows = 0;

    for (unsigned i = 0; i < MySecret.length(); i++)
        for (unsigned j = 0; j < MyCurrentGuess.length(); j++)
            if (MySecret[i] == MyCurrentGuess[j]) MyCows++;

    return MyCows - Bulls();
}

unsigned FBullCowGame::GoodTries()
{
    return MyWellFormedTries;
}

unsigned FBullCowGame::SuggestedMaxTries()
{
    return MySuggestedMaxTries;
}


/* ------1---------2---------3---------4---------5---------6---------7------ */

/* 0.0.5 2016-12-24-10:31 Change WellFormedTries() to GoodTries(), scrub the
         method annotations. Add essential includes without assumptions about
         FBullCowGame.hpp.
   0.0.4 2016-12-23-17:44 Adjust method names, add CurrentGuess(), and stub
         out verification of SecretWord until IsGoodIsogram() is working.
   0.0.3 2016-12-23-08:06 Use Ladder of guards to get to IsGoodIsogram().
         All preconditions checked and all methods guarded regardless of
         the order in which they are checked by an user of the interface.
   0.0.2 2016-12-22-22:30 Clean up constructer, fix string.length() usage, 
         and add consistency checking.
   0.0.1 2016-12-22-18:24 Stub/Coordinate all FBullCowGame.hpp methods. 
         */


/*                    *** end of FBullCowGame.cpp ***                         */



