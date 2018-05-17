package org.elsys.todo.impl;

import org.elsys.todo.Priority;
import org.elsys.todo.Status;
import org.elsys.todo.Task;

import java.util.Arrays;

public class TaskImpl implements Task {

	private Status status;
	private String description;
	private Priority priority;
	private String[] tags;
	
	public TaskImpl(Status status, String description,
			Priority priority, String[] tags) {
		this.status = status;
		this.description = description;
		this.priority = priority;
		this.tags = tags;
	}

	@Override
	public Status getStatus() {
		return status;
	}

	@Override
	public String getDescription() {
		return description;
	}

	@Override
	public Priority getPriority() {
		return priority;
	}

	@Override
	public String[] getTags() {
		return tags;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;

		TaskImpl task = (TaskImpl) o;

		if (status != task.status) return false;
		if (description != null ? !description.equals(task.description) : task.description != null) return false;
		if (priority != task.priority) return false;
		// Probably incorrect - comparing Object[] arrays with Arrays.equals
		return Arrays.equals(tags, task.tags);
	}

	@Override
	public int hashCode() {
		int result = status != null ? status.hashCode() : 0;
		result = 31 * result + (description != null ? description.hashCode() : 0);
		result = 31 * result + (priority != null ? priority.hashCode() : 0);
		result = 31 * result + Arrays.hashCode(tags);
		return result;
	}
}
