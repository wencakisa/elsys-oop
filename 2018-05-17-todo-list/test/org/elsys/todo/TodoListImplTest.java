package org.elsys.todo;

import org.junit.Test;

import static org.junit.Assert.*;

public class TodoListImplTest {

	private TodoList todoList = TodoList.parse(
			"TODO    | Do OOP homework              | Low    | school, programming\r\n" + 
			"TODO    | Get 8 hours of sleep.        | Low    | health\r\n" + 
			"DOING   | Party hard.                  | Normal | social\r\n" + 
			"DONE    | Netflix and chill.           | Normal | tv shows\r\n" + 
			"TODO    | Find missing socks.          | Low    | meh\r\n" + 
			"");

	@Test
	public void filterByStatus() {
		TodoList filtered = todoList.filter(Criteria.status(Status.DOING));
		assertEquals(1, filtered.getTasks().size());
	}

	@Test
	public void filterByPriority() {
		assertEquals(0, todoList.filter(Criteria.priority(Priority.HIGH))
				.getTasks().size());
		assertEquals(2, todoList.filter(Criteria.priority(Priority.NORMAL))
				.getTasks().size());

	}

	@Test
	public void filterByNotCriteria() {
		assertEquals(5, todoList
				.filter(Criteria.priority(Priority.HIGH).not())
				.getTasks().size());
		assertEquals(3, todoList
				.filter(Criteria.priority(Priority.NORMAL).not())
				.getTasks().size());

	}

	@Test
	public void filterByMixedCriteria() {
		assertEquals(2, todoList
				.filter(Criteria.priority(Priority.LOW).and(Criteria.tags(new String[] { "school" }).not()))
				.getTasks().size());

		assertEquals(5, todoList
				.filter(Criteria.priority(Priority.NORMAL).or(Criteria.status(Status.TODO)))
				.getTasks().size());
	}

	@Test
	public void testMatchingPercentage() {
		assertEquals(new Double(60.00), todoList.matchingPercentage(Criteria.status(Status.TODO)));
		assertEquals(new Double(60.00), todoList.matchingPercentage(Criteria.priority(Priority.LOW)));
		assertEquals(new Double(20.00), todoList.matchingPercentage(Criteria.description("Do OOP homework", true)));
		assertEquals(new Double(20.00), todoList.matchingPercentage(Criteria.description("dO OoP HOMEworK", false)));
		assertEquals(new Double(20.00), todoList.matchingPercentage(Criteria.tags(new String[] { "school" })));
	}

	@Test
	public void testXorCriteria() {
		assertEquals(new Double(60.00),
				todoList.matchingPercentage(Criteria.status(Status.TODO).xor(Criteria.priority(Priority.HIGH))));

		// Not sure if it works correctly
		assertEquals(todoList.matchingPercentage(Criteria.status(Status.TODO).and(Criteria.priority(Priority.LOW).not())),
				todoList.matchingPercentage(Criteria.status(Status.TODO).xor(Criteria.priority(Priority.LOW))));
	}

}
