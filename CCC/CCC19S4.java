import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class S4 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N, K;
		String[] line = br.readLine().split(" ");
		N = Integer.parseInt(line[0]);
		K = Integer.parseInt(line[1]);
		String[] scores = br.readLine().split(" ");
		byte trip;
		int highestScore = -1;
		int[] s = new int[N];
		LinkedList<Integer> q = new LinkedList<Integer>();
		for(int i = 0; i < K; i++) {
			q.add(Integer.parseInt(scores[K]));
		}
		while (!q.isEmpty()) {
			int temp = q.remove();
			if (s[temp] == 0) 
			if (s[temp] > 0)
			for(int i = 0; i < K; i++) {
				if (temp + i < N)
					q.add(Integer.parseInt(scores[N]));
			}
		}
	}

}
