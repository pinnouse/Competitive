import java.io.*;

public class S2 {
	public static boolean isPrime(int num) {
		if (num % 2 == 0 && num != 2) return false;
		for (int i = 3; i <= Math.sqrt(num); i += 2) {
			if (num % i == 0) {
				return false;
			}
		}
		return true;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		int[] N = new int[T];
		for (int i = 0; i < T; i++) {
			N[i] = Integer.parseInt(br.readLine());
		}
		
		for (int i = 0; i < T; i++) {
			int n = (N[i] % 2 == 0) ? N[i] - 1 : N[i];
			for (int j = n; j >= 3; j -= 2) {
				if (!isPrime(j)) continue;
				if (isPrime(N[i] * 2 - j)) {
					System.out.println(j + " " + (N[i] * 2 - j));
					break;
				}
			}
		}
	}

}
