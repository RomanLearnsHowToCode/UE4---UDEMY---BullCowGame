
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
        {
            if (Input == HiddenWord)
            {
                PrintLine(TEXT("You have won!"));
                EndGame();
            }
            else
            {
                --Lives;
                PrintLine(TEXT("Youh have lost a life!"));
                if (Lives > 0)
                {

                
                    if (Input.Len() != HiddenWord.Len())
                    {
                    PrintLine(TEXT("SOrry, Try guessing agaiN!\nYou have %i lives remaining"), Lives);
                    }
  
                }
                else
                {
                    PrintLine(TEXT("You have no lives left"));
                    EndGame();
                }
                
            }
            
        }
    }
    
}

void UBullCowCartridge::InitGame()
{
    PrintLine(TEXT("Welcome to Bull Cows!"));
    

    HiddenWord = TEXT("cakessss");
    // SET LIVES
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have got %i Lives: "), Lives);
    PrintLine(TEXT("Press Enter to continue"));


}

 void UBullCowCartridge::EndGame()
 {
     bGameOver = true;
     PrintLine(TEXT("Press Enter to play again."));
 }