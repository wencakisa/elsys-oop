package org.elsys.todo.impl;

import org.elsys.todo.Task;

public class DescriptionCriteria extends AbstractCriteria {

    private String description;

    private boolean exact;

    public DescriptionCriteria(String description, boolean exact) {
        this.description = description;
        this.exact = exact;
    }

    @Override
    public boolean matches(Task task) {
        if (!exact) {
            return task.getDescription().toLowerCase().contains(description.toLowerCase());
        }

        return task.getDescription().equals(description);
    }
}
