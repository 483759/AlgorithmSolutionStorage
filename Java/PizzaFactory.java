package Java;

import Java.Pizza.PizzaType;

public class PizzaFactory {
  public static Pizza getPizza (PizzaType pizzaType) throws ClassNotFoundException
  {
    if(pizzaType==PizzaType.HamMushroom)
    {
      return new HamAndMushroomPizza();
    }
    if(pizzaType==PizzaType.Deluxe)
    {
      return new DeluxePizza();
    }
    if(pizzaType==PizzaType.HamMushroom)
    {
      return new SeafoodPizza();
    }
    throw new ClassNotFoundException("The pizza type" + pizzaType.toString() + "is not recognized");
  }
}
