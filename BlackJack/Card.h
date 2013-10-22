//
//  Card.h
//  BlackJack
//
//  Created by Loren Bland on 10/21/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#ifndef BlackJack_Card_h
#define BlackJack_Card_h

#include <string>

namespace BlackJackGame
{

    class Card
    {
    public:
        Card( );
        Card( int value );
        
        const std::string GetCardString( );
        const int GetCardValue( );
        
    private:
        int m_value;
        
        
    };
};



#endif