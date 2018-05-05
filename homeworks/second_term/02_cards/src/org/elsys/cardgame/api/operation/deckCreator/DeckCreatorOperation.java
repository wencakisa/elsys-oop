package org.elsys.cardgame.api.operation.deckCreator;

import org.elsys.cardgame.api.game.Game;
import org.elsys.cardgame.api.operation.AbstractOperation;

public abstract class DeckCreatorOperation extends AbstractOperation {
    public DeckCreatorOperation(String name, Game game) {
        super(name, game);
    }

    @Override
    public void execute() {
        this.game = evaluate();
    }

    protected abstract Game evaluate();
}
