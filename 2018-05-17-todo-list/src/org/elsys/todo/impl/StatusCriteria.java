package org.elsys.todo.impl;

import org.elsys.todo.Status;
import org.elsys.todo.Task;

public class StatusCriteria extends AbstractCriteria {

    private Status status;

    public StatusCriteria(Status status) {
        this.status = status;
    }

    @Override
    public boolean matches(Task task) {
        return task.getStatus().equals(status);
    }
}
