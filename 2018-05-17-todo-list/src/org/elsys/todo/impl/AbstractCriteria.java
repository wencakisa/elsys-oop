package org.elsys.todo.impl;

import org.elsys.todo.Criteria;

public abstract class AbstractCriteria implements Criteria {
    @Override
    public Criteria and(Criteria other) {
        return new AndCriteria(this, other);
    }

    @Override
    public Criteria or(Criteria other) {
        return new OrCriteria(this, other);
    }

    @Override
    public Criteria xor(Criteria other) {
        return new XorCriteria(this, other);
    }

    @Override
    public Criteria not() {
        return new NotCriteria(this);
    }
}
