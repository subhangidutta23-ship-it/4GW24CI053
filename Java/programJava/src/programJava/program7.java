package programJava;

// 1. Interface with correct spelling
interface Resizable {
    void resizeWidth(int width);
    void resizeHeight(int height); // Removed the extra 'd'
}

// 2. Rectangle class implementing BOTH methods
class Rectangle implements Resizable {
    int width;
    int height;

    Rectangle(int w, int h) {
        this.width = w;
        this.height = h;
    }

    void display() {
        System.out.println("Width: " + width + ", Height: " + height);
    }

    // Must be public and match the interface name exactly
    
    public void resizeWidth(int newWidth) {
        this.width = newWidth;
    }

    
    public void resizeHeight(int newHeight) { // Matches interface
        this.height = newHeight;
    }
}

public class program7 {
    public static void main(String[] args) {
        Rectangle rect = new Rectangle(10, 20);
        System.out.println("Original Size:");
        rect.display();

        rect.resizeWidth(30);
        rect.resizeHeight(40);

        System.out.println("Resized Size:");
        rect.display();
    }
}