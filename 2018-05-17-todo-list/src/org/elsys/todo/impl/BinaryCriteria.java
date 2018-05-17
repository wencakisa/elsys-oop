package org.elsys.todo.impl;

import org.elsys.todo.Criteria;

public abstract class BinaryCriteria extends AbstractCriteria {

    protected Criteria criteria1;

    protected Criteria criteria2;

    public BinaryCriteria(Criteria criteria1, Criteria criteria2) {
        this.criteria1 = criteria1;
        this.criteria2 = criteria2;
    }
}
