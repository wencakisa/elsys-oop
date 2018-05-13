package org.elsys.todo.interfaces;

import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

import org.elsys.todo.impl.TaskImpl;
import org.elsys.todo.impl.TodoListImpl;

public interface TodoList {

	/**
	 * Parses the input String and creates new instance of TodoList.
	 * @param input
	 * @return new instance of TodoList
	 */
	static TodoList parse(String input) {
        List<Task> tasks = Stream.of(input.split("\n"))
                .map(line -> line.split("\\|"))
                .map(line -> Stream.of(line).map(String::trim).collect(Collectors.toList()))
                .map(line -> {
                    Status status = Status.valueOf(line.get(0).toUpperCase());
                    String description = line.get(1);
                    Priority priority = Priority.valueOf(line.get(2).toUpperCase());
                    String[] tags = line.get(3).split(", ");

                    return new TaskImpl(status, description, priority, tags);
                })
                .collect(Collectors.toList());

		return new TodoListImpl(tasks);
	}

	/**
	 * Checks if the TodoList is completed.
	 * @return
	 */
	Boolean isCompleted();

	/**
	 * Percentage of completed tasks.
	 * @return Double, with 2-digits precision.
	 */
	Double percentageCompleted();

	/**
	 * @return all tasks in the to-do list.
	 */
	List<Task> getTasks();

	/**
	 * Returns new to-do list, filtered by the provided criteria.
	 * @param criteria
	 * @return
	 */
	TodoList filter(Criteria criteria);

	/**
	 * Joins two instances of TodoList, removing the duplicating tasks.
	 * @param other
	 * @return
	 */
	TodoList join(TodoList other);
}
