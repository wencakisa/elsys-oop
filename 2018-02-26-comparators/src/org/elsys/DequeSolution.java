package org.elsys;

import java.util.*;

public class DequeSolution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int dequeSize = in.nextInt();
        int subDequeSize = in.nextInt();

        Deque<Integer> deque = new ArrayDeque<>();
        Set<Integer> subset = new HashSet<>();
        List<Integer> maxLengthOfSubsets = new ArrayList<>();

        for (int i = 0; i < dequeSize; i++) {
            int n = in.nextInt();

            deque.add(n);
            subset.add(n);

           if (deque.size() == subDequeSize) {
               maxLengthOfSubsets.add(subset.size());
               int first = deque.poll();

               if (!deque.contains(first)) {
                   subset.remove(first);
               }
           }
        }

        maxLengthOfSubsets.sort(Collections.reverseOrder());
        System.out.println(maxLengthOfSubsets.get(0));
    }
}
