//
//  main.cpp
//  BlackJack
//
//  Created by Loren Bland on 10/21/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#include <iostream>
#include "BlackJackGame.h"


int main(int argc, const char * argv[])
{
    
    BlackJackGame::BlackJackGame blackJackGame;
    BlackJackGame::DeckPtr deck = blackJackGame.GetDeck();
    
    
    deck->Shuffle();
    
    
    for(int counter = 0; counter < 52; ++counter)
    {
        BlackJackGame::CardPtr card = deck->GetTopCard();
        
        std::cout << card->GetCardString() << "  " << card->GetCardValue() << std::endl;
        
    }
    

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

