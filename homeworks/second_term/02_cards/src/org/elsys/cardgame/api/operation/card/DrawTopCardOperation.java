package org.elsys.cardgame.api.operation.card;

import org.elsys.cardgame.api.deck.Deck;
import org.elsys.cardgame.api.game.Game;

public class DrawTopCardOperation extends CardOperation {

    public static final String NAME = "draw_top_card";

    public DrawTopCardOperation(Game game) {
        super(NAME, game);
    }

    @Override
    protected void evaluate(Deck deck) {
        System.out.println(deck.drawTopCard());
    }
}
