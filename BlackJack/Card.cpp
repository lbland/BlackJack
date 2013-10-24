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
                stream << "UNKNOWN";
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
