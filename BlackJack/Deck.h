//
//  Deck.h
//  BlackJack
//
//  Created by Loren Bland on 10/21/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#ifndef BlackJack_Deck_h
#define BlackJack_Deck_h

#include "Card.h"
#include <vector>


namespace BlackJackGame
{
    static const unsigned int NUMBER_OF_CARDS_IN_A_DECK = 52;

    class Deck
    {
    public:
        Deck( );
        ~Deck( );
        
        const CardPtr& GetTopCard( );
        void Shuffle( );
        
    private:
        std::vector<CardPtr>    m_cards;
        unsigned int            m_howManyCardsDelt;
        aslclient               m_log;
        
        
        
    };

    typedef std::shared_ptr<Deck> DeckPtr;
};


#endif
