package org.elsys.cardgame.api.operation.card;

import org.elsys.cardgame.api.deck.Deck;
import org.elsys.cardgame.api.game.Game;

public class DealOperation extends CardOperation {

    public static final String NAME = "deal";

    public DealOperation(Game game) {
        super(NAME, game);
    }

    @Override
    protected void evaluate(Deck deck) {
        game.setDealtHand(deck.deal());
        System.out.println(game.getDealtHand());
    }
}
