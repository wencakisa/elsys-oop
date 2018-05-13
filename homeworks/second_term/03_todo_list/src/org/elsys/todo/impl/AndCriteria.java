package org.elsys.todo.impl;

import org.elsys.todo.interfaces.Criteria;
import org.elsys.todo.interfaces.Task;

public class AndCriteria extends BinaryCriteria {

    public AndCriteria(Criteria criteria1, Criteria criteria2) {
        super(criteria1, criteria2);
    }

    @Override
    public boolean matches(Task task) {
        return criteria1.matches(task) && criteria2.matches(task);
    }
}
