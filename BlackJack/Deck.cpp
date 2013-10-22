//
//  Deck.cpp
//  BlackJack
//
//  Created by Loren Bland on 10/21/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#include "Deck.h"


namespace BlackJackGame
{
    
    /********************************
     
     Deck constructor
     
     *********************************/
    Deck::Deck( )
    : m_howManyCardsDelt(0)
    {
        for(int counter = 0; counter < 52; ++counter)
        {
            m_cards[counter] = new Card(counter);
        }
    }
    
    
    
    Card* Deck::GetTopCard( )
    {
        return m_cards[m_howManyCardsDelt++];
    }
    
}