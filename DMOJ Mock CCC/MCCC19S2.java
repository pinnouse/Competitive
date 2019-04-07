import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        //Read counter while populating grid
        int counter = 0;
        int starting = -1;
        int endCol = -1;
        for (int i = 0; i < n; i++) {
            //Get row
            String[] row = br.readLine().split(" ");
            for (int j = 0; j < n; j++) {
                counter ++;
                int nextNum = Integer.parseInt(row[j]);
                if (starting == -1 && counter != nextNum)
                    starting = j;
                else if (starting > -1 && counter == nextNum && endCol == -1) {
                    endCol = j;
                }
            }
            if (starting > -1 && endCol == -1) {
                endCol = n;
                break;
            } else if (endCol > -1) break;
        }
        System.out.println(endCol - starting);
    }
}
