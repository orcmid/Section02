#pragma once
/* BlueCowGame.hpp 0.0.4             UTF-8                        2016-12-23 */
/* ------1---------2---------3---------4---------5---------6---------7------ */

#include <string>

class FBullCowGame 
{  /* A model for the Bulls and Cows Game.
      This model has no side-effects beyond its encapsulated state,
      so there is no input-output here. */

public:
    FBullCowGame(std::string SecretWord);
        /* Each instance has its own alpha isogram, with the word
           size determined automatically. 
           If the SecretWord is not an isogram, it is set to "",
           failing all guesses, and having WordSize() == 0.
           */

    unsigned WordSize();
        /* The size of the SecretWord.  0 if SecretWord was improper. */

    void SetGuess(std::string Guess);
         /* Enter a Guess */

    std::string CurrentGuess();
        /* The last SetGuess value or else the empty string */

    bool IsOnlyLetters();
         /* When there are only alpha characters in the current guess*/

    bool IsCorrectLength();
         /* When the alpha string is of the correct length */

    bool IsGoodIsogram();
         /* When the guess is a well-formed isogram of correct length */

    bool IsSecretGuessed();
         /* The guess is correct (WordSize of Bulls) */

    unsigned Bulls();
        /* the number of Bulls in the current Guess, or 0 */

    unsigned Cows();
        /* the number of Cows in the current Guess, or 0 */

    unsigned WellFormedTries();
        /* the number of guesses for which IsGoodIsogram was true */

    unsigned SuggestedMaxTries();
        /* the number of tries suggested as a limit for the 
           current SecretWord */
        // TODO: Over-ride with a constructor parameter?

private:
    std::string MySecret;
    std::string MyCurrentGuess;
    unsigned MyWellFormedTries;
    unsigned MySuggestedMaxTries;

        // TODO: Completely hide the implementation?

};

/* ------1---------2---------3---------4---------5---------6---------7------ */

/* 0.0.4 2016-12-23-17:43 Switch to SetGuess() and provide CurrentGuess().
         MyCows and MyBulls not needed in the state record.
   0.0.3 2016-12-22-22:31 Smooth and keep aligned with FBullCowGame.cpp
   0.0.2 2016-12-22-18:25 Complete privates, and smooth with FBullCowGame.cpp
   0.0.1 2016-12-22-14:58 Initial attempt at a pure model of the 
         situation as a challenge puzzle for Unreal Developer 
         Section02 Lecture 24 on Header Files as Contracts
         */

/*                      *** end of BullCowGame.hpp ***                       */
