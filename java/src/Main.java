import java.util.*;
import java.io.*;

public class Main {
	static int n;
	static char[][] a;

	public static String go(int y, int x, int s) {
		String tmp = "";
		char c = a[y][x];
		for (int i = y; i < y + s; i++) {
			for (int j = x; j < x + s; j++) {
				if (a[y][x] != a[i][j]) {
					tmp += "(";
					tmp += go(y, x, s / 2);
					tmp += go(y, x + s / 2, s / 2);
					tmp += go(y + s / 2, x, s / 2);
					tmp += go(y + s / 2, x + s / 2, s / 2);
					tmp += ")";
					return tmp;
				}
			}
		}
		tmp += a[y][x];
		return tmp;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		a = new char[n][n];
		for (int i = 0; i < n; i++) {
			String s = br.readLine();
			for (int j = 0; j < n; j++)
				a[i][j] = s.charAt(j);
		}

		System.out.println(go(0, 0, n));
	}
}