//
//  Exceptions.h
//  BlackJack
//
//  Created by Loren Bland on 10/27/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#ifndef __BlackJack_Exceptions_h
#define __BlackJack_Exceptions_h

#include <exception>

namespace BlackJackGame
{
    class NoMoreCardsInDeck : public std::exception
    {
    public:
        NoMoreCardsInDeck( const char* errorMessage )
         : m_errorMessage( errorMessage )
        {}
        
        const char* what( ) const throw()
        {
            return m_errorMessage;
        }
        
    private:
        const char* m_errorMessage;
    };
    
    class UnKnownCard : public std::exception
    {
    public:
        UnKnownCard( const char* errorMessage )
        : m_errorMessage( errorMessage )
        {}
        
        const char* what( ) const throw()
        {
            return m_errorMessage;
        }
        
    private:
        const char* m_errorMessage;
    };

    class UnKnowGameState : public std::exception
    {
    public:
        UnKnowGameState( const char* errorMessage )
        : m_errorMessage( errorMessage )
        {}
        
        const char* what( ) const throw()
        {
            return m_errorMessage;
        }
        
    private:
        const char* m_errorMessage;
    };


}

#endif
