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
     : m_dealerPtr( new Dealer( ) )
    {
    }
    
    
    
    /*******************************
     Start: Start the blackjack game
     
     *******************************/
    void BlackJackGame::Start( )
    {
        m_dealerPtr->Start();
        
    }
    
    
}