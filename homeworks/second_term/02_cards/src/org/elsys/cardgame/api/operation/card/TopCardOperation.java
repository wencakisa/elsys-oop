package org.elsys.cardgame.api.operation.card;

import org.elsys.cardgame.api.deck.Deck;
import org.elsys.cardgame.api.game.Game;

public class TopCardOperation extends CardOperation {

    public static final String NAME = "top_card";

    public TopCardOperation(Game game) {
        super(NAME, game);
    }

    @Override
    protected void evaluate(Deck deck) {
        System.out.println(deck.topCard());
    }
}
