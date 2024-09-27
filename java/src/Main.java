import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		ArrayList<String> a = new ArrayList<>();

		while(n-- > 0) {
			String s = br.readLine();
			String tmp = "";
			for(int i = 0; i < s.length();i++) {
				char c = s.charAt(i);
				if(c >= '0' ||  c <= '9')
					tmp += c;
				else if(tmp != "") {
					whlie(tmp != "" && tmp.charAt(0) != '0') {
						
					}
				}
			}
		}
		

		}
}}