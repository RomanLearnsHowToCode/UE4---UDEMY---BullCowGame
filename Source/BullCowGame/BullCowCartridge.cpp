
// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    
    Super::BeginPlay();
    InitGame();


    PrintLine(TEXT("Bull & Cows are welcoming a new player!\nCome Closer and press TAB\nThe hidden word has got: %s.\nIt is %i characters long"), *HiddenWord, HiddenWord.Len());
    PrintLine(FString::Printf(TEXT("The HiddenWord is: %s"), *HiddenWord));
    //SETTING UP THE GAME
    

    
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
        if (Input.Len() != HiddenWord.Len())
        {
          Lives--;   
          PrintLine(TEXT("Wrong lenght\nLives: " + Lives)); 
          
        } else
        {
           if(Lives == 0)
            PrintLine(TEXT("Game Over"));
        }
        
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