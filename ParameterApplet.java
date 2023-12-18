import java.applet.Applet;
import java.awt.Graphics;

//<applet code="ParameterApplet.class" width="300" height="100">//
  //  <param name="greeting" value="Welcome to Applet Programming!">//
public class ParameterApplet extends Applet {

    private String message;

    @Override
    public void init() {
        // Retrieve the parameter named "greeting" from the HTML file
        message = getParameter("greeting");

        // If the parameter is not provided, set a default message
        if (message == null) {
            message = "Hello, World!";
        }
    }

    @Override
    public void paint(Graphics g) {
        // Display the message on the applet window
        g.drawString(message, 20, 20);
    }
}
