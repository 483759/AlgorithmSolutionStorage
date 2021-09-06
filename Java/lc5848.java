package Java;

import java.util.ArrayList;
import java.util.List;

public class lc5848 {
  Node[] node;
  int[] parent;
  ArrayList<Integer>[] child;
  // List<Node> node=new ArrayList<>();
  // List<Integer> parent = new ArrayList<>();
  // List<List<Integer>> child;
  
  public static class Node {
    public boolean locked;
    public int user;
    
    public Node(boolean locked, int user){
      this.locked = locked;
      this.user = user;
    }
  }

  public lc5848(int[] parent) {
    child = new ArrayList[parent.length];

    for(int i=0;i<parent.length;i++){
      this.parent.add(parent[i]);
      if(child.get(parent[i])==null){
        child.get(parent[i])=new ArrayList<>();
      }

      node.add(new Node(false, -1));
    }
  }
  
  public boolean lock(int num, int user) {
    if(node.get(num).locked) {
      return false;
    }

    node.get(num).locked = true;
    node.get(num).user = user;
    return true;
  }
  
  public boolean unlock(int num, int user) {
    if(!node.get(num).locked || node.get(num).user != user){
      return false;
    }

    node.get(num).locked = false;
    return true;
  }
  
  public boolean upgrade(int num, int user) {
    if(node.get(num).locked) {
      return false;
    }

    int cur = num;
    while(parent.get(cur)!=-1){
      if(node.get(cur).locked){
        return false;
      }
      cur=parent.get(cur);
    }

    return true;
  }


  public static void main(String[] args) {
    
  }
}
