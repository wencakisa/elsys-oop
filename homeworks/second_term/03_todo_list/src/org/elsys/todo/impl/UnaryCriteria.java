package org.elsys.todo.impl;

import org.elsys.todo.interfaces.Criteria;

public abstract class UnaryCriteria extends AbstractCriteria {

    protected Criteria criteria;

    public UnaryCriteria(Criteria criteria) {
        this.criteria = criteria;
    }
}
