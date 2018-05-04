package org.elsys.cardgame.api.operation;

import org.elsys.cardgame.api.game.Game;

public abstract class AbstractOperation implements Operation {

    private String name;

    protected Game game;

    public AbstractOperation(String name, Game game) {
        this.name = name;
        this.game = game;
    }

    @Override
    public String getName() {
        return name;
    }
}
