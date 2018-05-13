package org.elsys.todo.impl;

import org.elsys.todo.interfaces.Criteria;
import org.elsys.todo.interfaces.Status;
import org.elsys.todo.interfaces.Task;
import org.elsys.todo.interfaces.TodoList;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

public class TodoListImpl implements TodoList {

    private List<Task> tasks;

    public TodoListImpl(List<Task> tasks) {
        this.tasks = tasks;
    }

    @Override
    public Boolean isCompleted() {
        return tasks.stream().allMatch(task -> task.getStatus().equals(Status.DONE));
    }

    @Override
    public Double percentageCompleted() {
        Double completedTasksCount = (double) tasks.stream()
                .filter(task -> task.getStatus().equals(Status.DONE))
                .count();

        return (completedTasksCount / tasks.size()) * 100;
    }

    @Override
    public List<Task> getTasks() {
        return tasks;
    }

    @Override
    public TodoList filter(Criteria criteria) {
        List<Task> filteredTasks = tasks.stream()
                .filter(criteria::matches)
                .collect(Collectors.toList());

        return new TodoListImpl(filteredTasks);
    }

    @Override
    public TodoList join(TodoList other) {
        Set<Task> uniqueTasks = new HashSet<>(tasks);
        uniqueTasks.addAll(other.getTasks());

        return new TodoListImpl(new ArrayList<>(uniqueTasks));
    }
}
