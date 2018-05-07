package org.elsys.cardgame.factory;

import java.util.ArrayList;
import java.util.List;

import org.elsys.cardgame.api.card.Card;
import org.elsys.cardgame.api.deck.BeloteDeck;
import org.elsys.cardgame.api.deck.Deck;
import org.elsys.cardgame.api.deck.SantaseDeck;
import org.elsys.cardgame.api.deck.WarDeck;
import org.elsys.cardgame.api.game.Game;
import org.elsys.cardgame.api.game.GameImpl;

public class GameFactory {

	private static Game createGame(Deck deck) {
	    return new GameImpl(deck);
    }

	public static Game createWarGame(List<Card> cards) {
		return createGame(new WarDeck(cards));
	}

	public static Game createSantaseGame(List<Card> cards) {
		return createGame(new SantaseDeck(cards));
	}

	public static Game createBeloteGame(List<Card> cards) {
		return createGame(new BeloteDeck(cards));
	}
}
