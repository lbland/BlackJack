//
//  Logger.cpp
//  BlackJack
//
//  Created by Loren Bland on 10/28/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#include "Logger.h"

#include <asl.h>

BlackJackGame::Logger* BlackJackGame::Logger::s_instance = NULL;

namespace BlackJackGame
{
    
    Logger::~Logger( )
    {
        asl_log(m_log, NULL, ASL_LEVEL_EMERG, "destroyed LOREN");
        asl_close(m_log);
    }

    
    /*******************************************
     
     Logger 
        Allow objects to log a message
     *******************************************/
    void Logger::LogMessage( const char* message, ErrorLevel level /*= INFO*/ )
    {

        switch(level)
        {
            case ErrorLevel::INFO:
                //asl_log(m_log, NULL, ASL_LEVEL_ERR, "A Unknow Card number got is being used, critial error.  shutting down.");
                asl_log(m_log, NULL, ASL_LEVEL_INFO, "%s", message);
                break;
                
            case ErrorLevel::WARNING:
                asl_log(m_log, NULL, ASL_LEVEL_WARNING, "%s", message);
                break;
                
            case ErrorLevel::ERROR:
                asl_log(m_log, NULL, ASL_LEVEL_ERR, "%s", message);
                break;
                
            case ErrorLevel::EMERGENCY:
                asl_log(m_log, NULL, ASL_LEVEL_EMERG, "%s", message);
                break;
                
            default:
                
                //unknown error levels should be debug
                
                asl_log(m_log, NULL, ASL_LEVEL_DEBUG, "%s", message);
                break;
        }
        
        
    }
}