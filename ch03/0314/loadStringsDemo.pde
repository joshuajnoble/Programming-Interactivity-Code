void setup(){    size(500, 400);    PFont font;    font = loadFont("Ziggurat-HTF-Black-32.vlw");    textFont(font, 32);    String[] lines = loadStrings("list.txt");    print("there are " + lines.length + " lines in your file");    for (int i=0; i < lines.length; i++) {        text(lines[i], 20 + i*30, 50 + i*30);//put each line in a new place    }}

void draw()
{
// nothing here
}

void mousePressed()
{
String[] lines = new String[4];lines[0] = "hello";lines[1] = "out";lines[2] = "there";lines[3] = "!";
saveStrings("data/greeting.txt", lines);
}