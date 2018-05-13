package org.elsys.todo.interfaces;

public interface Task {

	Status getStatus();

	String getDescription();

	Priority getPriority();

	String[] getTags();
}
