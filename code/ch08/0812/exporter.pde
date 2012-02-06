import SimplePostscript.*;
SimplePostscript ps;

void setup() {
    size(200,200);
    ps=new SimplePostscript(this);</programlisting>

          <para>If this file exists, then we just open it, otherwise this line
          will create the file in the same folder as the application:</para>

          <programlisting format="linespecific" id="I_programlisting3_d1e18211">    ps.open("pattern.ps",0,0, 200,200);
    noLoop();
}

void draw() {
    background(255);
    stroke(0);
    ps.setlinewidth(0.25);</programlisting>

          <para>Now this begins drawing to the file itself:</para>

          <programlisting format="linespecific" id="I_programlisting3_d1e18215">    ps.setgray(0);
    int step=2;
    for(int y=0; y<height; y+=step) {
        beginShape();
        for(int x=0; x<width; x+=step/2) {
            float z=y+calc(x,y);
            vertex(x,z);
            if (x==0) ps.moveto(x,z);
            else ps.lineto(x,z);
        }
        endShape();
        ps.stroke();
    }
    ps.close();
}

float calc(float x,float y) {
    return 10*(sin(x*0.1)*cos((y+x*0.33)*0.1));
}