package org.elsys.cardgame.api.game;

import org.elsys.cardgame.api.hand.Hand;
import org.elsys.cardgame.api.operation.Operation;
import org.elsys.cardgame.api.deck.Deck;

public interface Game {

	Deck getDeck();
	
	Hand getDealtHand();
	
	void setDealtHand(Hand hand);

	void process(String command);

	void addOperation(Operation operation);
}
