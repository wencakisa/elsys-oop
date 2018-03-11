package org.elsys;

import java.util.Scanner;

abstract class Book {
    String title;

    abstract void setTitle(String s);

    String getTitle() {
        return this.title;
    }
}

class MyBook extends Book {
    void setTitle(String s) {
        this.title = s;
    }
}

public class Books {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String title = in.nextLine();

        MyBook new_novel = new MyBook();
        new_novel.setTitle(title);

        System.out.println("The title is: " + new_novel.getTitle());

        in.close();
    }
}
