package org.elsys.cardgame.api.operation.deckOrderModifier;

import org.elsys.cardgame.api.deck.Deck;
import org.elsys.cardgame.api.game.Game;

public class ShuffleOperation extends DeckOrderModifierOperation {

    public static final String NAME = "shuffle";

    public ShuffleOperation(Game game) {
        super(NAME, game);
    }

    @Override
    protected void evaluate(Deck deck) {
        deck.shuffle();
    }
}
