package org.elsys.cardgame.api.hand;

import org.elsys.cardgame.api.card.Card;

import java.util.List;

public interface
Hand {

	List<Card> getCards();

	int size();
}
