package org.example;

public class BattleArena {
    public static void fight(Creature creature1, Creature creature2) {
        System.out.println("--- BATTLE START ---");
        creature1.display();
        creature2.display();
        System.out.println("--------------------");

        int round = 1;
        while (creature1.isAlive() && creature2.isAlive()) {
            System.out.println("\n--- Round " + round + " ---");

            // Creature 1 attacks Creature 2
            creature1.attack(creature2);
            if (!creature2.isAlive()) break; // Check if the fight is over

            // Creature 2 attacks Creature 1
            creature2.attack(creature1);

            // Display status at the end of the round
            creature1.display();
            creature2.display();
            round++;
        }

        System.out.println("\n--- BATTLE OVER ---");
        if (creature1.isAlive()) {
            System.out.println(creature1.name + " is the winner!");
        } else if (creature2.isAlive()) {
            System.out.println(creature2.name + " is the winner!");
        } else {
            System.out.println("It's a draw!");
        }
    }
}