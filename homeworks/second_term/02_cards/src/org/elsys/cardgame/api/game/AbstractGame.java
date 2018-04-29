package org.elsys.cardgame.api.game;

import org.elsys.cardgame.api.hand.Hand;
import org.elsys.cardgame.api.operation.Operation;
import org.elsys.cardgame.api.deck.Deck;

import java.util.ArrayList;
import java.util.List;

public abstract class AbstractGame implements Game {

    private Deck deck;

    private Hand dealtHand;

    private List<Operation> operations;

    public AbstractGame(Deck deck) {
        this.deck = deck;
        this.dealtHand = null;
        this.operations = new ArrayList<>();
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
        for (Operation o : operations) {
            if (o.getName().equals(command)) {
                o.execute();
            }
        }
    }

    @Override
    public void addOperation(Operation operation) {
        this.operations.add(operation);
    }
}
