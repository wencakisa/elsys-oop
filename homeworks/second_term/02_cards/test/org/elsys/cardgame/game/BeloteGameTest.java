package org.elsys.cardgame.game;

import org.elsys.cardgame.api.card.Card;
import org.elsys.cardgame.api.deck.Deck;
import org.elsys.cardgame.api.deck.BeloteDeck;
import org.elsys.cardgame.api.game.Game;
import org.elsys.cardgame.factory.DeckFactory;
import org.elsys.cardgame.factory.GameFactory;

import java.util.List;

public class BeloteGameTest extends AbstractGameTest {
    @Override
    protected Game createGame(List<Card> cards) {
        return GameFactory.createBeloteGame(cards);
    }

    @Override
    public Deck defaultDeck() {
        return DeckFactory.defaultBeloteDeck();
    }

    @Override
    public int deckSize() {
        return BeloteDeck.DECK_SIZE;
    }

    @Override
    public int handSize() {
        return BeloteDeck.HAND_SIZE;
    }
}
