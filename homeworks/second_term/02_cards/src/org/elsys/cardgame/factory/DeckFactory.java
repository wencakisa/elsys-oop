package org.elsys.cardgame.factory;

import org.elsys.cardgame.api.*;

import java.util.List;
import java.util.ArrayList;

public class DeckFactory {

    private static List<Card> defaultDeckCards(List<Rank> rankPowers) {
        List<Card> result = new ArrayList<>();

        for (Suit s : Suit.values()) {
            for (Rank r : rankPowers) {
                result.add(new PlayingCard(s, r));
            }
        }

        return result;
    }

	public static Deck defaultWarDeck() {
        return new WarDeck(defaultDeckCards(WarDeck.RANK_POWERS));
	}

	public static Deck defaultSantaseDeck() {
        return new SantaseDeck(defaultDeckCards(SantaseDeck.RANK_POWERS));
	}

	public static Deck defaultBeloteDeck() {
        return new BeloteDeck(defaultDeckCards(BeloteDeck.RANK_POWERS));
	}
}