
// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"



void UBullCowCartridge::BeginPlay() // When the game starts
{
    
    Super::BeginPlay();
    PrintLine(TEXT("Bull & Cows are welcoming a new player!\nCome Closer and press TAB"));
    //SETTING UP THE GAME
    InitGame();

    
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
   // PrintLine(Input);

   //Checking PLayerGuess

    if(Input == HiddenWord)
    {
        PrintLine(TEXT("THAT'S CORRECT"));

    } else
    {
        PrintLine(TEXT("WRONG"));
        Lives--;
        PrintLine(TEXT("Lives :" + Lives));

       
    }
     


     // remove life
     // check if its Isogram
     // Check right number char


    // Check if Lives > 0
    // If Yes Guess Again
    //Show lives left
    // If No Show GameOver and HiddenWord?
    // Prompt to play again, Press Enter to play again?
    // Check player Input

}

void UBullCowCartridge::InitGame()
{
    HiddenWord = TEXT("cake");
    // SET LIVES
    Lives = 5;


}