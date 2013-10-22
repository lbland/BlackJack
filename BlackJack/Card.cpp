//
//  Card.cpp
//  BlackJack
//
//  Created by Loren Bland on 10/21/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#include "Card.h"
#include <sstream>

namespace BlackJackGame
{
    /****************************************
     
     Card class -  a class that defines a card in a deck of cards
     
     ****************************************/
    Card::Card( int value )
     : m_value( value )
    {
    }
    
    
    /*******************************************
     
     std::string GetCardString
     
     *******************************************/
    const std::string Card::GetCardString( )
    {
        std::stringstream stream;
        
        switch (m_value % 13)
        {
            case 0:
                stream << "Ace";
                break;
            case 1:
                stream << "Two";
                break;
            case 2:
                stream << "Three";
                break;
            case 3:
                stream << "Four";
                break;
            case 4:
                stream << "Five";
                break;
            case 5:
                stream << "Six";
                break;
            case 6:
                stream << "Seven";
                break;
            case 7:
                stream << "Eight";
                break;
            case 8:
                stream << "Nine";
                break;
            case 9:
                stream << "Ten";
                break;
            case 10:
                stream << "Jack";
                break;
            case 11:
                stream << "Queen";
                break;
            case 12:
                stream << "King";
                break;
            default:
                stream << "UNKNOWN";
                break;
        }
        
        
        switch ( m_value / 13 ) {
            case 0:
                stream << " of Clubs ";
                break;
            case 1:
                stream << " of Diamonds ";
                break;
            case 2:
                stream << " of Hearts ";
                break;
            case 3:
                stream << " of Spades ";
                break;
                
            default:
                stream << " of UNKNOWN ";
                break;
        }
        
        
        return stream.str();
        
        
    }
    
    
    /*************************************************
    
     GetCardValue( ) return the value of the card.
     
     TBD how to handle ACES
     
    **************************************************/
    const int Card::GetCardValue( )
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


}
