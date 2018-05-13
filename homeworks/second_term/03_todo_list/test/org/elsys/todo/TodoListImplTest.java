package org.elsys.todo;

import static org.junit.Assert.*;

import org.elsys.todo.interfaces.Criteria;
import org.elsys.todo.interfaces.Priority;
import org.elsys.todo.interfaces.Status;
import org.elsys.todo.interfaces.TodoList;
import org.junit.Test;

public class TodoListImplTest {

	private TodoList todoList = TodoList.parse(
			"TODO    | Do OOP homework              | Low    | school, programming\r\n" +
			"TODO    | Get 8 hours of sleep.        | Low    | health\r\n" +
			"DOING   | Party hard.                  | Normal | social\r\n" + 
			"DONE    | Netflix and chill.           | Normal | tv shows\r\n" + 
			"TODO    | Find missing socks.          | Low    | meh\r\n" +
			"");
	
	private TodoList completedTodoList = TodoList.parse(
			"DONE    | Do OOP homework              | Low    | school, programming\r\n" + 
			"DONE    | Get 8 hours of sleep.        | Low    | health\r\n" + 
			"DONE    | Party hard.                  | Normal | social\r\n" + 
			"DONE    | Netflix and chill.           | Normal | tv shows\r\n" + 
			"DONE    | Find missing socks.          | Low    | meh\r\n" + 
			"");
	
	@Test
	public void testIsCompleted() {
		assertEquals(false, todoList.isCompleted());
		assertEquals(true, completedTodoList.isCompleted());
	}

	@Test
	public void testPercentageCompleted() {
		assertEquals(new Double(100.0), completedTodoList.percentageCompleted());
		assertNotEquals(new Double(100.0), todoList.percentageCompleted());
		assertEquals(new Double(20.0), todoList.percentageCompleted());
	}

	@Test
	public void testGetTasks() {
		assertEquals(5, todoList.getTasks().size());
	}
	
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
	public void testJoin() {
		assertEquals(
				todoList.getTasks().size() + completedTodoList.getTasks().size() - 1,
				todoList.join(completedTodoList).getTasks().size()
		);
		assertEquals(todoList.getTasks().size(), todoList.join(todoList).getTasks().size());
	}
}
