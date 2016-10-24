import java.util.*;

class test {

	final static long SECOND = 1000;
	final static long MINUTE = SECOND * 60;
	final static long HOUR = MINUTE * 60;
	final static long DAY = HOUR * 24;
	final static long WEEK = DAY * 7;

	public static void main(String[] args) {
		Calendar cal1 = Calendar.getInstance();
		Date date1 = cal1.getTime();
		System.out.println(date1);

		cal1.add(Calendar.MONTH, -1);
		Date date2 = cal1.getTime();
		System.out.println(date2);

		System.out.println(date1.compareTo(date2));
		System.out.printf("First time: %d, Second time: %d", date1.getTime(), date2.getTime());

		System.out.println();

		long interval = date1.getTime() - date2.getTime();

		System.out.printf("Interval in seconds: %d\n", interval / SECOND);
		System.out.printf("Interval in minutes: %d\n", interval / MINUTE);
		System.out.printf("Interval in hours: %d\n", interval / HOUR);
		System.out.printf("Interval in days: %d\n", interval / DAY);
	}
}
