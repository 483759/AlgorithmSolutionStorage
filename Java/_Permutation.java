package list;

import java.util.Scanner;

public class _Permutation {

    static int n, m;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();

        func(new int[m], 1, 0,new boolean[n]);

    }

    public static void func(int[] sel, int k, int dep,boolean[] check) {
        if (dep == sel.length) {
            for (int i = 0; i < sel.length; i++) {
                System.out.print(sel[i] + " ");
            }
            System.out.println();
            return;
        }

        for (int i = k; i <= n; i++) {
            if(check[i])continue;
            sel[dep] = i;
            check[i]=true;
            func(sel, i + 1, dep + 1,check);
            check[i]=false;
        }
    }
}
