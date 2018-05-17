package org.elsys.todo.impl;

import org.elsys.todo.Criteria;
import org.elsys.todo.Task;

public class OrCriteria extends BinaryCriteria {
    public OrCriteria(Criteria criteria1, Criteria criteria2) {
        super(criteria1, criteria2);
    }

    @Override
    public boolean matches(Task task) {
        return criteria1.matches(task) || criteria2.matches(task);
    }
}
