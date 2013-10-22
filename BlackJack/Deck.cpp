//
//  Deck.cpp
//  BlackJack
//
//  Created by Loren Bland on 10/21/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#include "Deck.h"
#define NUMBER_OF_CARDS_IN_A_DECK 52

namespace BlackJackGame
{
    
    /********************************
     
     Deck constructor
     
     *********************************/
    Deck::Deck( )
    : m_howManyCardsDelt( 0 )
    {
        m_cards.reserve( NUMBER_OF_CARDS_IN_A_DECK );
        for( int counter = 0; counter < NUMBER_OF_CARDS_IN_A_DECK; ++counter )
        {
            CardPtr card(new Card(counter));
            m_cards.push_back( std::move( card ) );
            //m_cards.push_back( new Card( counter ) );
        }
    }
    
    
    /*************************************
    
     Destructor
     
     *************************************/
    Deck::~Deck( )
    {
    }
    
    /*************************************
     
     GetTopCard 
        returns the top card of the deck
     
     ************************************/
    CardPtr Deck::GetTopCard( )
    {
        return std::move( m_cards[ m_howManyCardsDelt++ ] );
    }
    
}