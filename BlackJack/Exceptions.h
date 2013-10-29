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
    
    /*****************************************
     NoMoreCardsInDeck Exception
        This exception is thrown when a deck has been completely delt,
        and a request for the top card is made
     
     *****************************************/
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
    
    
    /*****************************************
     UnKnownCard Exception
        This exception is throw when a card with an unknow value or suit 
        is detected.
     
     *****************************************/
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

    
    
    /*****************************************
     UnKnowGameState Exception
        This happen when the dealer class gets to a GameState that is unknown state
     
     *****************************************/
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
