package org.elsys.cardgame.factory;

import java.util.List;

import org.elsys.cardgame.api.card.Card;
import org.elsys.cardgame.api.deck.BeloteDeck;
import org.elsys.cardgame.api.deck.Deck;
import org.elsys.cardgame.api.deck.SantaseDeck;
import org.elsys.cardgame.api.deck.WarDeck;
import org.elsys.cardgame.api.game.BeloteGame;
import org.elsys.cardgame.api.game.Game;
import org.elsys.cardgame.api.game.SantaseGame;
import org.elsys.cardgame.api.game.WarGame;

public class GameFactory {

	public static Game createWarGame(List<Card> cards) {
		return new WarGame(new WarDeck(cards));
	}

	public static Game createSantaseGame(List<Card> cards) {
		return new SantaseGame(new SantaseDeck(cards));
	}

	public static Game createBeloteGame(List<Card> cards) {
		return new BeloteGame(new BeloteDeck(cards));
	}
}
