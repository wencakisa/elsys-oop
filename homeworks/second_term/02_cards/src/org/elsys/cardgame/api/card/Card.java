package org.elsys.cardgame.api.card;

import org.elsys.cardgame.api.Rank;
import org.elsys.cardgame.api.Suit;

public interface Card {

	Suit getSuit();

	Rank getRank();
}
