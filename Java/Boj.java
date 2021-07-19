package list;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Boj {

    public static class Point {
        int x;
        int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

//        @Override
//        public int compareTo(Point o) {
//            //return o.x-x;
//            return Integer.compare(x,o.x);
//        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Point> list = new ArrayList<>();

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                list.add(new Point(i,j));
            }
        }

        Collections.sort(list, (o1, o2) -> o1.x - o2.x);


        for (Point li: list) {
            System.out.println(li.x+" "+li.y);
        }

    }
}
