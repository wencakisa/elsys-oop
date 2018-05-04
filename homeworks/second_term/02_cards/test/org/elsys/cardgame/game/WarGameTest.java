package org.elsys.cardgame.game;

import org.elsys.cardgame.api.card.Card;
import org.elsys.cardgame.api.deck.Deck;
import org.elsys.cardgame.api.deck.WarDeck;
import org.elsys.cardgame.api.game.Game;
import org.elsys.cardgame.factory.DeckFactory;
import org.elsys.cardgame.factory.GameFactory;

import java.util.List;

public class WarGameTest extends AbstractGameTest {
    @Override
    protected Game createGame(List<Card> cards) {
        return GameFactory.createWarGame(cards);
    }

    @Override
    public Deck defaultDeck() {
        return DeckFactory.defaultWarDeck();
    }

    @Override
    public int deckSize() {
        return WarDeck.DECK_SIZE;
    }

    @Override
    public int handSize() {
        return WarDeck.HAND_SIZE;
    }
}
