//
//  Hand.h
//  BlackJack
//
//  Created by Loren Bland on 10/23/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#ifndef __BlackJack_Hand_h
#define __BlackJack_Hand_h

#include <iostream>
#include <list>
#include "Card.h"

#endif /* defined(__BlackJack__Hand__) */

namespace BlackJackGame
{
    
    class Hand
    {
    public:
        Hand( );
        
        const std::string GetHandShowingAllCards( );
        const std::string GetDealersHandAsString( );
        
        void AddCard( const CardPtr& card );
        int  GetCount( );
        bool HasBusted( );
        void ClearHand( );
        bool ShouldDealerHit( );
        
    private:
        std::list<CardPtr>  m_cards;
        bool                m_hasAce;
        int                 m_highHand;
        int                 m_lowHand;
        
    };
    
    typedef std::shared_ptr<Hand> HandPtr;
};