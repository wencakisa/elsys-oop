package org.elsys.todo.interfaces;

import org.elsys.todo.impl.PriorityCriteria;
import org.elsys.todo.impl.StatusCriteria;
import org.elsys.todo.impl.TagsCriteria;

/**
 * Interface used for filtering {@link TodoList}s.
 */
public interface Criteria {

	/**
	 * Creates new Criteria instance for matching {@link Task}s with the given
	 * status.
	 * 
	 * @param status
	 * @return the new Criteria instance
	 */
	static Criteria status(Status status) {
		return new StatusCriteria(status);
	}

	/**
	 * Creates new Criteria instance for matching {@link Task}s with the given
	 * priority.
	 * 
	 * @param priority
	 * @return the new Criteria instance
	 */
	static Criteria priority(Priority priority) {
		return new PriorityCriteria(priority);
	}

	/**
	 * Creates new Criteria instance for matching {@link Task}s with the given
	 * tags.
	 * 
	 * @param tags
	 * @return the new Criteria instance
	 */
	static Criteria tags(String[] tags) {
		return new TagsCriteria(tags);
	}

	/**
	 * Creates new Criteria instance representing conjunction with the provided
	 * as argument Criteria.
	 * 
	 * @param other
	 * @return the new Criteria instance
	 */
	Criteria and(Criteria other);

	/**
	 * Creates new Criteria instance representing disjunction with the provided
	 * as argument Criteria.
	 * 
	 * @param other
	 * @return the new Criteria instance
	 */
	Criteria or(Criteria other);

	/**
	 * Creates new Criteria instance representing negation of the Criteria.
	 * 
	 * @param
	 * @return the new Criteria instance
	 */
	Criteria not();

    /**
     * Returns boolean value whether the provided task matches the criteria
     *
     * @param task
     * @return the result of matching as a boolean
     */
	boolean matches(Task task);
}
