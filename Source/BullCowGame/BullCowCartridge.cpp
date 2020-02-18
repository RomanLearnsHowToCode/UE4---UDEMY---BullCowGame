
// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    
    Super::BeginPlay();

    InitGame();


    PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord); // Debug line

    //SETTING UP THE GAME
    
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if(bGameOver)
    {
        ClearScreen();
        InitGame();

    }
    else
    {
        ProcessGuess(Input);
    }
    
}

void UBullCowCartridge::InitGame() // SetupGame()
{

    PrintLine(TEXT("Welcome to Bull Cows!"));

    HiddenWord = TEXT("cakes");
    // SET LIVES
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have got %i Lives: "), Lives);
    PrintLine(TEXT("\nPress Enter to continue"));
    PrintLine(TEXT("Character 1 of the hidden word is: %c"), HiddenWord[0]); // print "c"

    // const TCHAR HW[] = TEXT("plums"); 
    // PrintLine(TEXT("The 4th character of HW is: %c"), HW[3]); // prints "m"

    // WHILE LOOP

    // int32 i = 0;
    // while (i <=10)
    // {
    //     PrintLine(TEXT("%i"), i);
    //     i++;
    // }

    // FOR LOOP

    // for (int32 i = 0; i<10; i++)
    // {
    //     PrintLine(TEXT("%i"),i);
    // }

    // DO WHILE LOOP

    // int32 i = 0;
    // do
    // {
    //     PrintLine(TEXT("%i"), i);
    //     i++;
    // } while (i < 2);
    


}

 void UBullCowCartridge::EndGame()
 {
     bGameOver = true;
     PrintLine(TEXT("Press Enter to play again."));
 }

 void UBullCowCartridge::ProcessGuess(FString Guess)
 {
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("You have won!"));
        EndGame();
        return; // early return
    }
     
    // Check Right Number of Characters

    if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("The hidden word is %i letters long"), HiddenWord.Len());
        PrintLine(TEXT("SOrry, Try guessing agaiN!\nYou have %i lives remaining"), Lives);
    }

    //Check If Isogram
    if (!IsIsogram(Guess))
    {
         PrintLine(TEXT("No repeating letter, guess again"));
         return;
     }

    // Remove life
    --Lives;
    PrintLine(TEXT("Youh have lost a life!"));

    if (Lives <= 0)
    {
        ClearScreen();
        PrintLine(TEXT("You have no lives left"));
        PrintLine(TEXT("The hidden word was: %s"), *HiddenWord);
        EndGame();
        return;                
    }

    // Show player the Bulls and Cows
 }

 bool UBullCowCartridge::IsIsogram(FString Word) const // CONST function
 {
    //  For each letter
    //  Start at element [0]
    //  Compare against the next letter.
    //  Until we reach the end of an array [Word.Len() -1]
    //  if any letter are same return false

    for (int32 Index = 0; Index < Word.Len(); Index++)
    {
        PrintLine(TEXT("%c"), Word[Index]);
    }
    

    return true;
 }