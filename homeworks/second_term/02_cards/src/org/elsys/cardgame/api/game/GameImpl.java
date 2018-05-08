package org.elsys.cardgame.api.game;

import org.elsys.cardgame.api.hand.Hand;
import org.elsys.cardgame.api.deck.Deck;
import org.elsys.cardgame.api.operation.Operation;
import org.elsys.cardgame.api.operation.simple.SizeOperation;
import org.elsys.cardgame.api.operation.card.*;
import org.elsys.cardgame.api.operation.deckOrderModifier.ShuffleOperation;
import org.elsys.cardgame.api.operation.deckOrderModifier.SortOperation;

import java.util.ArrayList;
import java.util.List;

public class GameImpl implements Game {

    private Deck deck;

    private Hand dealtHand;

    private List<Operation> operations;

    public GameImpl(Deck deck) {
        if (!deck.canPlay()) {
            System.err.println("ERROR: Not enough cards for " + deck.getName());
        }

        this.deck = deck;
        this.dealtHand = null;
        this.operations = new ArrayList<>();

        addOperation(new SizeOperation(this));
        addOperation(new TopCardOperation(this));
        addOperation(new BottomCardOperation(this));
        addOperation(new DrawTopCardOperation(this));
        addOperation(new DrawBottomCardOperation(this));
        addOperation(new DealOperation(this));
        addOperation(new SortOperation(this));
        addOperation(new ShuffleOperation(this));
    }

    @Override
    public Deck getDeck() {
        return deck;
    }

    @Override
    public Hand getDealtHand() {
        return dealtHand;
    }

    @Override
    public void setDealtHand(Hand hand) {
        this.dealtHand = hand;
    }

    @Override
    public void process(String command) {
        Operation operation = getOperation(command);

        if (operation != null) {
            operation.execute();
        } else {
            System.err.println("ERROR: Unknown operation");
        }
    }

    @Override
    public void addOperation(Operation operation) {
        this.operations.add(operation);
    }

    private Operation getOperation(String token) {
        for (Operation operation : operations) {
            if (operation.getName().equals(token)) {
                return operation;
            }
        }

        return null;
    }
}
