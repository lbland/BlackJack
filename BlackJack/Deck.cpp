//
//  Deck.cpp
//  BlackJack
//
//  Created by Loren Bland on 10/21/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//
#include "Deck.h"
#include "Exceptions.h"

#include <algorithm>
#include <random>
#include <chrono>


namespace BlackJackGame
{
    
    /********************************
     
     Deck constructor
     
     *********************************/
    Deck::Deck( )
    : m_howManyCardsDelt( 0 ),
      m_log( asl_open("com.lorenbland.BlackJack", "Logging for BlackJack", 0) )
    {
        m_cards.reserve( NUMBER_OF_CARDS_IN_A_DECK );
        for( int counter = 0; counter < NUMBER_OF_CARDS_IN_A_DECK; ++counter )
        {
            CardPtr card(new Card(counter));
            m_cards.push_back( card );
        }
    }
    
    
    /****************************************
     
     Destructor - destructor.  need to close the log
     
     ****************************************/
    Deck::~Deck( )
    {
        asl_close(m_log);
    }
    
    /*************************************
     
     DealTopCard 
        returns the top card of the deck
     
     ************************************/
    const CardPtr& Deck::DealTopCard( )
    {
        try
        {
            if( m_howManyCardsDelt >= ( NUMBER_OF_CARDS_IN_A_DECK - 1 )  )
            {
                asl_log(m_log, NULL, ASL_LEVEL_ERR, "The deck is going to be empty Shutting down game.");
                throw NoMoreCardsInDeck( "Sorry there are no more cards in the deck." );
            }
            return m_cards[ m_howManyCardsDelt++ ];
        }
        catch ( NoMoreCardsInDeck& ex )
        {
            throw ex;
        }

    }
    
    
    /*************************************
     
     Shuffle
     shuffles the deck of cards
     
     ************************************/
    void Deck::Shuffle( )
    {
        //unsigned int seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
        std::random_shuffle( m_cards.begin( ), m_cards.end( ) );
        
        //reset how many cards have been delt.
        m_howManyCardsDelt = 0;
    }
    
    
}