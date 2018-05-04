package org.elsys.cardgame.api.operation.card;

import org.elsys.cardgame.api.deck.Deck;
import org.elsys.cardgame.api.game.Game;

public class BottomCardOperation extends CardOperation {

    public static final String NAME = "bottom_card";

    public BottomCardOperation(Game game) {
        super(NAME, game);
    }

    @Override
    protected void evaluate(Deck deck) {
        System.out.println(deck.bottomCard());
    }
}
