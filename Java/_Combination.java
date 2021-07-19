package list;

import java.util.Scanner;

public class _Combination {

    static int n, m;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();

        func(new int[m], 1, 0);

    }

    public static void func(int[] sel, int k, int dep) {
        if (dep == sel.length) {
            for (int i = 0; i < sel.length; i++) {
                System.out.print(sel[i] + " ");
            }
            System.out.println();
            return;
        }

        for (int i = k; i <= n; i++) {
            sel[dep] = i;
            func(sel, i + 1, dep + 1);
        }
    }
}
