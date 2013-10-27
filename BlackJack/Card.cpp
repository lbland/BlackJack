//
//  Card.cpp
//  BlackJack
//
//  Created by Loren Bland on 10/21/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#include "Card.h"
#include "Exceptions.h"
#include <sstream>

namespace BlackJackGame
{
    /****************************************
     
     Card class -  a class that defines a card in a deck of cards
     
     ****************************************/
    Card::Card( unsigned int value )
     : m_value( value )
    {
    }
    
    
    /*******************************************
     
     GetCardDisplay return
     
     *******************************************/
    const std::string Card::GetCardDisplay( )
    {
        try
        {
            std::stringstream stream;
            
            switch( m_value % 13 )
            {
                case 0:
                    stream << "A";
                    break;
                case 1:
                    stream << "2";
                    break;
                case 2:
                    stream << "3";
                    break;
                case 3:
                    stream << "4";
                    break;
                case 4:
                    stream << "5";
                    break;
                case 5:
                    stream << "6";
                    break;
                case 6:
                    stream << "7";
                    break;
                case 7:
                    stream << "8";
                    break;
                case 8:
                    stream << "9";
                    break;
                case 9:
                    stream << "10";
                    break;
                case 10:
                    stream << "J";
                    break;
                case 11:
                    stream << "Q";
                    break;
                case 12:
                    stream << "K";
                    break;
                default:
                    throw UnKnownCard("An Unknown card has slipped into the deck");
                    break;
            }
            
            
            switch ( m_value / 13 ) {
                case 0:
                    stream << "C ";
                    break;
                case 1:
                    stream << "D ";
                    break;
                case 2:
                    stream << "H ";
                    break;
                case 3:
                    stream << "S ";
                    break;
                    
                default:
                    throw UnKnownCard("An Unknown card has slipped into the deck");
                    break;
            }
            
            
            return stream.str();
            
        }
        catch(UnKnownCard& ex)
        {
            throw ex;
        }
        
    }
    
    
    /*************************************************
    
     GetCardValue( ) return the value of the card.
     
    **************************************************/
    const unsigned int Card::GetCardValue( ) const
    {
        int cardValue = m_value % 13;

        if(cardValue == 0)
        {
            return 11;
        }
        
        if (cardValue >= 9) {
            return 10;
        }
        
        return cardValue + 1;
        
    }
    
    
    
    /************************************************
     
     IsAce - returns true if the card is an ace.
     
     *************************************************/
    bool Card::IsAce( ) const
    {
        unsigned int value = GetCardValue( );
        if( value == 11 )
        {
            return true;
        }
        
        return false;
        
    }

}
