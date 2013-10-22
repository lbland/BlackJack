//
//  BackJackGame.cpp
//  BlackJack
//
//  Created by Loren Bland on 10/22/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#include "BlackJackGame.h"

namespace BlackJackGame
{
    /*******************************
     Constructor
     
     *******************************/
    BlackJackGame::BlackJackGame( )
    :m_deck( new Deck( ) )
    {
    }
    
    /*******************************
     GetDeck:
        Gets the deck of cards for the game
     
     *******************************/
    DeckPtr BlackJackGame::GetDeck( )
    {
        return std::move( m_deck );
    }
    
    
    
}