package org.elsys.cardgame.api.operation.card;

import org.elsys.cardgame.api.deck.Deck;
import org.elsys.cardgame.api.game.Game;

public class DrawBottomCardOperation extends CardOperation {

    public static final String NAME = "draw_bottom_card";

    public DrawBottomCardOperation(Game game) {
        super(NAME, game);
    }

    @Override
    protected void evaluate(Deck deck) {
        System.out.println(deck.drawBottomCard());
    }
}
