//
//  Deck.cpp
//  BlackJack
//
//  Created by Loren Bland on 10/21/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#include <algorithm>
#include <random>
#include <chrono>

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
            m_cards.push_back( card );
        }
    }
    
    
    /*************************************
     
     GetTopCard 
        returns the top card of the deck
     
     ************************************/
    const CardPtr& Deck::GetTopCard( )
    {
        return m_cards.at( m_howManyCardsDelt++ );
    }
    
    
    /*************************************
     
     Shuffle
     shuffles the deck of cards
     
     ************************************/
    void Deck::Shuffle( )
    {
        unsigned int seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
        std::shuffle( m_cards.begin( ), m_cards.end( ), std::default_random_engine(seed) );
        
        //reset how many cards have been delt.
        m_howManyCardsDelt = 0;
    }
    
    
}