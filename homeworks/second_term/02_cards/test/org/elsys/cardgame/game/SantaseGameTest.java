package org.elsys.cardgame.game;

import org.elsys.cardgame.api.card.Card;
import org.elsys.cardgame.api.deck.Deck;
import org.elsys.cardgame.api.deck.SantaseDeck;
import org.elsys.cardgame.api.game.Game;
import org.elsys.cardgame.factory.DeckFactory;
import org.elsys.cardgame.factory.GameFactory;

import java.util.List;

public class SantaseGameTest extends AbstractGameTest {
    @Override
    protected Game createGame(List<Card> cards) {
        return GameFactory.createSantaseGame(cards);
    }

    @Override
    public Deck defaultDeck() {
        return DeckFactory.defaultSantaseDeck();
    }

    @Override
    public int deckSize() {
        return SantaseDeck.DECK_SIZE;
    }

    @Override
    public int handSize() {
        return SantaseDeck.HAND_SIZE;
    }
}
