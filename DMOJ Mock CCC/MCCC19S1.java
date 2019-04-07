import java.util.*;

public class MockCCC19S1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long total = 0;
        for (int i = 0; i < n; i++)
            total += sc.nextInt();
        double avg = Math.round(total * 10.0 / n) / 10.0;

        if (avg == 0) System.out.println("0.0");
        else System.out.println(avg);
    }
}
