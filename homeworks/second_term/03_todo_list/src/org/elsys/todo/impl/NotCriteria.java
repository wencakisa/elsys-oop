package org.elsys.todo.impl;

import org.elsys.todo.interfaces.Criteria;
import org.elsys.todo.interfaces.Task;

public class NotCriteria extends UnaryCriteria {

    public NotCriteria(Criteria criteria) {
        super(criteria);
    }

    @Override
    public boolean matches(Task task) {
        return !criteria.matches(task);
    }
}
