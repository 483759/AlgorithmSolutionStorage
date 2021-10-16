package Java;

import Java.Pizza.PizzaType;

public class MainPizza {
  public static void main(String[] args) throws Exception{
    
    try {
      Pizza pizza = PizzaFactory.getPizza(PizzaType.HamMushroom);
      // Pizza pizza = PizzaFactory.getPizza(PizzaType.Deluxe);
      // Pizza pizza = PizzaFactory.getPizza(PizzaType.SeafoodPizza);
      System.out.println(pizza.getPrice());
    } catch (ClassNotFoundException e) {
      // TODO Auto-generated catch block
      e.printStackTrace();
    }
  }
}