import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    Vector<Integer> v = new Vector<Integer>(n);
    int total_seats = 0;
    for (int i = 0; i < n; i++) {
      int x = in.nextInt();
      v.add(x);
      total_seats += x;
    }
    Vector<Integer> parties = new Vector<Integer>();
    parties.add(1);
    int alice_party = v.get(0);
    for (int i = 1; i < n; i++) {
      if (alice_party <= total_seats / 2 && v.get(0) >= v.get(i) * 2) {
        alice_party += v.get(i);
        parties.add(i + 1);
      }
    }
    if (alice_party > total_seats / 2) {
      System.out.println((int) parties.size());
      for (Integer x : parties) {
        System.out.print(x + " ");
      }
      System.out.println();
    } else {
      System.out.println(0);
    }
  }
}
