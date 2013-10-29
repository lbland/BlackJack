//
//  BlackJackGame.h
//  BlackJack
//
//  Created by Loren Bland on 10/21/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#ifndef BlackJack_BlackJackGame_h
#define BlackJack_BlackJackGame_h

#include "Dealer.h"

namespace BlackJackGame
{
    
    /*******************************************
     BlackJackGame
     
     The BlackJackGame class is responsible for starting the game
     through the dealer.
     
     
     ******************************************/
    class BlackJackGame
    {
    public:
        BlackJackGame( );
        
        void Start( );
        
    private:
        DealerPtr m_dealerPtr;
        
    };

};

#endif
