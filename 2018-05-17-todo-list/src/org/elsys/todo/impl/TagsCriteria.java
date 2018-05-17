package org.elsys.todo.impl;

import org.elsys.todo.Task;

import java.util.Arrays;
import java.util.stream.Stream;

public class TagsCriteria extends AbstractCriteria {

    private String[] tags;

    public TagsCriteria(String[] tags) {
        this.tags = tags;
    }

    @Override
    public boolean matches(Task task) {
        return Stream.of(tags).anyMatch(tag -> Arrays.asList(task.getTags()).contains(tag));
    }
}
