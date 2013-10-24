//
//  Dealer.h
//  BlackJack
//
//  Created by Loren Bland on 10/22/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#ifndef __BlackJack_Dealer_h
#define __BlackJack_Dealer_h

#include <iostream>
#include <list>
#include "Deck.h"
#include "Hand.h"


namespace BlackJackGame {
    
    
    class Dealer
    {
        
    public:
        
        Dealer( );
        
        void Deal( );
        
        
    private:
        void AskForUserInput( );
        void DealersTurn( );
        void GiveUserOneMoreCard( );
        void GiveDealerOneMoreCard( );
        void CompareHands( );
        bool ShouldDealerHit( );
        
        
        DeckPtr     m_deckPtr;
        HandPtr     m_playersCards;
        HandPtr     m_dealersCards;
        
        int         m_handsPlayerWon;
        int         m_handsDealerWon;
        int         m_draws;
        
    };
    
    typedef std::shared_ptr<Dealer> DealerPtr;
};


#endif /* defined(__BlackJack__Dealer__) */
