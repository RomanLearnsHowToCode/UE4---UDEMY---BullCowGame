
// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"



void UBullCowCartridge::BeginPlay() // When the game starts
{
    
    Super::BeginPlay();
    PrintLine(TEXT("Bull & Cows are welcoming a new player!\nCome Closer and press TAB"));
    HiddenWord = TEXT("cake");
    
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
   // PrintLine(Input);

    if(Input == HiddenWord)
    {
        PrintLine(TEXT("THAT'S CORRECT"));

    } else
    {
        PrintLine(TEXT("WRONG"));
    }
     
}