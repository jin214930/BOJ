import java.util.*;
import java.io.*;

public class Main {
	static int n, c;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());

		HashMap<Integer, Integer> mp = new LinkedHashMap<>();
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			int x = Integer.parseInt(st.nextToken());
			if (mp.containsKey(x))
				mp.put(x, mp.get(x) + 1);
			else
				mp.put(x, 1);
		}

		ArrayList<Integer> a = new ArrayList<>(mp.keySet());

		Collections.sort(a, new Comparator<Integer>() {
			@Override
			public int compare(Integer a, Integer b) {
				return Integer.compare(mp.get(b), mp.get(a));
			}
		});

		Iterator<Integer> it = a.iterator();
		while (it.hasNext()) {
			Integer i = it.next();
			for (int j = 0; j < mp.get(i); j++)
				System.out.print(i + " ");
		}
	}
}