package org.elsys.todo.impl;

import org.elsys.todo.Criteria;
import org.elsys.todo.Task;

public class NotCriteria extends UnaryCriteria {
    public NotCriteria(Criteria criteria) {
        super(criteria);
    }

    @Override
    public boolean matches(Task task) {
        return !criteria.matches(task);
    }
}
