package Java;

import java.io.FileInputStream;
import java.util.Scanner;

public class Boj20304 {

    static int security(int a,int b) {	//두 숫자 사이의 보안척도를 검사하는 메소드
        int cnt=0;		//보안 척도를 저장할 변수

        while(!(a==0&&b==0)) {		//a와 b를 이진화한 뒤 모든 자리수에 대해 비교
            int x=a%2;
            int y=b%2;
            //두 숫자의 맨 끝 자리 계산

            if(x!=y)cnt++;		//이진화한 자리의 숫자가 같다면 cnt를 증가시킴
            a/=2;
            b/=2;		//다음 비교를 위해 두 숫자 모두 right shift
        }

        return cnt;		//계산한 총 보안 척도 값을 반환
    }

    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("res/input.txt"));

        Scanner sc=new Scanner(System.in);
        StringBuilder sb=new StringBuilder();

        int n=sc.nextInt();
        int m=sc.nextInt();
        int ans=0;

        int[] pre=new int[m];		//기존 시도했던 pass들을 저장할 변수
        boolean[][] bin=new boolean[m][21];

        for (int i = 0; i < pre.length; i++) {
            pre[i]=sc.nextInt();
            int k=pre[i];
            int t=bin[i].length-1;
            while(k!=0){
                if(k%2==1)bin[i][t]=true;
                t--;
                k/=2;
            }
        }

        for (int i = 0; i <= n; i++) {
            int min=Integer.MAX_VALUE;		//보안성(기존 시도했던 pass들과 비교해서 가장 낮은 보안 척도)을 저장할 변수
            for (int j = 0; j < pre.length; j++) {
                //System.out.println(security(pre[j],i));
                min=Math.min(min, security(pre[j],i));		//숫자 i와 pass와의 보안 척도를 비교한 뒤, 최소값을 갱신
            }
            ans=Math.max(min, ans);		//가장 높은 보안성을 가진 숫자 i를 갱신
        }
        System.out.println(ans);
    }

}
