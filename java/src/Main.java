import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] a = new int[4];
		int[] cnt = new int[100];
		int ans = 0;

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 1; i < 4; i++)
			a[i] = Integer.parseInt(st.nextToken());

		for (int i = 0; i < 3; i++) {
			st = new StringTokenizer(br.readLine());
			int s = Integer.parseInt(st.nextToken());
			int e = Integer.parseInt(st.nextToken());
			for (int j = s; j < e; j++)
				cnt[j]++;
		}

		for (int i = 0; i < 100; i++)
			ans += cnt[i] * a[cnt[i]];

		System.out.println(ans);
	}
}