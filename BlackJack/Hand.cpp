//
//  Hand.cpp
//  BlackJack
//
//  Created by Loren Bland on 10/23/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#include <sstream>
#include "Hand.h"

#define TWEENTY_ONE 21


namespace BlackJackGame
{
    /****************************************
     
     Hand class - The cards in a players hand
     ****************************************/
    Hand::Hand( )
    : m_cards( )
    {
    }
    
    
    /****************************************
     
     AddCard
        Add a card to the hand.
     ****************************************/
    void Hand::AddCard( const CardPtr& card )
    {
        m_cards.push_back( card );
    }
    
    /****************************************
     
     GetCount
      Gets the count of the hand (TBD ACES)
     ****************************************/
    int Hand::GetCount( )
    {
        int handCount = 0;
        
        for(std::list<CardPtr>::iterator iter = m_cards.begin( ); iter != m_cards.end( ); ++iter )
        {
            CardPtr card = *iter;
            handCount += card->GetCardValue( );
        }
        
        return handCount;
    }
    
    
    /****************************************
    HasBusted
        returns if the hand has busted
     ****************************************/
    bool Hand::HasBusted( )
    {
        if( GetCount( ) > TWEENTY_ONE )
        {
            return true;
        }
        return false;
    }
    
    /****************************************
     GetHandShowingAllCards
        Returns a string that can show a players hand
     ****************************************/
    const std::string Hand::GetHandShowingAllCards( )
    {
        std::stringstream hand;
        for(std::list<CardPtr>::iterator iter = m_cards.begin( ); iter != m_cards.end( ); ++iter )
        {
            CardPtr card = *iter;
            hand << card->GetCardString( ) << " ";
        }
        
        return hand.str( );
    }
    
    
    /****************************************
     GetHandHiddingFirstCard
     Returns a string that can show a hand but hides one card
     ****************************************/
    const std::string Hand::GetDealersHandAsString( )
    {
        std::stringstream hand;
        hand << "Hidden Card " << m_cards.front( )->GetCardString( );
        return hand.str( );
    }
    
    
    /****************************************
     ClearHand
     clears the hand (list)
     ****************************************/
    void Hand::ClearHand( )
    {
        m_cards.clear();
    }
    
}