package org.elsys.todo.impl;

import java.util.*;
import java.util.function.Consumer;
import java.util.stream.Collectors;

import org.elsys.todo.Criteria;
import org.elsys.todo.Priority;
import org.elsys.todo.Status;
import org.elsys.todo.Task;
import org.elsys.todo.TodoList;

public class TodoListImpl implements TodoList {

	private List<Task> tasks;

	/**
	 * TODO    | Do OOP homework              | Low    | school, programming
	 * TODO    | Get 8 hours of sleep.        | Low    | health
	 * DOING   | Party hard.                  | Normal | social
	 * DONE    | Netflix and chill.           | Normal | tv shows
	 * TODO    | Find missing socks.          | Low    | meh

	 * @param input
	 */
	public TodoListImpl(String input) {
		tasks = Arrays.stream(input.split("\n")).map(line -> {
			String[] splitted = Arrays.stream(line.split("\\|"))
				.map(String::trim)
				.toArray(String[]::new);
			return new TaskImpl(
					Status.valueOf(splitted[0].toUpperCase()),
					splitted[1],
					Priority.valueOf(splitted[2].toUpperCase()),
					splitted[3].split(", "));
		}).collect(Collectors.toList());
	}

	public TodoListImpl(List<Task> list) {
		tasks = list;
	}

	@Override
	public Boolean isCompleted() {
		return getCompletedTasks().size() > 0;
	}

	@Override
	public Double completedPercentage() {
		return intersectionPercentage(getCompletedTasks());
	}

	@Override
	public Double statusPercentage(Status status) {
		return intersectionPercentage(filter(Criteria.status(status)).getTasks());
	}

	@Override
	public Double matchingPercentage(Criteria criteria) {
		return intersectionPercentage(filter(criteria).getTasks());
	}

	@Override
	public List<Task> getTasks() {
		return tasks;
	}

	@Override
	public TodoList filter(Criteria criteria) {
		return new TodoListImpl(tasks.stream().filter(criteria::matches).collect(Collectors.toList()));
	}

	@Override
	public int count(Criteria criteria) {
		return filter(criteria).getTasks().size();
	}

	@Override
	public void each(Consumer<Task> consumer) {
		tasks.forEach(consumer);
	}
	
	@Override
	public TodoList join(TodoList other) {
		Set<Task> filteredTasks = new HashSet<>(tasks);
		filteredTasks.addAll(other.getTasks());

		return new TodoListImpl(new ArrayList<>(filteredTasks));
	}

	private List<Task> getCompletedTasks() {
		return filter(Criteria.status(Status.DONE)).getTasks();
	}

	private Double intersectionPercentage(List<Task> filteredTasks) {
		return (filteredTasks.size() * 100.00d) / tasks.size();
	}
}
