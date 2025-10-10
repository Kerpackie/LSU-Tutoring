package org.example;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        // Creating objects of the subclasses
        Creature smaug = new Dragon("Smaug the Golden", 100, 15, 30);
        Creature gribble = new Goblin("Gribble the Sneaky", 50, 8, 0.3);

        // Using the utility method to start the interaction
        BattleArena.fight(smaug, gribble);
    }
}