//
//  BackJackGame.cpp
//  BlackJack
//
//  Created by Loren Bland on 10/22/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#include "BlackJackGame.h"
#include "Exceptions.h"


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
        try
        {
            m_dealerPtr->Start();
        }
        catch (NoMoreCardsInDeck& ex)
        {
            std::cout << ex.what() << std::endl;
        }
        catch(UnKnownCard& ex)
        {
            std::cout << ex.what() << std::endl;
        }
        catch(UnKnowGameState& ex)
        {
            std::cout << ex.what() << std::endl;
        }
        
        std::cout << "Please come back and play again.'" << std::endl;
        
    }
    
    
}