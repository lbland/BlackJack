//
//  Hand.h
//  BlackJack
//
//  Created by Loren Bland on 10/23/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#ifndef __BlackJack_Hand_h
#define __BlackJack_Hand_h

#include "Card.h"

#include <iostream>
#include <list>

#endif /* defined(__BlackJack__Hand__) */

namespace BlackJackGame
{
    static const unsigned int TWEENTY_ONE   = 21;
    static const unsigned int HIGH_ACE      = 11;
    static const unsigned int LOW_ACE       = 1;
    static const unsigned int SEVENTEEN     = 17;
    
    /*********************************************
      Hand - 
        this class is used to keep track of a players hand.
     
     **********************************************/
    
    class Hand
    {
    public:
        Hand( );
        
        ~Hand( );
        
        const std::string GetHandShowingAllCards( ) const;
        const std::string GetDealersHandAsString( ) const;
        
        void AddCard( const CardPtr& card );
        const unsigned int  GetCount( ) const;
        const bool HasBusted( ) const;
        void ClearHand( );
        bool ShouldDealerHit( );
        
    private:
        std::list<CardPtr>  m_cards;
        bool                m_hasAce;
        unsigned int        m_highHand;
        unsigned int        m_lowHand;
        
    };
    
    typedef std::shared_ptr<Hand> HandPtr;
};