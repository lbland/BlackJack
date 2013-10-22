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

    class Deck
    {
    public:
        Deck( );
        ~Deck( );
        CardPtr GetTopCard( );
        
    private:
        
        std::vector<CardPtr>    m_cards;
        int                     m_howManyCardsDelt;
        
        
    };

    typedef std::unique_ptr<Deck> DeckPtr;
};


#endif
