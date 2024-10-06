import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		int ans = s.length();
		String[] a = { "c=", "c-", "d-", "lj", "nj", "s=", "z=" };
		for (int i = 0; i < s.length() - 1; i++) {
			for (int j = 0; j < 7; j++) {
				if (s.substring(i, i + 2).equals(a[j])) {
					ans--;
					break;
				}
			}
			if (i < s.length() - 2) {
				if (s.substring(i, i + 3).equals("dz="))
					ans -= 1;
			}
		}

		System.out.println(ans);
	}
}