class test_ref {
	public static void main(String[] args) {
		System.out.println("Swapping numbers...");
		
		int a = 3, b = 5;
		System.out.printf("a = %d, b = %d\n", a, b);
		
		System.out.println("Swapping ordinary...");
		swap_ord(a, b);
		System.out.printf("a = %d, b = %d\n", a, b);
		System.out.println("Swapping wrapped...");
		swap_wrap(a, b);
		System.out.printf("a = %d, b = %d\n", a, b);
		Integer i_a = new Integer(a);
		Integer i_b = new Integer(b);
		swap_wrap(i_a, i_b);	
		System.out.printf("a = %d, b = %d\n", i_a, i_b);
		
	}
	
	static void swap_ord(int a, int b) {
		int temp = a;
		a = b;
		b = temp;
	}

	static void swap_wrap(Integer a, Integer b) {
		int temp = a;
		a.valueOf(b);
		b.valueOf(temp);
	}

	
}
