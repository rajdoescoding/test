import java.awt.*; 
import java.applet.*; 
/*<applet code="FirstApplet" width=400 height=300></applet>*/ 
public class FirstApplet extends Applet {
    public void paint(Graphics g)
    { 
        g.setColor(Color.blue);
        Font font = new Font("Arial", Font.BOLD, 16);
        g.setFont(font); 
        g.drawString("This is My First Applet",60,110); 
    } 
}

