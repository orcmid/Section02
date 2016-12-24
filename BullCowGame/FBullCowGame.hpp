#pragma once
/* BlueCowGame.hpp 0.0.5             UTF-8                        2016-12-24 */
/* ------1---------2---------3---------4---------5---------6---------7------ */

#include <string>

class FBullCowGame 
{  /* A model for the Bulls and Cows Game.
      This model has no side-effects beyond its encapsulated state,
      with no input-output and player interaction here. */

public:
    FBullCowGame(std::string SecretWord);
        /* Each instance has its own alpha isogram, with the word
           size determined automatically. 
           If the SecretWord is not an isogram, it is set to ""
           so that WordSize() == 0 and all guesses will fail.
           */

    unsigned WordSize();
        /* The size of the SecretWord.  
           0 if SecretWord was not a good isogram. */

    void SetGuess(std::string Guess);
         /* Enter a Guess to be the CurrentGuess() 
            until another is set.
            */

    std::string CurrentGuess();
        /* The latest SetGuess() parameter and the 
           empty string, "", before the first SetGuess(). */

    bool IsOnlyLetters();
         /* When there are only some alpha characters in 
            CurrentGuess() 
            */

    bool IsCorrectLength();
         /* When the alpha CurrentGuess() is of the correct length */

    bool IsGoodIsogram();
         /* When CurrentGuess() is a well-formed isogram of 
            correct length, whether or not a winner. 
            */

    bool IsSecretGuessed();
         /* CurrentGuess() matches the secret word, unless
            the secret word is improper (so WordSize() == 0)
            */

    unsigned Bulls();
        /* the number of Bulls when IsGoodIsogram(), else 0 */

    unsigned Cows();
        /* the number of Cows when IsGoodIsogram(), else 0 */

    unsigned GoodTries();
        /* the number of SetGuess() operations for which 
           IsGoodIsogram() was true.   
           */

    unsigned SuggestedMaxTries();
        /* the number of tries suggested as a limit for the 
           current SecretWord */
        /* TODO: Over-ride with a constructor parameter?
                 Estimate from SecretWord.length()?
                 */


private:
    std::string MySecret;
    std::string MyCurrentGuess;
    unsigned MyWellFormedTries;
    unsigned MySuggestedMaxTries;
        /* TODO: Completely hide this implementation info 
                 from the interface and contract?
                 */

};

/* ------1---------2---------3---------4---------5---------6---------7------ */

/* 0.0.5 2016-12-24-10:)4 Annotate the methods better.  Change WellFormedTries()
         to GoodTries().
   0.0.4 2016-12-23-17:43 Switch to SetGuess() and provide CurrentGuess().
         MyCows and MyBulls not needed in the state record.
   0.0.3 2016-12-22-22:31 Smooth and keep aligned with FBullCowGame.cpp
   0.0.2 2016-12-22-18:25 Complete privates, and smooth with FBullCowGame.cpp
   0.0.1 2016-12-22-14:58 Initial attempt at a pure model of the 
         situation as a challenge puzzle for Unreal Developer 
         Section02 Lecture 24 on Header Files as Contracts
         */

/*                      *** end of BullCowGame.hpp ***                       */
