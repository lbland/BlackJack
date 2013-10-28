//
//  Logger.h
//  BlackJack
//
//  Created by Loren Bland on 10/28/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#ifndef __BlackJack_Logger_h
#define __BlackJack_Logger_h

#include <asl.h>
#include <string>

namespace BlackJackGame
{

    enum ErrorLevel
    {
        INFO,
        WARNING,
        ERROR,
        EMERGENCY
    };
    
    class Logger
    {
    private:
        
        Logger( )
        :m_log( asl_open("com.lorenbland.BlackJack", "Logging for BlackJack", 0) )
        {}
        Logger(Logger const& copy);
        Logger& operator=(Logger const& copy);
        
        aslclient m_log;
        static Logger *s_instance;
        
    public:
        
        ~Logger( );

        static Logger* GetInstance()
        {
            if(s_instance == NULL)
            {
                s_instance = new Logger( );
            }
            
            return s_instance;
        }
        
        void LogMessage( const char* message, ErrorLevel level = ErrorLevel::INFO );
        
    };

}

#endif
