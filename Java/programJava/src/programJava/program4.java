package programJava;

public class program4 {
	// Instance variables 
	private int x;
	private int y;
	// Default constructor (0,0)
	
	public program4() {
		this.x = 0;
		this.y = 0;
	}
	
	// Overloaded constructor with parameters
	public program4 (int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	// Setter method to set both x and y
	public void setXY (int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	// Getter method that returns x and y in an array
	public int[] getXY() {
		return new int[] {x, y};
	}
	
	// toString method
	public String toString() {
		return "("+ x +","+ y +")";
	}
	
	// Method to calculate distance to another point with (x, y)
	public double distance (int x, int y) {
		int dx = this.x - x;
		int dy = this.y - y;
		return Math.sqrt(dx * dx + dy * dy);
	}
	
	// Overloaded distance method to another program4 object
	public double distance (program4 another) {
		int dx = this.x - another.x;
		int dy = this.y - another.y;
		return Math.sqrt(dx * dx + dy * dy);
	}
	
	// Overloaded distance method to the origin (0, 0)
	public double distance () {
		return Math.sqrt(x * x + y * y);
	}
	
	public static void main(String[] args) {
		// Create points
		program4 p1 = new program4(); // Default (0, 0)
		program4 p2 = new program4(3, 4); // (3, 4)
		// Test toString()
		System.out.println("p1 :" +p1); // (0, 0)
		System.out.println("p2 :" +p2); // (3, 4)
		// Test setXY()
		p1.setXY(5,  6);
		System.out.println("After setXY, p1 :" +p1); // (1, 2)
		// Test getXY()
		int[] coords = p1.getXY();
		System.out.println("p1 x :" + coords[0] + ",y :" + coords[1]); 
		// Test distance(x, y)
		double d1 = p1.distance(4, 6);
		System.out.println("Distance from p1 to (4, 6) :" + d1); 
		// Test distance( program4 another)
		double d2 = p1.distance(p2);
		System.out.println("Distance from p1 to p2 :" + d2); 
		// Test distance() to origin
		double d3 = p2.distance();
		System.out.println("Distance from p2 to origin :" + d3); 
	}
}

