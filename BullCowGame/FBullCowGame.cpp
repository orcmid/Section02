/* FBullCowGame.cpp 0.0.3            UTF-8                        2016-12-23 */
/* ------1---------2---------3---------4---------5---------6---------7------ */

#include "FBullCowGame.hpp"

FBullCowGame::FBullCowGame(std::string SecretWord)
{
    MySecret = SecretWord;
    MyCurrentGuess = SecretWord;
    if (!IsGoodIsogram())
        MySecret = std::string("");
    MyCurrentGuess = std::string("");
    MyBulls = 0;
    MyCows = 0;
    MyWellFormedTries = 0;
    MySuggestedMaxTries = 7;
}

unsigned FBullCowGame::WordSize()
{
    return MySecret.length();
}

void FBullCowGame::CheckGuess(std::string Guess)
{
    MyCurrentGuess = Guess;
    if (IsGoodIsogram()) MyWellFormedTries++;
}

bool FBullCowGame::IsOnlyLetters()
{
    if (MyCurrentGuess.length() == 0) return false;

    return false; 
        // TODO: Add Logic
}

bool FBullCowGame::IsCorrectLength()
{
    if (!IsOnlyLetters()) return false;

    return MyCurrentGuess.length() == MySecret.length();
}

bool FBullCowGame::IsGoodIsogram()
{
    if (!IsCorrectLength()) return false;

    return false; 
        // TODO: Add Logic
}

bool FBullCowGame::IsSecretGuessed()
{
    if (!IsGoodIsogram()) return false;

    return Bulls() == MySecret.length();
}

unsigned FBullCowGame::Bulls()
{
    if (!IsGoodIsogram()) return 0;

    return MyBulls;
        // Needs to actually figure it out, based on good isogram

}

unsigned FBullCowGame::Cows()
{
    if (!IsGoodIsogram()) return 0;
    return MyCows;
        // Likewise, nice to get Bulls and Cows in one pass but no biggie.
}

unsigned FBullCowGame::WellFormedTries()
{
    return MyWellFormedTries;
}

unsigned FBullCowGame::SuggestedMaxTries()
{
    return MySuggestedMaxTries;
}


/* ------1---------2---------3---------4---------5---------6---------7------ */

/* 0.0.3 2016-12-23-08:06 Use Ladder of guards to get to IsGoodIsogram().
         All preconditions checked and all methods guarded regardless of
         the order in which they are checked by an user of the interface.
   0.0.2 2016-12-22-22:30 Clean up constructer, fix string.length() usage, 
         and add consistency checking.
   0.0.1 2016-12-22-18:24 Stub/Coordinate all FBullCowGame.hpp methods. 
         */


/*        *** end of FBullCowGame.cpp ***                  */



