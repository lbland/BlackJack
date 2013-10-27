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
#include <asl.h>

namespace BlackJackGame
{

    class Card
    {
    public:
        Card( unsigned int value );
        ~Card( );
        
        const std::string GetCardDisplay( );
        const unsigned int GetCardValue( ) const;
        bool IsAce( ) const;
        
    private:
        unsigned int m_value;
        aslclient m_log;
        
        
    };
    
    typedef std::shared_ptr<Card> CardPtr;
};



#endif
