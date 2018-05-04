package org.elsys.cardgame.api.operation.simple;

import org.elsys.cardgame.api.deck.Deck;
import org.elsys.cardgame.api.game.Game;
import org.elsys.cardgame.api.operation.AbstractOperation;

public class SizeOperation extends AbstractOperation {

    public static final String NAME = "size";

    public SizeOperation(Game game) {
        super(NAME, game);
    }

    @Override
    public void execute() {
        Deck deck = game.getDeck();

        if (deck != null) {
            System.out.println(deck.size());
        } else {
            System.err.println("ERROR: No deck");
        }
    }
}
