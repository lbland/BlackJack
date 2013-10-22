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


namespace BlackJackGame
{

    class Deck
    {
    public:
        Deck( );
        Card* GetTopCard( );
        
    private:
        
        Card* m_cards[52];
        int m_howManyCardsDelt;
        
        
    };
};


#endif
