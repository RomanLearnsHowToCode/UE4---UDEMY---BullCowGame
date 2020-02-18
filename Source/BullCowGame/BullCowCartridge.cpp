
// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    
    Super::BeginPlay();

    FBullCowCount Count;
    PrintLine(TEXT("Bulls = %i, Cows = %i"), Count.Bulls, Count.Cows);
    


    //PrintLine(TEXT("%i"), FMath::RandRange(0,10));


    InitGame();

    //PrintLine(TEXT("The number of possible words is %i"),Words.Num()); // Debug line    
    //PrintLine(TEXT("The number of valid words is: %i"), GetValidWords(Words).Num());
    //PrintLine(TEXT("Valid Words -1 is: %i"),GetValidWords(Words).Num()-1);



    
    

    //SETTING UP THE GAME
    
}

void UBullCowCartridge::OnInput(const FString& PlayerInput) // referencing
{
    // REFERENCING VARIABLES

    // int32 a = 0;
    // int32& refa = a;




    if(bGameOver)
    {
        ClearScreen();
        InitGame();

    }
    else
    {
        ProcessGuess(PlayerInput);
    }
    
}

void UBullCowCartridge::InitGame() // SetupGame()
{

    PrintLine(TEXT("Welcome to Bull Cows!"));

    HiddenWord = GetValidWords(Words)[FMath::RandRange(0, GetValidWords(Words).Num() -1)];
    // SET LIVES
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("Character 1 of the hidden word is: %c"), HiddenWord[0]); // print "c"
    PrintLine(TEXT("Character 3 of the hidden word is: %c"), HiddenWord[2]);
    PrintLine(TEXT("Character 4 of the hidden word is: %c"), HiddenWord[3]);
    PrintLine(TEXT("You have got %i Lives: "), Lives);
    PrintLine(TEXT("\nPress Enter to continue"));
    PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord); // Debug line
}

 void UBullCowCartridge::EndGame()
 {
     bGameOver = true;
     PrintLine(TEXT("Press Enter to play again."));
 }

 void UBullCowCartridge::ProcessGuess(const FString& Guess)
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
    int32 Bulls, Cows; // syntactic sugar
    GetBullCows(Guess,Bulls,Cows);

    PrintLine(TEXT("You have %i Bulls and %i Cows"), Bulls, Cows);

 }

 bool UBullCowCartridge::IsIsogram(const FString& Word) const // CONST function
 {

    for (int32 Index = 0; Index < Word.Len(); Index++)
    {
        for (int32 Comparison =  Index + 1; Comparison < Word.Len(); Comparison++)
        {
            if (Word[Index] == Word[Comparison])
            {
                return false;
            }
            
        }

    }

    return true;
     
 }

TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString>& WordList) const
 {

    TArray<FString> ValidWords;


    for (FString Word : WordList)
    {   
        if(Word.Len() >=4 && Word.Len() <=8 && IsIsogram(Word))
        {
            ValidWords.Emplace(Word);
        }
        
    }
    return ValidWords;
 }

FBullCowCount UBullCowCartridge::GetBullCows(const FString& Guess, int32& BullCount, int32& CowCount) const // opravit zitra
 {
     BullCount = 0;
     CowCount = 0;

     // If the index of Guess is same as index of the Hidden Word, Bull Count++
     // If not a bull was it a cow? If yes CowCount++

    for (int32 GuessIndex = 0; GuessIndex < Guess.Len(); GuessIndex++)
    {
        if (Guess[GuessIndex] == HiddenWord[GuessIndex])
        {
            // BULL is a char on right space
            BullCount++;
            continue;
        }

    for (int32 HiddenIndex = 0; HiddenIndex < HiddenWord.Len(); HiddenIndex++)
    {
        if(Guess[GuessIndex] == HiddenWord[HiddenIndex])
        {
            // COWS are chars on the right spot
            CowCount++;
        }
    }
    }
 }

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