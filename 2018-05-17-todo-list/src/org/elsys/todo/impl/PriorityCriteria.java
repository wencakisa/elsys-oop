package org.elsys.todo.impl;

import org.elsys.todo.Priority;
import org.elsys.todo.Task;

public class PriorityCriteria extends AbstractCriteria {

    private Priority priority;

    public PriorityCriteria(Priority priority) {
        this.priority = priority;
    }

    @Override
    public boolean matches(Task task) {
        return task.getPriority().equals(priority);
    }
}
