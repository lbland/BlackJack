//
//  Dealer.cpp
//  BlackJack
//
//  Created by Loren Bland on 10/22/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#include "Dealer.h"


namespace BlackJackGame
{

    /****************************************
     
     Dealer class -  The dealer owns the deck
     ****************************************/
    Dealer::Dealer( )
    : m_deckPtr( new Deck( ) ),
      m_dealersCards( new Hand( ) ),
      m_playersCards( new Hand( ) ),
      m_handsPlayerWon( 0 ),
      m_handsDealerWon( 0 ),
      m_draws( 0 )
    
    {
    }
    
    /****************************************
     
     Deal - deals the blackjack hands
     ****************************************/
    void Dealer::Deal( )
    {
        // first card to player
        GiveUserOneMoreCard( );
        // dealer gets 2nd card
        GiveDealerOneMoreCard( );
        // 3rd card to player
        GiveUserOneMoreCard( );
        // dealer gets 4th card
        GiveDealerOneMoreCard( );
        
        std::cout << "You have: " << std::endl;
        std::cout << m_playersCards->GetHandShowingAllCards( ) << std::endl;
        
        std::cout << "Dealer has: " << std::endl;
        std::cout << m_dealersCards->GetDealersHandAsString( ) << std::endl;
        
        AskForUserInput( );
        
    }
    
    
    /****************************************
     
     AskForUserInput - asks the user to give a action
     ****************************************/
    void Dealer::AskForUserInput( )
    {
        std::cout << "What would you like to do (h)it or (s)tay?";
        std::string input;
        getline( std::cin, input );
        
        if( input.compare("s") == 0 || input.compare("S") == 0 )
        {
            DealersTurn( );
        }
        else if( input.compare("h") == 0 || input.compare("H") == 0 )
        {
            GiveUserOneMoreCard( );
            
            if( m_playersCards->HasBusted( ) )
            {
                CompareHands( );
                
            }
            AskForUserInput( );
            
        }
        else
        {
            std::cout << "Please enter a valid action: \n h - Hit \n s - Stay" << std::endl;
            AskForUserInput( );
        }
        
    }
    
    
    /****************************************
    DealersTurn - should the dealer hit if so, hit.
    
     ****************************************/
    void Dealer::DealersTurn( )
    {
        // turn over deal
        std::cout << std::endl;
        std::cout << "Dealer has: " << std::endl;
        
        // see what the dealer has
        std::cout << m_dealersCards->GetHandShowingAllCards( ) << std::endl;
        
        if( ShouldDealerHit( ) )
        {
            GiveDealerOneMoreCard( );
        }
        
        CompareHands( );
    }
    
    /****************************************
     GiveUserOneMoreCard - give the user a card
     
     ****************************************/
    void Dealer::GiveUserOneMoreCard( )
    {
        m_playersCards->AddCard( m_deckPtr->GetTopCard( ) );
    }

    
    /****************************************
     GiveDealerOneMoreCard - give the dealer a card
     
     ****************************************/
    void Dealer::GiveDealerOneMoreCard( )
    {
        m_dealersCards->AddCard( m_deckPtr->GetTopCard( ) );
    }
    
    
    /****************************************
     ShouldDealerHit - should the dealer hit, (TBD)dealer has to hit on soft 17.
     
     ****************************************/
    bool Dealer::ShouldDealerHit( )
    {
        int handCount = m_dealersCards->GetCount( );
        
        std::cout << std::endl;
        std::cout << "Dealer has: " << handCount;
        
        if(handCount >= 17)
        {
            return false;
        }
        return true;
    }
    
    
    
    /****************************************
     CompareHands - compares the 2 hands
     
     ****************************************/
    void Dealer::CompareHands( )
    {
        int playersHand = m_playersCards->GetCount( );
        int dealersHand = m_dealersCards->GetCount( );
        
        // player wins
        if( ( playersHand > dealersHand && !m_playersCards->HasBusted( ) ) || m_dealersCards->HasBusted( ) )
        {
            m_handsPlayerWon++;
            std::cout << "You Win!" << std::endl;
        }
        else if( dealersHand > playersHand || m_playersCards->HasBusted( ) )
        {
            m_handsDealerWon++;
            std::cout << "Dealer wins" << std::endl;
        }
        else if( dealersHand == playersHand )
        {
            m_draws++;
            std::cout << "Game is a draw." << std::endl;
        }
        
        std::cout << "Player has won " << m_handsPlayerWon << " games." << std::endl;
        std::cout << "Dealer has won " << m_handsDealerWon << " games." << std::endl;
        
        
        
    }
    
}