//
//  Hand.cpp
//  BlackJack
//
//  Created by Loren Bland on 10/23/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#include "Hand.h"
#include "Logger.h"

#include <sstream>
#include <assert.h>

namespace BlackJackGame
{
    /****************************************
     
     Hand class - The cards in a players hand
     ****************************************/
    Hand::Hand( )
    : m_cards( ),
      m_hasAce( false ),
      m_highHand( 0 ),
      m_lowHand( 0 )
    {
    }
    
    /****************************************
     
     Destructor - destructor.  
     
     ****************************************/
    Hand::~Hand( )
    {
        
        for(std::list<CardPtr>::iterator iter = m_cards.begin( ); iter != m_cards.end( ); ++iter )
        {
            (*iter).reset( );
        }
    }
    
    /****************************************
     
     AddCard
        Add a card to the hand.
     ****************************************/
    void Hand::AddCard( const CardPtr& card )
    {
        assert(card);
        
        m_cards.push_back( card );
        int value = card->GetCardValue();
        bool isAce = card->IsAce( );
        
        
        if( m_hasAce == false && isAce == false )
        {
            m_highHand += value;
        }
        else if( m_hasAce == false && isAce == true )
        {
            m_hasAce = true;
            m_lowHand = m_highHand;
            
            m_highHand += HIGH_ACE;
            m_lowHand += LOW_ACE;
        }
        else if( m_hasAce == true && isAce == false )
        {
            m_lowHand += value;
            m_highHand += value;
        }
        else
        {
            // this is the case where we already have at least 2 aces.  We shoudl just add 1 in all cases
            // because two 11s would be a bust.
            m_lowHand += LOW_ACE;
            m_highHand +=  LOW_ACE;
        }
    }
    
    /****************************************
     
     GetCount
      Gets the count of the hand
     ****************************************/
    const unsigned int Hand::GetCount( ) const
    {
        if( m_highHand > TWEENTY_ONE )
        {
            return m_lowHand;
        }
        
        return m_highHand;
    }
    
    
    /****************************************
    HasBusted
        returns if the hand has busted
     ****************************************/
    const bool Hand::HasBusted( ) const
    {
        if( m_highHand > TWEENTY_ONE && m_hasAce == false )
        {
            return true;
        }
        else if( m_highHand > TWEENTY_ONE && m_hasAce && m_lowHand > TWEENTY_ONE )
        {
            return true;
        }
        
        return false;
    }
    
    /****************************************
     GetHandShowingAllCards
        Returns a string that can show a players hand
     ****************************************/
    const std::string Hand::GetHandShowingAllCards( ) const
    {        
        std::stringstream hand;
        for(std::list<CardPtr>::const_iterator iter = m_cards.begin( ); iter != m_cards.end( ); ++iter )
        {
            CardPtr card = *iter;
            hand << card->GetCardDisplay( ) << " ";
        }
        
        // if the hand has an ace, there are two possible hands values.
        // there can only be two values because multiple 11s would be a bust.
        if( m_hasAce == true )
        {
            Logger::LogMessage("Hand has two aces");
            hand << "HAND: " << m_highHand << "(" << m_lowHand << ")";
        }
        else
        {
            hand << " HAND: " << m_highHand;
        }
        
        return hand.str( );
    }
    
    
    /****************************************
     GetHandHiddingFirstCard
        Returns a string that can show a hand but hides one card
     ****************************************/
    const std::string Hand::GetDealersHandAsString( ) const
    {
        std::stringstream hand;
        hand << "Hidden Card " << m_cards.front( )->GetCardDisplay( );
        return hand.str( );
    }
    
    
    /****************************************
     ClearHand
        clears the hand (list).
     ****************************************/
    void Hand::ClearHand( )
    {
        m_cards.clear();
        m_hasAce = false;
        m_highHand = 0;
        m_lowHand = 0;
    }
    
    /****************************************
     ShouldDealerHit
        Should the dealer hit, Dealer has to hit on soft 17, won't hit on hard 17
     ****************************************/
    bool Hand::ShouldDealerHit( )
    {
        if( m_highHand < SEVENTEEN )
        {
            return true;
        }
        else if( m_highHand <= SEVENTEEN && m_hasAce == true )
        {
            //soft seventeen
            return true;
        }
        else if( m_highHand <= TWEENTY_ONE && m_highHand > SEVENTEEN && m_hasAce )
        {
            // has aces but beats soft 17.
            return false;
        }
        else if( m_highHand > TWEENTY_ONE && m_lowHand <= SEVENTEEN && m_hasAce )
        {
            // has not beaten the soft 17 requirement yet.
            return true;
        }
        
        //otherwise Do no
        return false;
        
    }
    
}