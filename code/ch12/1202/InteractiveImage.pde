class InteractiveImage implements Comparable  {
  
  int _depth;
  PImage img;
  XMLElement xmlData;
  
  public int getX() { return xmlData.getIntAttribute("x"); }
  public int getY() { return xmlData.getIntAttribute("y"); }
  //public int getDepth() { return xmlData.getIntAttribute("depth"); }
  public int getDepth() { return _depth; }
  public int getId() { return xmlData.getIntAttribute("id"); }
  
  
  public void setX(int val) { 
    xmlData.setAttribute("x", str(val)); 
    println(" xml x "+val);
   }
  public void setY(int val) { 
    xmlData.setAttribute("y", str(val)); 
       println(" xml y "+val);
  }
  public void setDepth(int val) { 
    print(" depth "+val);
    _depth = val; 
  }
    
  public int compareTo(Object other)
  {
    int otherDepth = ((InteractiveImage) other).getDepth();
    if(otherDepth > _depth) {
      return -1;
    } else {
      return 1;
    }
    //return getDepth() - otherDepth;    
  }
  
  public void setXMLData(XMLElement s)
  {
    xmlData = s;
    //println(" setXMLData "+xmlData.getAttribute("x")+" "+xmlData.getAttribute("y"));
    println(" setXMLData "+s);
    setX(xmlData.getIntAttribute("x"));
    setY(xmlData.getIntAttribute("y"));
    setDepth(xmlData.getIntAttribute("depth"));
  }
  
  public boolean isClicked(int mx, int my)
  {
    int x = getX();
    int y = getY();
    if(mx > x && mx < x + img.width) {
      if(my > y && my < y + img.height){
         return true;
      }
    }
    return false;
  }
}
