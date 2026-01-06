package programJava;

// Base class
class Shape {
	void draw() {
		System.out.println("Drawing Shape");
	}
	void erase() {
		System.out.println("Erasing Shape");
	}
}

// Subclass Circle
class Circle extends Shape{
	void draw() {
		System.out.println("Drawing Circle");
	}
	void erase() {
		System.out.println("Erasing Circle");
	}
}

//Subclass Triangle
class Triangle extends Shape{
	void draw() {
		System.out.println("Drawing Triangle");
	}
	void erase() {
		System.out.println("Erasing Triangle");
	}
}

//Subclass Square
class Square extends Shape{
	void draw() {
		System.out.println("Drawing Square");
	}
	void erase() {
		System.out.println("Erasing Square");
	}
}

// Main class to demonstrate polymorphism
public class program5 {
	public static void main(String[] args) {
		// Create shape references pointing to different objects
		Shape s;
		s = new Circle();
		s.draw();
		s.erase();
		s = new Triangle();
		s.draw();
		s.erase();
		s = new Square();
		s.draw();
		s.erase();

	}

}
