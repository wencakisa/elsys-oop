package org.elsys.cardgame.api.deck;

import org.elsys.cardgame.api.card.Card;
import org.elsys.cardgame.api.hand.Hand;

import java.util.List;

public interface Deck {

	List<Card> getCards();

	boolean canPlay();

	boolean canDeal();

	String getName();

	int size();

	int handSize();

	Card drawTopCard();

	Card topCard();

	Card drawBottomCard();

	Card bottomCard();

	Hand deal();

	void sort();
	
	void shuffle();

}
