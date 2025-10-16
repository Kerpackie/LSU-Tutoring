## Exercise: Creature Battle Arena

This project involves creating a base `Creature` class and then specializing it into different types, like a `Dragon` and a `Goblin`. Finally, you'll create a `BattleArena` to make them fight\!

### Step 1: Create the Base `Creature` Class

First, let's create the foundation for all our creatures. This class will hold the common attributes and behaviors.

**Instructions:**
Create a Class named `Creature`. It should have the following:

  * **Attributes (Fields/Properties):**
      * `name` (String): The creature's name.
      * `health` (int): Its current health points.
      * `attackPower` (int): How much damage it deals.
  * **Constructor:**
      * A constructor that accepts `name`, `health`, and `attackPower` to initialize the object.
  * **Methods:**
      * `attack(Creature target)`: This method should reduce the `target` creature's health by the `attackPower` of the current creature. Print a message describing the attack (e.g., "Grog the Goblin attacks, dealing 5 damage\!").
      * `takeDamage(int damage)`: Reduces the creature's `health` by the `damage` amount.
      * `isAlive()`: Returns `true` if `health` is greater than 0, otherwise `false`.
      * `display()`: Prints the creature's status (e.g., "Name: Grog, Health: 15/20, Attack: 5"). You might want to add a `maxHealth` attribute to make this display more informative\!

-----

### Step 2: Create Specialized Creatures using Inheritance

Now, let's create some more interesting creatures that **inherit** from `Creature`. They will have their own unique abilities. This is the core of the inheritance lesson.

**Instructions:**

1.  **Create a `Dragon` class:**
      * It should **extend** `Creature`.
      * Add a new attribute: `fireBreathPower` (int).
      * Create a constructor that accepts `name`, `health`, `attackPower`, and `fireBreathPower`. It must call the parent constructor using `super()`.
      * **Override** the `attack(Creature target)` method. A Dragon's attack should be its regular `attackPower` plus a random chance to use fire breath. (There is a Random() method you can use!)
      * Add a new method `breatheFire(Creature target)` that deals `fireBreathPower` damage.


2.  **Create a `Goblin` class:**
      * It should **extend** `Creature`.
      * Add a new attribute: `dodgeChance` (double, e.g., 0.3 for 30%).
      * Create a constructor that calls the parent `super()` constructor.
      * **Override** the `takeDamage(int damage)` method. The Goblin should have a chance to dodge the attack. If it dodges, it takes no damage. Otherwise, it takes damage as normal.


-----

### Step 3: Create a `BattleArena` Utility Class

This class isn't a creature; it's a "manager" or "utility" class. Its job is to control the battle. This teaches the concept of using methods outside the entity classes themselves.

**Instructions:**
Create a `BattleArena` class with a **static** method. Static methods are perfect for utility functions that don't rely on an object's state.

  * **Method:**
      * `public static void fight(Creature c1, Creature c2)`: This method will contain the main battle loop.
          * The loop should continue as long as **both** creatures `isAlive()`.
          * Inside the loop, `c1` attacks `c2`, then `c2` attacks `c1`.
          * After each attack, check if the defending creature is still alive. If not, break the loop.
          * Display the status of both creatures at the end of each round.
          * After the loop ends, declare the winner\! 

-----

### Step 4: Putting It All Together (The `main` Method)

Finally, create a `Main` class to start the program, create creature objects, and begin the fight.

**Instructions:**
Create a class `Main` with a `main` method.

1.  **Create objects:**
      * Instantiate a `Dragon` object.
      * Instantiate a `Goblin` object.
2.  **Start the battle:**
      * Call the static `fight` method from your `BattleArena` class, passing in the two creatures you just created.
  
  <img width="575" height="583" alt="Screenshot 2025-10-09 at 21 40 59" src="https://github.com/user-attachments/assets/a4bdc4af-2378-4f75-b65d-2b9c8573e3fb" />

---

## Step 1 — Full Code & Mini‑Tutorial

### `Creature.java`

```java
package org.example;

public class Creature {
    String name;
    int health;
    int attackPower;

    public Creature(String name, int health, int attackPower) {
        this.name = name;
        this.health = health;
        this.attackPower = attackPower;
    }

    public void attack(Creature target) {
        System.out.println(this.name + " attacks " + target.name + ", dealing " + this.attackPower + " damage!");
        target.takeDamage(this.attackPower);
    }

    public void takeDamage(int damage) {
        this.health -= damage;
    }

    public boolean isAlive() {
        return this.health > 0;
    }

    public void display() {
        System.out.println("Name: " + name + ", Health: " + health + ", Attack: " + attackPower);
    }
}
```


**Mini‑Tutorial: Understanding `Creature`**  
This is the blueprint for all creatures. It keeps shared state like `name`, `health`, and `attackPower`, and exposes common actions.

- **Constructor:** Initializes the creature’s stats so every instance starts with known values.  
- **`attack(Creature target)`:** The basic action — usually calls `target.takeDamage(attackPower)`. Keeping damage application in `takeDamage` lets subclasses customize how damage works without changing callers.  
- **`takeDamage(int damage)`:** Central place to decrease health. Good implementations clamp health at 0 and can print status updates for visibility while learning.  
- **`isAlive()`:** Returns `true` while health > 0; this makes battle loops simple and readable.  
- **`display()`:** A helper for printing a clear, human‑readable status after each round.


---

## Step 2 — Full Code & Mini‑Tutorial (Inheritance)

### `Dragon.java`

```java
package org.example;

import java.util.Random;

public class Dragon extends Creature {
    private int fireBreathPower;

    public Dragon(String name, int health, int attackPower, int fireBreathPower) {
        super(name, health, attackPower); // Calling the parent constructor
        this.fireBreathPower = fireBreathPower;
    }

    // Method Override
    @Override
    public void attack(Creature target) {
        // A 50% chance to breathe fire instead of a normal attack
        if (new Random().nextBoolean()) {
            System.out.println(this.name + " unleashes a torrent of fire!");
            breatheFire(target);
        } else {
            super.attack(target); // Calling the base class's attack method
        }
    }

    public void breatheFire(Creature target) {
        System.out.println(this.name + "'s fire breath deals " + this.fireBreathPower + " damage to " + target.name);
        target.takeDamage(this.fireBreathPower);
    }
}
```


**Mini‑Tutorial: Specializing with `Dragon`**  
`Dragon` **extends** `Creature`, inheriting everything and adding a signature ability — fire breath.

- **Extra Field (e.g., `fireBreathPower`):** New stats that only dragons have.  
- **Override `attack(...)`:** Shows **polymorphism**; dragons may do a normal hit or a stronger fire attack. Even if you store a `Dragon` in a `Creature` variable, the **Dragon’s** `attack` runs at runtime.  
- **`breatheFire(...)`:** Clear, single‑purpose method for the special move — improves readability and reuse.


### `Goblin.java`

```java
package org.example;

public class Goblin extends Creature {
    private double dodgeChance;

    public Goblin(String name, int health, int attackPower, double dodgeChance) {
        super(name, health, attackPower);
        this.dodgeChance = dodgeChance;
    }

    // Method Override
    @Override
    public void takeDamage(int damage) {
        if (Math.random() < this.dodgeChance) {
            System.out.println(this.name + " dodged the attack!");
        } else {
            super.takeDamage(damage); // Let the parent class handle the damage
        }
    }
}
```


**Mini‑Tutorial: Specializing with `Goblin`**  
`Goblin` also **extends** `Creature`, but changes how it **takes** damage by overriding `takeDamage(...)`.

- **`dodgeChance`:** A probability (like `0.3` for 30%) to avoid hits.  
- **Override `takeDamage(...)`:** Calls to `attack(...)` don’t need to change — polymorphism ensures goblins sometimes dodge when damage is applied.  
- **Learning Tip:** Overriding defensive behavior is a clean way to make enemies feel unique without duplicating battle logic.


---

## Step 3 — Full Code & Mini‑Tutorial (Battle Manager)

### `BattleArena.java`

```java
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
```


**Mini‑Tutorial: Orchestrating the Fight**  
`BattleArena` is a **utility** class — not a creature. Its `fight(c1, c2)` method is `static`, so you can call it without creating an arena object.

Typical loop pattern:
1) While **both** creatures `isAlive()`  
2) `c1` attacks `c2` → check if `c2` is alive  
3) `c2` attacks `c1` → check if `c1` is alive  
4) Print a status line after each round

This separation keeps battle rules in one place and leaves creatures focused on their own behavior.


---

## Step 4 — Full Code & Mini‑Tutorial (Entry Point)

### `Main.java`

```java
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
```


**Mini‑Tutorial: Running the Program**  
`Main` holds `public static void main(String[] args)`, which is where Java starts executing.

- **Instantiate** your fighters (e.g., a `Dragon` and a `Goblin`).  
- **Call** `BattleArena.fight(...)` to run the loop until one falls.  
- **Experiment:** Change stats (health, attack, fire power, dodge chance) and run again to see different outcomes.



---

## Appendix — Compile & Run (Quick Reference)

```bash
# Compile all classes in the same folder
javac *.java

# Run the program
java Main
```

> Using packages? Compile from the project root and run with the fully‑qualified name, e.g.:
>
> ```bash
> javac arena/*.java
> java arena.Main
> ```